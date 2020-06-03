#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable

// Phong Parameters
layout (location = 0) in vec2 vTexCoord ;
layout (location = 1) in vec3 vNormal ;
layout (location = 2) in vec3 vFragPos ;
//layout (location = 0) in vec3 vColor;
//layout (location = 3) in vec2 vTextureCoordinates;

//output written to the screen is always location 0
layout (location = 0) out vec4 fragColor;

layout (location = 1) uniform sampler2D tex0;
layout (location = 8) uniform vec3 uViewPosition;
layout (location = 9) uniform vec3 uLightPosition;
layout (location = 10) uniform float uKa; // Ambient
layout (location = 11) uniform float uKd; // Diffuse
layout (location = 12) uniform float uKs; // Specular
//layout (location = 13) uniform float uShininess;


vec3 calcPhongLight (vec3 viewDirection , vec3 lightDirection) {
    // Calculate Phong-Illumination here
    float constant =  1.0;
    float linear = 0.7;
    float quadratic = 1.8;
    float distance = distance(vFragPos, uLightPosition);

    vec3 ambient = uKa * vec3(1, 1, 1);
    vec3 diffuse = (uKd * max(dot(lightDirection, vNormal), 0.0)) * vec3(1, 1, 1);
    vec3 reflection = reflect(-lightDirection, vNormal);
    vec3 specular = uKs * max(dot(reflection, viewDirection), 0.0) * vec3(1, 1, 1);
    float fatt = 1.0 / (constant + linear * distance + quadratic * pow(distance, 2));

    return ambient + fatt * vec3(diffuse + specular);
}

void main(void) {
    // ..
    // Calculate viewDirection & lightDirection -> normalize
    vec3 viewDirection = normalize(uViewPosition - vFragPos);
    vec3 lightDirection = normalize(uLightPosition - vFragPos);

    // Calculate Phong-Illumination: vec3 result
    vec3 brightness = calcPhongLight(viewDirection, lightDirection);

    vec4 texel = texture(tex0, vTexCoord);
    fragColor = vec4((texel.rgb * brightness), 1.0);
    //fragTexture = texture(tex0, vTexCoord);
}
