#version 430 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

layout (location = 1) in vec2 vTexPos;

layout (location = 0) out vec4 fragColor;

layout (location = 90) uniform sampler2D tex0;

void main() {
    vec4 texel = texture(tex0, vTexPos);

    fragColor = vec4(vec3(pow(texel.x, 50)), 1.0);
    //fragColor = vec4(texel);
}
