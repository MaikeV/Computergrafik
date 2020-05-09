#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec2 aPosition;

void main() {
    //define vertex position in space.
    //must be 4-dimensional, so supplement Z and W values
    gl_Position = vec4(aPosition, 0.0, 1.0);
}
