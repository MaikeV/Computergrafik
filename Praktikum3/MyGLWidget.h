#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLDebugLogger>
#include <QElapsedTimer>
#include "modelloader/model.h"
#include "skybox.h"

class MyGLWidget : public QOpenGLWidget, private QOpenGLFunctions_3_3_Core {
    Q_OBJECT
private:
    int fov = 75;
    int angle = 75;
    bool projectionModeIsPerspective = true;
    bool isAnimated = false;
    bool cameraCenter = false;
    double near = 0.1;
    double far = 100;
    int rotationA = 0;
    int rotationB = 0;
    int rotationC = 0;
    GLuint m_tex;
    GLuint m_tex2;
    GLuint m_cubeTex;
    QVector3D m_CameraPos;
    QVector3D cameraTarget = QVector3D(0.0f, 0.0f, 0.0f);
    QVector3D up = QVector3D(0.0f, 1.0f, 0.0f);
    QMatrix4x4 cameraDirection;
    QOpenGLShaderProgram *m_progTexture;
    QOpenGLShaderProgram *m_progColor;
    QOpenGLDebugLogger *debugLogger;
    Model model;
    Model model2;
    Model model3;
    Model sphere;
    SkyBox skybox;
    QMatrix4x4 projMat;
    QMatrix4x4 mvpMat;
    QElapsedTimer timer;

//    struct Vertex {
//        GLfloat position[2];
//        GLfloat color[3];
//        GLfloat textureCoordinates[2];
//    };

    struct Vertex {
        GLfloat position[3];
        GLfloat normal[3];
        GLfloat texCoord[2];
    };

    void scaleTransformRotate();
    float rgbToFloat(int rgb);
    void printContextInfo();
    GLuint initTexture(GLuint m_tex, QImage texImage);
    void drawTexture(GLuint tex);
    void updateProjectionMatrix();

public:
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
        setFocusPolicy(Qt::StrongFocus);
    }

    ~MyGLWidget() {
        makeCurrent ();
        //delete m_progTexture;
//        glDeleteBuffers (1, &m_vbo);
//        glDeleteVertexArrays(1, &m_vao);
        glDeleteTextures(1, &m_tex);
//        glDeleteBuffers(1, &m_ibo);
        delete m_progColor;
        model.finiGL();
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
    void setIsAnimated(bool value);
    void setCameraToCenter(bool value);
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
    void cameraToCenterChanged(bool cameraToCenter);
    void isAnimatedChanged(bool isAnimated);
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
