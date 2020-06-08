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

    //textures and texture objects
    loadTextures();

    //modelloading
    loadModels();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    initMaterials();

    //Fill ls with data...
    setLights();

    //Generate Uniform Buffer Object
    glGenBuffers(1, &uboLights);
    glBindBuffer(GL_UNIFORM_BUFFER, uboLights);
    glBufferData(GL_UNIFORM_BUFFER, NUM_LS * sizeof(LightSource), nullptr, GL_STATIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, uboLights);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

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
    m_progLighting->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/lightShader.vert");
    m_progLighting->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/lightShader.frag");
    m_progLighting->link();
    Q_ASSERT(m_progLighting->isLinked());
}

void MyGLWidget::loadModels() {
    model.initGL(":/gimbal_suspensionNew.obj");
    model2.initGL(":/gimbal_suspensionNew.obj");
    model3.initGL(":/gimbalNew.obj");
    sphere.initGL(":/sphere.obj");
    sun.initGL (":/sphere.obj");
    sunRed.initGL(":/sphere.obj");
    sunGreen.initGL(":/sphere.obj");
    sunBlue.initGL(":/sphere.obj");
    sunViolett.initGL(":/sphere.obj");
    sunYellow.initGL(":/sphere.obj");
}

void MyGLWidget::loadTextures() {
    texImg.load(":/texture.jpg");
    texLava.load(":/TextureLava.jpg");
    texGold.load(":/goldentexture3.jpg");
    texSilver.load(":/silver.jpg");
    texObsidian.load(":/obsidian.jpg");
    texRuby.load(":/ruby.jpg");
    texBronze.load(":/bronze.jpg");
    Q_ASSERT(!texImg.isNull());
    Q_ASSERT(!texLava.isNull());
    Q_ASSERT(!texGold.isNull());
    Q_ASSERT(!texObsidian.isNull());
    Q_ASSERT(!texRuby.isNull());
    Q_ASSERT(!texBronze.isNull());
    Q_ASSERT(!texSilver.isNull());

    m_texIce = initTexture(m_texIce, texImg);
    m_texLava = initTexture(m_texLava, texLava);
    m_texGold = initTexture(m_texGold, texGold);
    m_texObsidian = initTexture(m_texObsidian, texObsidian);
    m_texBronze = initTexture(m_texBronze, texBronze);
    m_texRuby = initTexture(m_texRuby, texRuby);
    m_texSilver = initTexture(m_texSilver, texSilver);
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

void MyGLWidget::setLights() {
    ls[0] = { //blue light
        QVector3D(0.0f, 0.0f, 0.0f), //position
        QVector3D(0.0f, 0.0f, 1.0f), //color
        0.3f, //ambient
        1.0f, //diffuse
        0.5f, //specular
        1.0,  //constant
        0.35, //linaer
        0.44 //quadratic
    };

    ls[1] = { //green light
        QVector3D(0.0f, 0.0f, 0.0f), //position
        QVector3D(0.0f, 1.0f, 0.0f), //color
        0.3f, //ambient
        1.0f, //diffuse
        0.5f, //specular
        1.0,  //constant
        0.35, //linaer
        0.44, //quadratic
    };

    ls[2] = { //red light
        QVector3D(0.0f, 0.0f, 0.0f), //position
        QVector3D(1.0f, 0.0f, 0.0f), //color
        0.3f, //ambient
        1.0f, //diffuse
        0.5f, //specular
        1.0,  //constant
        0.35, //linaer
        0.44, //quadratic
    };

    ls[3] = { //violett light
        QVector3D(0.0f, 0.0f, 0.0f), //position
        QVector3D(0.5f, 0.0f, 1.0f), //color
        0.3f, //ambient
        1.0f, //diffuse
        0.5f, //specular
        1.0,  //constant
        0.35, //linaer
        0.44, //quadratic
    };

    ls[4] = { //yellow light
        QVector3D(0.0f, 0.0f, 0.0f), //position
        QVector3D(1.0f, 1.0f, 0.0f), //color
        0.3f, //ambient
        1.0f, //diffuse
        0.5f, //specular
        1.0,  //constant
        0.35, //linaer
        0.44, //quadratic
    };
}

void MyGLWidget::initMaterials() {
    gold = Material{
            QVector3D(0.24725f, 0.1995f, 0.0745f),
            QVector3D(0.75164f, 0.60648f, 0.22648f),
            QVector3D(0.628281f, 0.555802f, 0.366065f),
            0.4f,
    };

    bronze = Material{
            QVector3D(0.2125f, 0.1275f, 0.054f),
            QVector3D(0.714f, 0.4284f, 0.18144f),
            QVector3D(0.393548f, 0.271906f, 0.166721f),
            0.2f,
    };

    obsidian = Material {
            QVector3D(0.05375f, 0.05f, 0.06625f),
            QVector3D(0.18275f, 0.17f, 0.22525f),
            QVector3D(0.332741f, 0.328634f, 0.346435f),
            0.3f,
    };

    ruby = Material {
            QVector3D(0.1745f, 0.01175f, 0.01175f),
            QVector3D(0.61424f, 0.04136f, 0.04136f),
            QVector3D(0.727811f, 0.626959f, 0.626959f),
            0.6f,
    };

    silver = Material {
            QVector3D(0.19225f, 0.19225f, 0.19225f),
            QVector3D(0.50754f, 0.50754f, 0.50754f),
            QVector3D(0.508273f, 0.508273f, 0.508273f),
            0.4f,
    };
}

void MyGLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(this->isAnimated) {
        a = (timer.elapsed() / 60) % 360;
        b = (timer.elapsed() / 30) % 360;
        c = (timer.elapsed() / 15) % 360;
    } else {
        a = this->rotationA;
        b = this->rotationB;
        c = this->rotationC;
    }

    glBindBuffer(GL_UNIFORM_BUFFER, uboLights);

    cameraDirection.setToIdentity();
    cameraDirection.lookAt(m_CameraPos, cameraTarget, up);

    rstLights();

    glBindBufferBase(GL_UNIFORM_BUFFER, 0, uboLights);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(ls), ls);

    glEnable(GL_DEPTH_TEST);
    scaleTransformRotate();

    skybox.draw(projMat, cameraDirection);

    update();
}

