#include "MyGLWidget.h"
#include <QDebug>
#include <QKeyEvent>

void MyGLWidget::initializeGL() {
    bool success = initializeOpenGLFunctions ();

    Q_ASSERT(success); Q_UNUSED(success);

    printContextInfo();

    debugLogger = new QOpenGLDebugLogger(this); //this is a member variable
    connect(debugLogger, &QOpenGLDebugLogger::messageLogged, this, &MyGLWidget::onMessageLogged);

    if(debugLogger->initialize()) {
        debugLogger->startLogging(QOpenGLDebugLogger::SynchronousLogging);
        debugLogger->enableMessages();
    }

    glClearColor (0.2f, 0.2f, 0.2f, 0.1f);

    //textures
    QImage texImg;
    QImage texLava;
    texImg.load(":/texture.jpg");
    texLava.load(":/TextureLava.jpg");
    Q_ASSERT(!texImg.isNull());
    Q_ASSERT(!texLava.isNull());

    //modelloading
    model.initGL(":/gimbal_suspension.obj");
    model2.initGL(":/gimbal_suspension.obj");
    model3.initGL(":/gimbal.obj");
    sphere.initGL(":/sphere.obj");
    sun.initGL (":/sphere.obj");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //Create texture object
    m_tex = initTexture(m_tex, texImg);
    m_tex2 = initTexture(m_tex2, texLava);

    //culling
    glEnable(GL_CULL_FACE);
    //glCullFace (GL_FRONT);

    updateProjectionMatrix();

    skybox.init();

    timer.start();

    //shader
    m_progColor = new QOpenGLShaderProgram();
    m_progColor->addShaderFromSourceFile(QOpenGLShader::Vertex,":/sample.vert");
    m_progColor->addShaderFromSourceFile(QOpenGLShader::Fragment,":/colorShader.frag");
    m_progColor->link();
    Q_ASSERT(m_progColor->isLinked());

    m_progLighting = new QOpenGLShaderProgram();
    m_progLighting->addShaderFromSourceFile (QOpenGLShader::Vertex, ":/lightShader.vert");
    m_progLighting->addShaderFromSourceFile (QOpenGLShader::Fragment, ":/colorShader.frag");
    m_progLighting->link();
    Q_ASSERT(m_progLighting->isLinked());
}

void MyGLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //depth test
    glEnable(GL_DEPTH_TEST);

    scaleTransformRotate();

    skybox.draw(projMat, cameraDirection);

    update();
}

void MyGLWidget::setLighting() {

    this->ambient = float(this->rotationA) / 180.f;
    this->diffuse = float(this->rotationB) / 180.f;
    this->specular = float(this->rotationC) / 180.f;
    this->shininess = float(this->angle) / 360.f * 100.f;

    m_progColor->setUniformValue(8, m_CameraPos);
    m_progColor->setUniformValue(9, lightPos);
    m_progColor->setUniformValue(10, ambient);
    m_progColor->setUniformValue(11, diffuse);
    m_progColor->setUniformValue(12, specular);
    //m_progColor->setUniformValue(13, shininess);
}

void MyGLWidget::scaleTransformRotate() {
    QVector3D rotAxisY(0, 1, 0);
    QVector3D rotAxisZ(0, 0, 1);
    QVector3D rotAxisX(1, 0, 0);

    int a, b, c;
    int camMod;

    if(this->isAnimated) {
        a = (timer.elapsed() / 60) % 360;
        b = (timer.elapsed() / 30) % 360;
        c = (timer.elapsed() / 15) % 360;
    } else {
        a = this->rotationA;
        b = this->rotationB;
        c = this->rotationC;
    }

    if(this->cameraCenter) {
        m_CameraPos = QVector3D(0.0f, 0.0f, 0.0f);
        camMod = 1;
    } else {
        m_CameraPos = QVector3D(0.0f, 0.0f, 2.0f);
        camMod = 0;
    }

    m_progLighting->bind();

    //sun
    cameraDirection.setToIdentity();
    cameraDirection.lookAt(m_CameraPos, cameraTarget, up);
    modelMat.setToIdentity ();
    modelMat.scale(QVector3D(0.1f, 0.1f, 0.1f));
    modelMat.rotate(timer.elapsed() / 60 % 360, rotAxisY);
    modelMat.translate(12.0f, 0.0f, 0.0f);
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, QVector3D(1.f, 1.f, 1.f));
    lightPos = modelMat.column(0).toVector3D();
    qDebug() << modelMat;
    sun.drawElements();

    m_progColor->bind();

    setLighting();

    //outer
    modelMat.setToIdentity();
    modelMat.rotate(a, rotAxisX);
    m_progColor->setUniformValue(0, projMat * cameraDirection * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    drawTexture(m_tex);
    model.drawElements();

    QMatrix4x4 cameraDirectionMVP = cameraDirection;

    //middle
    modelMat.setToIdentity();
    modelMat.rotate(90, rotAxisZ);
    modelMat.rotate(a, -rotAxisY);
    modelMat.rotate(b, rotAxisX);
    modelMat.scale(QVector3D(0.7f, 0.7f, 0.7f));
    m_progColor->setUniformValue (0, projMat * cameraDirection * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    model2.drawElements();

    //inner
    modelMat.setToIdentity();
    modelMat.rotate(a, rotAxisX);
    modelMat.rotate(b, rotAxisY);
    modelMat.rotate(c, rotAxisX);
    modelMat.scale(QVector3D(0.5f, 0.5f, 0.5f));
    cameraDirection.rotate(a * camMod, rotAxisX);
    cameraDirection.rotate(b * camMod, rotAxisY);
    cameraDirection.rotate(c * camMod, rotAxisX);
    m_progColor->setUniformValue (0, projMat * cameraDirectionMVP * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    model3.drawElements();

    //sphere
    modelMat.setToIdentity();
    modelMat.scale(QVector3D(0.05f, 0.05f, 0.05f));
    modelMat.rotate(a, rotAxisX);
    modelMat.rotate(b, rotAxisY);
    modelMat.rotate(float(timer.elapsed() / 60) * 5.0f, rotAxisZ);
    modelMat.translate(QVector3D(-16.0f, 0.0f, 0.0f));
    m_progColor->setUniformValue(0, projMat * cameraDirectionMVP * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    drawTexture(m_tex2);
    sphere.drawElements();

}

GLuint MyGLWidget::initTexture(GLuint m_tex, QImage texImg) {
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);

    //fill with pixel data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texImg.width(),
                 texImg.height(), 0, GL_BGRA,GL_UNSIGNED_BYTE,
                 texImg.bits());

    //set filtering (interpolation) options
    //without these commands, _sampling will return black_
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //set wrap mode to "clamp to edge"
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //set wrap mode to "repeat"
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    return m_tex;
}

void MyGLWidget::drawTexture(GLuint tex) {
    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, tex);

    m_progColor->setUniformValue(1, 0);
}

