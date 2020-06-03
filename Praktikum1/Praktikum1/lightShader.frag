#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in vec3 vColor;

layout (location = 0) out vec4 color;

void main() {
    color = vec4(vColor, 1.0);
}

