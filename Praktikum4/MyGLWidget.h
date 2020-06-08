#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#define NUM_LS 5

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

    int shininess;
    float ambient;
    float diffuse;
    float specular;

    int a, b, c;
    int camMod;

    GLuint m_texIce;
    GLuint m_texLava;
    GLuint m_texGold;
    GLuint m_texObsidian;
    GLuint m_texBronze;
    GLuint m_texRuby;
    GLuint m_texSilver;
    GLuint m_cubeTex;

    QImage texImg;
    QImage texLava;
    QImage texGold;
    QImage texSilver;
    QImage texObsidian;
    QImage texRuby;
    QImage texBronze;

    QVector3D m_CameraPos = QVector3D(0.0f, 0.0f, 2.0f);
    QVector3D cameraTarget = QVector3D(0.0f, 0.0f, 0.0f);
    QVector3D up = QVector3D(0.0f, 1.0f, 0.0f); 
    QVector3D lightPos = QVector3D(0.0f, 0.0f, 0.0f);
    QVector3D rotAxisX = QVector3D(1, 0, 0);
    QVector3D rotAxisY  = QVector3D(0, 1, 0);
    QVector3D rotAxisZ = QVector3D(0, 0, 1);

    QOpenGLShaderProgram *m_progColor;
    QOpenGLShaderProgram *m_progLighting;

    QOpenGLDebugLogger *debugLogger;

    Model model;
    Model model2;
    Model model3;
    Model sphere;
    Model sun;
    Model sunRed;
    Model sunGreen;
    Model sunBlue;
    Model sunViolett;
    Model sunYellow;

    SkyBox skybox;

    QMatrix4x4 projMat;
    QMatrix4x4 mvpMat;
    QMatrix4x4 modelMat;
    QMatrix4x4 cameraDirection;

    QElapsedTimer timer;

    struct LightSource {
        alignas(16) QVector3D position;
        alignas(16) QVector3D color;

        float ka;
        float kd;
        float ks;
        float constant;
        float linear;
        float quadratic;
    };

    LightSource ls[NUM_LS];

    unsigned int uboLights;

    struct Vertex {
        GLfloat position[3];
        GLfloat normal[3];
        GLfloat texCoord[2];
    };

    struct Material {
        QVector3D ambient;
        QVector3D diffuse;
        QVector3D specular;
        float shininess;
    };

    Material gold;
    Material bronze;
    Material obsidian;
    Material ruby;
    Material silver;

    void setLights();
    void loadModels();
    void loadTextures();
    void rstLights();
    void initMaterials();
    void scaleTransformRotate();
    float rgbToFloat(int rgb);
    void printContextInfo();
    GLuint initTexture(GLuint m_texIce, QImage texImage);
    void drawTexture(GLuint tex);
    void updateProjectionMatrix();

public:
    MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
        setFocusPolicy(Qt::StrongFocus);
    }

    ~MyGLWidget() {
        makeCurrent ();
        glDeleteTextures(1, &m_texIce);
        delete m_progColor;
        model.finiGL();
        model2.finiGL();
        model3.finiGL();
        sphere.finiGL();
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
