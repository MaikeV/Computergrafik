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
        {{0.0f, 0.5f},      {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f},     {0.0f, 1.0f, 0.0f}},
        {{-0.5f, -0.5f},    {0.0f, 0.0f, 1.0f}},
    };

    //copy data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    glGenVertexArrays (1, &m_vao);

    //Start recording buffer and attribute metadata
    glBindVertexArray(m_vao);

    #define OFS(s,a) reinterpret_cast<void* const>(offsetof(s,a))

    glEnableVertexAttribArray (0);
    glVertexAttribPointer (0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, position));

    glEnableVertexAttribArray (1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFS(Vertex, color));

    #undef OFS

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //Create texture object
    glGenTextures(1, &m_tex);
    glBindTexture(GL_TEXTURE_2D, m_tex);

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex,":/sample.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment,":/sample.frag");
    m_prog->link();
    Q_ASSERT(m_prog->isLinked());
}

void MyGLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT);

    //bind Resources
    glBindVertexArray(m_vao);
    m_prog->bind();

    //starting at vertex 0, render 3 vertices(=>1 triangle)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //Stop recording
    glBindVertexArray(0);

    qDebug() << rgbToFloat (this->rotationA);
    m_prog->setUniformValue (0, rgbToFloat(this->rotationA));

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