void MyGLWidget::updateProjectionMatrix() {
    this->projMat.setToIdentity();
    this->projMat.perspective(float(this->fov), (float(this->width()) / float(this->height())), float(this->near), float(this->far));
}

void MyGLWidget::resizeGL(int w, int h) {
    updateProjectionMatrix();
}

float MyGLWidget::rgbToFloat(int rgb) {
    return rgb/255.0f;
}

void MyGLWidget::printContextInfo() {
    QOpenGLContext *ctx = QOpenGLContext::currentContext();
    Q_ASSERT(ctx);
    typedef char const* (*GLGETSTRINGPTR)(GLenum);
    auto _glGetString = reinterpret_cast<GLGETSTRINGPTR>(ctx->getProcAddress("glGetString"));
    Q_ASSERT(_glGetString);
    qDebug() << "==============================";
    qDebug() << _glGetString(GL_VENDOR);
    qDebug() << _glGetString(GL_RENDERER);
    qDebug() << _glGetString(GL_VERSION);
    qDebug() << _glGetString(GL_SHADING_LANGUAGE_VERSION);
    qDebug() << "==============================";
}

//donotforgettodeclarethisasaslot
void MyGLWidget::onMessageLogged(QOpenGLDebugMessage message) {
    //std::cout << message.message().toStdString() << std::endl;
    //use this if qDebug output is not accessible
    //if(message.type() != QOpenGLDebugMessage::OtherType) {
        qDebug()<<message;
    //}
}

void MyGLWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W){
        this->m_CameraPos.setZ (this->m_CameraPos.z()+ 0.2f);
    } else if(event->key() == Qt::Key_A) {
        this->m_CameraPos.setX (this->m_CameraPos.x() - 0.2f);
    } else if(event->key() == Qt::Key_S) {
        this->m_CameraPos.setZ (this->m_CameraPos.z() - 0.2f);
    } else if(event->key() == Qt::Key_D) {
        this->m_CameraPos.setX (this->m_CameraPos.x() + 0.2f);
    } else {
        QOpenGLWidget::keyPressEvent(event);
    }

    qInfo() << "Camera Position = " << this->m_CameraPos;
}

void MyGLWidget::setFOV(int value) {
    if(this->fov != value) {
        this->fov = value;
        emit this->fovValueChanged(value);

        updateProjectionMatrix();
    }
}

void MyGLWidget::setAngle(int value) {
    if(this->angle != value) {
        this->angle = value;
        emit this->angleValueChanged (value);

        //updateProjectionMatrix();
    }
}

void MyGLWidget::setProjectionMode(bool value) {
    if(value) {
        this->projectionModeIsPerspective = !this->projectionModeIsPerspective;
        emit this->projectionModeValueChanged (this->projectionModeIsPerspective);
        qInfo() << "ProjectionMode is Perspective: " << this->projectionModeIsPerspective;
    }
}

void MyGLWidget::setNear(double value) {
    if(this->near != value) {
        if((value - this->far) <= -2.0) {
            this->near = value;
        } else {
            emit this->adjustNear (this->far - 2.0);
        }

        updateProjectionMatrix();
    }
}

void MyGLWidget::setFar(double value) {
    if(this->far != value) {
        if((value - this->near) >= 2.0) {
            this->far = value;
        } else {
            emit this->adjustFar (this->near + 2.0);
        }

        updateProjectionMatrix();
    }
}

void MyGLWidget::setRotationA(int value) {
    if(this->rotationA != value) {
        this->rotationA = value;
        //qDebug() << this->rotationA;
        emit this->rotationAValueChanged (value);
    }
}

void MyGLWidget::setRotationB(int value) {
    if(this->rotationB != value) {
        this->rotationB = value;
        emit this->rotationBValueChanged (value);
    }
}

void MyGLWidget::setRotationC(int value) {
    if(this->rotationC != value) {
        this->rotationC = value;
        emit this->rotationCValueChanged (value);
    }
}

void MyGLWidget::setCameraToCenter (bool value) {
    this->cameraCenter = !this->cameraCenter;
}

void MyGLWidget::setIsAnimated (bool value) {
    this->isAnimated = !this->isAnimated;
    timer.restart ();
}
