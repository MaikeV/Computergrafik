#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

layout (location = 0) out vec3 vColor;

layout (location = 15) uniform vec3 uColor;
layout (location = 14) uniform mat4 uModelViewProjectionMatrix;

void main() {
    vColor = uColor;
    gl_Position = uModelViewProjectionMatrix * vec4(aPosition, 1.0);
}
