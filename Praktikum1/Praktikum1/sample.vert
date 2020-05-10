#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec3 aColor;

layout(location = 0) out vec3 vColor;


void main() {
    //define vertex position in space.
    //must be 4-dimensional, so supplement Z and W values
    vColor = aColor;

    gl_Position = vec4(aPosition, 0.0, 1.0);
}
