#version 430 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in vec3 vColor;

layout (location = 0) out vec4 fragColor;

layout (location = 15) uniform vec3 uColor;

void main() {
    fragColor = vec4(uColor, 1.0f);
}

