#version 430 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aTexPos;

layout (location = 1) out vec2 vTexPos;

void main() {
    vTexPos = aTexPos;

    gl_Position = vec4(aPosition, 0.0, 1.0);
}
