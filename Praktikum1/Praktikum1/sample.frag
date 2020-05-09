#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

//output written to the screen is always location 0
layout (location=0) out vec4 fragColor;

void main() {
    //write white color to every fragment
    fragColor = vec4(1.0,1.0,1.0,1.0);
}
