#include "MyGLWidget.h"
#include <QDebug>
#include <QKeyEvent>



void MyGLWidget::initializeGL() {
    bool success = initializeOpenGLFunctions ();

    Q_ASSERT(success); Q_UNUSED(success);

    debugLogger = new QOpenGLDebugLogger(this); //this is a member variable
    connect(debugLogger, &QOpenGLDebugLogger::messageLogged, this, &MyGLWidget::onMessageLogged);

    if(debugLogger->initialize()) {
        debugLogger->startLogging(QOpenGLDebugLogger::SynchronousLogging);
        debugLogger->enableMessages();
    }

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex,":/sample.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment,":/sample.frag");
    m_prog->link();
    Q_ASSERT(m_prog->isLinked());

    glClearColor (0.2f, 0.2f, 0.2f, 0.1f);

    glGenVertexArrays (1, &m_vao);

   // struct Vertex {
        //x, y, z
        GLfloat vert[] = {
            0.0f, 0.5f,
            0.5f, -0.5f,
            -0.5f, -0.5f
        };
    //};

    //Associate earlier Vertex Buffer with this VAO
    glBindBuffer (GL_ARRAY_BUFFER, m_vbo);

    //create buffer object
    glGenBuffers (1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    //Start recording buffer and attribute metadata
    glBindVertexArray(m_vao);

    //Start recording buffer and attribute metadata
    //glBindVertexArray(m_vao);

    //copy data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

    //Enable and specify vertex attribute 0(2 floats)
    //void* cast is necessary for legacy reasons
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, sizeof(GLfloat[2]), nullptr);

    //Stop recording
    glBindVertexArray(0);
}

void MyGLWidget::paintGL() {
    glClear (GL_COLOR_BUFFER_BIT);

    //erase old pixels
    //glClear(GL_COLOR_BUFFER_BIT);

    //bind Resources
    glBindVertexArray(m_vao);
    m_prog->bind();

    //starting at vertex 0, render 3 vertices(=>1 triangle)
    glDrawArrays(GL_TRIANGLES, 0, 3);

    update();
}

void MyGLWidget::resizeGL(int w, int h) {

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
