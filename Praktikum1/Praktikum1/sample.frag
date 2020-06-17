#version 430 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 1) in vec2 vTextureCoordinates;

//output written to the screen is always location 0
layout (location = 0) out vec4 fragTexture;

//layout (location = 1) uniform sampler2D tex0;
//layout (location = 2) uniform float uPositionModifier;

//m_prog
void main() {

}
