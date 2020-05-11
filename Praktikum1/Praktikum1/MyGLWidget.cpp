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

    QImage texImg;
    texImg.load(":/texture.jpg");
    Q_ASSERT(!texImg.isNull());

    //create buffer object
    glGenBuffers (1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    Vertex vert[] = {
        {{-0.25f, 0.5f},     {1.0f, 0.0f, 0.0f},     {0.5f, 1.0f}},  //top
        {{0.25f, -0.5f},     {0.0f, 1.0f, 0.0f},     {1.0f, 0.0f}},  //right
        {{-0.75f, -0.5f},    {0.0f, 0.0f, 1.0f},     {0.0f, 0.0f}},  //left
        {{0.75f, 0.5f},      {0.0f, 0.0f, 0.0f},     {1.0f, 1.0f}},  //triangle2
    };

    //copy data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    glGenVertexArrays (1, &m_vao);

    //Start recording buffer and attribute metadata
    glBindVertexArray(m_vao);

    //construct and fill IBO with data
    GLuint data[] = {2, 1, 0, 1, 0, 3};
    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    #define OFS(s,a) reinterpret_cast<void* const>(offsetof(s,a))

    glEnableVertexAttribArray (0);
    glVertexAttribPointer (0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, position));

    glEnableVertexAttribArray (1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, color));

    glEnableVertexAttribArray (2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, textureCoordinates));

    #undef OFS

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //Create texture object
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

    m_progTexture = new QOpenGLShaderProgram();
    m_progColor = new QOpenGLShaderProgram();
    m_progTexture->addShaderFromSourceFile(QOpenGLShader::Vertex,":/sample.vert");
    m_progTexture->addShaderFromSourceFile(QOpenGLShader::Fragment,":/sample.frag");
    m_progColor->addShaderFromSourceFile(QOpenGLShader::Vertex,":/sample.vert");
    m_progColor->addShaderFromSourceFile(QOpenGLShader::Fragment,":/colorShader.frag");
    m_progTexture->link();
    m_progColor->link();
    Q_ASSERT(m_progTexture->isLinked());
    Q_ASSERT(m_progColor->isLinked());
}

void MyGLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT);

    QVector3D rotAxis(0, 1, 0);
    QMatrix4x4 rotMat;

    m_progColor->bind();

    rotMat.rotate(this->rotationB, rotAxis);

    m_progColor->setUniformValue (0, rgbToFloat(this->rotationA));
    m_progColor->setUniformValue (3, rotMat);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

    glActiveTexture (GL_TEXTURE0);
    glBindTexture (GL_TEXTURE_2D, m_tex);

    m_progTexture->bind();
    m_progTexture->setUniformValue(1, 0);
    m_progTexture->setUniformValue(2, (this->rotationC/10.0f));

    m_progTexture->setUniformValue(3, rotMat);

    void* const offset = reinterpret_cast <void* const>(sizeof(GLuint) * 3);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, offset);

    update();
}

void MyGLWidget::resizeGL(int w, int h) {

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
    qDebug()<<message;
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
    }
}

void MyGLWidget::setAngle(int value) {
    if(this->angle != value) {
        this->angle = value;
        emit this->angleValueChanged (value);
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
    }
}

void MyGLWidget::setFar(double value) {
    if(this->far != value) {
        if((value - this->near) >= 2.0) {
            this->far = value;
        } else {
            emit this->adjustFar (this->near + 2.0);
        }
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
