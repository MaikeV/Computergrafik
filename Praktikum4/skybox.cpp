#include "skybox.h"

SkyBox::SkyBox() {}

void SkyBox::init() {
    initializeOpenGLFunctions ();

    loadCubemap();

    static const GLfloat vertexData[] = {
        -1, 1, -1,
        -1, -1, -1,
        1, -1, -1,
        1, 1, -1,
        -1, -1, 1,
        -1, 1, 1,
        1, -1, 1,
        1, 1, 1,
    };

    static const GLuint indicesData[] = {
        0, 1, 2, 2, 3, 0,
        4, 1, 0, 0, 5, 4,
        2, 6, 7, 7, 3, 2,
        4, 5, 7, 7, 6, 4,
        0, 3, 7, 7, 5, 0,
        1, 4, 2, 2, 4, 6,
    };

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesData), indicesData, GL_STATIC_DRAW);

    glGenBuffers (1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData (GL_ARRAY_BUFFER, sizeof (vertexData), vertexData, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, nullptr);
    glBindVertexArray(0);

    m_prog = new QOpenGLShaderProgram();
    m_prog->addShaderFromSourceFile(QOpenGLShader::Vertex,":/skybox.vert");
    m_prog->addShaderFromSourceFile(QOpenGLShader::Fragment,":/skybox.frag");
    m_prog->link();
    Q_ASSERT(m_prog->isLinked());

    //m_vao.release();
}

void SkyBox::draw(QMatrix4x4 &projection, QMatrix4x4 view) {
    glDepthMask(GL_FALSE);

//    QMatrix4x4 view2;
//    view2.lookAt (QVector3D(0, 0, 0), QVector3D(0, 0, -1), QVector3D(0, 1, 0));

    view.column(3) = QVector4D(0.0f, 0.0f, 0.0f, 0.0f);
    view.scale(10.0f);

    //m_vao.bind();
    glBindVertexArray (m_vao);

    glActiveTexture (GL_TEXTURE2);
    glBindTexture (GL_TEXTURE_CUBE_MAP, m_cubeTex);

    m_prog->bind();

    m_prog->setUniformValue(9, projection);
    m_prog->setUniformValue(7, view);
    m_prog->setUniformValue(6, 0);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    //Release VAO
    //m_vao.release();

    glDepthMask(GL_TRUE);
}

void SkyBox::loadCubemap() {
    glGenTextures (1, &this->m_cubeTex);
    glBindTexture (GL_TEXTURE_CUBE_MAP, this->m_cubeTex);

    right.load(":/skybox/right.jpg");
    left.load(":/skybox/left.jpg");
    top.load(":/skybox/top.jpg");
    bottom.load(":/skybox/bottom.jpg");
    front.load(":/skybox/back.jpg"); //switched
    back.load(":/skybox/front.jpg");

    glTexImage2D (GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, right.width(), right.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(right.constBits ()));
    glTexImage2D (GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, left.width(), left.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(left.constBits ()));
    glTexImage2D (GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, top.width(), top.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(top.constBits ()));
    glTexImage2D (GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, bottom.width(), bottom.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(bottom.constBits ()));
    glTexImage2D (GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, back.width(), back.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(back.constBits ()));
    glTexImage2D (GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, front.width(), front.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, reinterpret_cast<void const*>(front.constBits ()));

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}
