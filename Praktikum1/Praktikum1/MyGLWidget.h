#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include<QOpenGLWidget>

class MyGLWidget : public QOpenGLWidget {
    Q_OBJECT
private:
    int fov;
    int angle;
    int projectionMode;
    double near;
    double far;
    int rotationA;
    int rotationB;
    int rotationC;

public:
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {

    }

    int getFOV() const {
        return fov;
    }

    int getAngle() const {
        return angle;
    }
public slots:
    void setFOV(int value);
    void setAngle(int value);
    void setProjectionMode();
    void setNear(double value);
    void setFar(double value);
    void setRotationA(int value);
    void setRotationB(int value);
    void setRotationC(int value);

signals:
    void fovValueChanged(int value);
    void angleValueChanged(int value);
    void projectionModeValueChanged();
    void nearValueChanged(double value);
    void farValueChanged(double value);
    void rotationAValueChanged(int value);
    void rotationBValueChanged(int value);
    void rotationCValueChanged(int value);
};

#endif // MYGLWIDGET_H
