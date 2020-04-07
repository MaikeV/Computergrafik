#include "MyGLWidget.h"

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

void MyGLWidget::setProjectionMode() {

}

void MyGLWidget::setNear(double value) {
    if(this->near != value) {
        this->near = value;
        emit this->nearValueChanged (value);
    }
}

void MyGLWidget::setFar(double value) {
    if(this->far != value) {
        this->far = value;
        emit this->farValueChanged (value);
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
