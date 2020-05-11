#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in vec3 vColor;

//output written to the screen is always location 0
layout (location = 0) out vec4 fragColor;

layout (location = 0) uniform float uAlpha;

//m_prog2
void main(void) {
    //write white color to every fragment
    fragColor = vec4(vColor, uAlpha);
}
