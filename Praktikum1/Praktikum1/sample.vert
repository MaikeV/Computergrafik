#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable
layout (location = 0) in vec3 aPosition ;
layout (location = 1) in vec3 aNormal ;
layout (location = 2) in vec2 aTexCoord ;

layout (location = 0) out vec2 vTexCoord ;
layout (location = 1) out vec3 vNormal ;
layout (location = 2) out vec3 vFragPos ;

layout (location = 0) uniform mat4 uModelViewProjectionMatrix;
layout (location = 2) uniform mat4 uModelMatrix;

void main() {
    vec4 vertHom = vec4(aPosition, 1.0);

    vTexCoord = aTexCoord.st;

    // Normalize and pass on normals
    vNormal = normalize(mat3(transpose(inverse(uModelMatrix))) * aNormal);

    // Calculate and normalize fragment position
    // WorldSpace -> ModelMatrix
    vFragPos = normalize(uModelMatrix * vertHom).xyz;
    //normalize(vFragPos);

    gl_Position = uModelViewProjectionMatrix * vertHom;
}