void MyGLWidget::rstLights() {
    m_progLighting->bind();

    //blue light
    modelMat.setToIdentity();
    modelMat.rotate(timer.elapsed() / 15 % 360, rotAxisX);
    modelMat.scale(QVector3D(0.1f, 0.1f, 0.1f));
    modelMat.translate(QVector3D(0.0f, 12.0f, 0.0f));
    ls[0].position = modelMat.column(3).toVector3D();
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, ls[0].color);
    sunBlue.drawElements();

    //green light
    modelMat.setToIdentity();
    modelMat.rotate(timer.elapsed() / 15 % 360, rotAxisX);
    modelMat.rotate(timer.elapsed() / 15 % 360, -rotAxisY);
    modelMat.scale(QVector3D(0.07f, 0.07f, 0.07f));
    modelMat.translate(QVector3D(11.5f, 11.5f, 0.0f));
    ls[1].position = modelMat.column(3).toVector3D();
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, ls[1].color);
    sunGreen.drawElements();

    //red light
    modelMat.setToIdentity();
    modelMat.rotate(timer.elapsed() / 15 % 360, rotAxisZ);
    modelMat.scale(QVector3D(0.09f, 0.09f, 0.09f));
    modelMat.translate(QVector3D(0.0f, 14.0f, 0.0f));
    ls[2].position = modelMat.column(3).toVector3D();
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, ls[2].color);
    sunRed.drawElements();

    //violett light
    modelMat.setToIdentity();
    modelMat.rotate(timer.elapsed() / 15 % 360, -rotAxisX);
    modelMat.rotate(timer.elapsed() / 15 % 360, rotAxisY);
    modelMat.scale(QVector3D(0.09f, 0.09f, 0.09f));
    modelMat.translate(QVector3D(-11.5f, 11.5f, 0.0f));
    ls[3].position = modelMat.column(3).toVector3D();
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, ls[3].color);
    sunViolett.drawElements();

    //yellow light
    modelMat.setToIdentity();
    modelMat.rotate(timer.elapsed() / 15 % 360, rotAxisY);
    modelMat.scale(QVector3D(0.09f, 0.09f, 0.09f));
    modelMat.translate(QVector3D(-14.0f, 0.0f, 0.0f));
    ls[4].position = modelMat.column(3).toVector3D();
    m_progLighting->setUniformValue(14, projMat * cameraDirection * modelMat);
    m_progLighting->setUniformValue(15, ls[4].color);
    sunYellow.drawElements();
}

