#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QString>
#include <QOpenGLFunctions_3_3_Core>

//#include "common.h"

class Model : QOpenGLFunctions_3_3_Core {
public:
    Model();

    void initGL(const QString &filename);
    void drawElements();
    void finiGL();

private:
    QOpenGLBuffer m_vbo;
    QOpenGLBuffer m_ibo;
    QOpenGLVertexArrayObject m_vao;

    unsigned m_iboCount = 0;
};

#endif // MODEL_H
