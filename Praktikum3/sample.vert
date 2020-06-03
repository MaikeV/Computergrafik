#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTextureCoordinates;

layout(location = 0) out vec3 vColor;
layout(location = 1) out vec2 vTextureCoordinates;

layout(location = 5) uniform mat4 MVP;

void main() {
    //define vertex position in space.
    //must be 4-dimensional, so supplement Z and W values
    vColor = aColor;
    vTextureCoordinates = aTextureCoordinates;

    vec4 pos = vec4(aPosition, 1.0);

    gl_Position = MVP * pos;
}