void MyGLWidget::scaleTransformRotate() {
    m_progColor->bind();

    if(this->cameraCenter) {
        m_CameraPos = QVector3D(0.0f, 0.0f, 0.0f);
        camMod = 1;
    } else {
        camMod = 0;
    }

    cameraDirection.setToIdentity();
    cameraDirection.lookAt(m_CameraPos, cameraTarget, up);

    //outer
    modelMat.setToIdentity();
    modelMat.rotate(a, rotAxisX);
    m_progColor->setUniformValue(0, projMat * cameraDirection * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    m_progColor->setUniformValue(16, gold.ambient);
    m_progColor->setUniformValue(17, gold.diffuse);
    m_progColor->setUniformValue(18, gold.specular);
    m_progColor->setUniformValue(19, gold.shininess);
    drawTexture(m_texGold);
    model.drawElements();

    QMatrix4x4 cameraDirectionMVP = cameraDirection;

    //middle
    modelMat.setToIdentity();
    modelMat.rotate(90, rotAxisZ);
    modelMat.rotate(a, -rotAxisY);
    modelMat.rotate(b, rotAxisX);
    modelMat.scale(QVector3D(0.7f, 0.7f, 0.7f));
    m_progColor->setUniformValue(16, silver.ambient);
    m_progColor->setUniformValue(17, silver.diffuse);
    m_progColor->setUniformValue(18, silver.specular);
    m_progColor->setUniformValue(19, silver.shininess);
    m_progColor->setUniformValue(0, projMat * cameraDirection * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    drawTexture(m_texSilver);
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
    m_progColor->setUniformValue(16, bronze.ambient);
    m_progColor->setUniformValue(17, bronze.diffuse);
    m_progColor->setUniformValue(18, bronze.specular);
    m_progColor->setUniformValue(19, bronze.shininess);
    m_progColor->setUniformValue (0, projMat * cameraDirectionMVP * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    drawTexture(m_texBronze);
    model3.drawElements();

    //sphere
    modelMat.setToIdentity();
    modelMat.scale(QVector3D(0.05f, 0.05f, 0.05f));
    modelMat.rotate(a, rotAxisX);
    modelMat.rotate(b, rotAxisY);
    modelMat.rotate(float(timer.elapsed() / 60) * 5.0f, rotAxisZ);
    modelMat.translate(QVector3D(-16.0f, 0.0f, 0.0f));
    m_progColor->setUniformValue(16, ruby.ambient);
    m_progColor->setUniformValue(17, ruby.diffuse);
    m_progColor->setUniformValue(18, ruby.specular);
    m_progColor->setUniformValue(19, ruby.shininess);
    m_progColor->setUniformValue(0, projMat * cameraDirectionMVP * modelMat);
    m_progColor->setUniformValue(2, modelMat);
    drawTexture(m_texRuby);
    sphere.drawElements();
}

void MyGLWidget::drawTexture(GLuint tex) {
    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_CUBE_MAP, skybox.getCubeTex());

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
    if(message.type() != QOpenGLDebugMessage::OtherType) {
        qDebug()<<message;
    }
}

void MyGLWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_W){
        this->m_CameraPos.setZ (this->m_CameraPos.z() - 0.2f);
        this->cameraTarget.setZ (this->cameraTarget.z() - 0.2f);
    } else if(event->key() == Qt::Key_A) {
        this->m_CameraPos.setX (this->m_CameraPos.x() - 0.2f);
        this->cameraTarget.setX (this->cameraTarget.x() - 0.2f);
    } else if(event->key() == Qt::Key_S) {
        this->m_CameraPos.setZ (this->m_CameraPos.z() + 0.2f);
        this->cameraTarget.setZ (this->cameraTarget.z() + 0.2f);
    } else if(event->key() == Qt::Key_D) {
        this->m_CameraPos.setX (this->m_CameraPos.x() + 0.2f);
        this->cameraTarget.setX (this->cameraTarget.x() + 0.2f);
    } else if(event->key() == Qt::Key_Up) {
        this->m_CameraPos.setY (this->m_CameraPos.y() + 0.2f);
        this->cameraTarget.setY (this->cameraTarget.y() + 0.2f);
    } else if(event->key() == Qt::Key_Down) {
        this->m_CameraPos.setY (this->m_CameraPos.y() - 0.2f);
        this->cameraTarget.setY (this->cameraTarget.y() - 0.2f);
    } else if(event->key() == Qt::Key_Q) {
        this->cameraTarget.setX (this->cameraTarget.x() - 0.2f);
    } else if(event->key() == Qt::Key_E) {
        this->cameraTarget.setX (this->cameraTarget.x() + 0.2f);
    } else if(event->key() == Qt::Key_R) {
        this->cameraTarget.setY (this->cameraTarget.y() + 0.2f);
    } else if(event->key() == Qt::Key_F) {
        this->cameraTarget.setY (this->cameraTarget.y() - 0.2f);
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

    if (!this->cameraCenter) {
        m_CameraPos = QVector3D(0.0f, 0.0f, 2.0f);
    }
}

void MyGLWidget::setIsAnimated (bool value) {
    this->isAnimated = !this->isAnimated;
    timer.restart ();
}
