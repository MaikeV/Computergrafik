#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLDebugLogger>

class MyGLWidget : public QOpenGLWidget, private  QOpenGLFunctions_3_3_Core{
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
    GLuint m_vao;
    GLuint m_vbo;
    QVector3D m_CameraPos = QVector3D(0, 0, 0);
    QOpenGLShaderProgram *m_prog;
    QOpenGLDebugLogger *debugLogger;

public:
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
        setFocusPolicy(Qt::StrongFocus);
    }

    ~MyGLWidget() {
        makeCurrent ();
        delete m_prog;
        glDeleteBuffers (1, &m_vbo);
        glDeleteVertexArrays(1,&m_vao);
    }

    int getFOV() const {
        return fov;
    }

    int getAngle() const {
        return angle;
    }

    void keyPressEvent(QKeyEvent*event) override;

    //set up any required OpenGL resources
    //called once before the first call to paint and resize
    //Initialisieren
    void initializeGL() override;

    //called whenever the widget needs to be painted
    //Rendering der aktuellen Szene
    void paintGL() override;

    //called whenever the widget has been resized
    //Reinitialisieren
    void resizeGL(int w, int h) override;


public slots:
    void setFOV(int value);
    void setAngle(int value);
    void setProjectionMode(bool value);
    void setNear(double value);
    void setFar(double value);
    void setRotationA(int value);
    void setRotationB(int value);
    void setRotationC(int value);
    void onMessageLogged(QOpenGLDebugMessage message);

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
