#include "MyGLWidget.h"
#include <QDebug>
#include <QKeyEvent>

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
