#ifndef SKYBOX_H
#define SKYBOX_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLDebugLogger>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class SkyBox : QOpenGLFunctions_3_3_Core{
private:
    QImage right;
    QImage left;
    QImage top;
    QImage bottom;
    QImage front;
    QImage back;

    QOpenGLShaderProgram *m_prog;

    GLuint m_cubeTex;

    GLuint m_vbo;
    GLuint m_ibo;
    GLuint m_vao;


public:
    GLuint getCubeTex() const {
        return this->m_cubeTex;
    }

    void init();
    void render();
    void draw(QMatrix4x4 &projection, QMatrix4x4 view);
    void loadCubemap();

    SkyBox();

    ~SkyBox() {
        glDeleteTextures (1, & m_cubeTex );
    }
};

#endif // SKYBOX_H
