#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include<QOpenGLWidget>
#include <QVector3D>

class MyGLWidget : public QOpenGLWidget {
    Q_OBJECT
private:
    int fov = 45;
    int angle = 0;
    bool projectionModeIsPerspective = true;
    double near = 0;
    double far = 2;
    int rotationA = 0;
    int rotationB = 0;
    int rotationC = 0;
    QVector3D m_CameraPos = QVector3D(0, 0, 0);

public:
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
        setFocusPolicy(Qt::StrongFocus);
    }

    int getFOV() const {
        return fov;
    }

    int getAngle() const {
        return angle;
    }

    void keyPressEvent(QKeyEvent*event);

public slots:
    void setFOV(int value);
    void setAngle(int value);
    void setProjectionMode(bool value);
    void setNear(double value);
    void setFar(double value);
    void setRotationA(int value);
    void setRotationB(int value);
    void setRotationC(int value);

signals:
    void adjustNear(double value);
    void adjustFar(double value);
    void fovValueChanged(int value);
    void angleValueChanged(int value);
    void projectionModeValueChanged(bool projectionMode);
    void nearValueChanged(double value);
    void farValueChanged(double value);
    void rotationAValueChanged(int value);
    void rotationBValueChanged(int value);
    void rotationCValueChanged(int value);
};

#endif // MYGLWIDGET_H
