#version 330 core
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_separate_shader_objects : enable
#define NUM_LS 5

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct PointLight {     //base alignment    alligned offset     total bytes
    vec3 position;      //16                0                   16
    vec3 color;         //16                16                  32
    float ambient;      //4                 32                  36
    float diffuse;      //4                 36                  40
    float specular;     //4                 40                  44
    float constant;     //4                 44                  48
    float linear;       //4                 48                  52
    float quadratic;    //4                 52                  56
};                      //16                                    64

// Phong Parameters
layout (location = 0) in vec2 vTexCoord ;
layout (location = 1) in vec3 vNormal ;
layout (location = 2) in vec3 vFragPos ;

//output written to the screen is always location 0
layout (location = 0) out vec4 fragColor;

layout (location = 1) uniform sampler2D tex0;
layout (location = 7) uniform samplerCube cubeMap;
layout (location = 8) uniform vec3 uViewPosition;
layout (location = 13) uniform float uShininess;

layout (location = 16) uniform Material uMaterial;

layout (std140) uniform lightBlock {
    PointLight lights[NUM_LS];
};

vec3 calcPhongLight (PointLight light, vec3 viewDirection, vec3 lightDirection) {
    // Calculate Phong-Illumination here
    //13, 1.0, 0.35, 0.44

    float distance = distance(vFragPos, light.position);

    vec3 ambient = light.ambient * uMaterial.ambient;
    vec3 diffuse = (light.diffuse * max(dot(lightDirection, vNormal), 0.0)) * uMaterial.diffuse;
    vec3 reflection = reflect(-lightDirection, vNormal);
    vec3 specular = light.specular * pow(max(dot(reflection, viewDirection), 0.0), uMaterial.shininess * 128) * uMaterial.specular;
    //float shininess = uMaterial.shininess * uShininess;
    float fatt = 1.0 / (light.constant + light.linear * distance + light.quadratic * pow(distance, 2));
    return ambient + fatt * diffuse + specular * light.color;
}

void main(void) {
    // ..
    // Calculate viewDirection & lightDirection -> normalize
    vec3 viewDirection = normalize(uViewPosition - vFragPos);

    // Calculate Phong-Illumination: vec3 result
    vec3 result = vec3(0.0f);

    for(int i = 0; i < NUM_LS; i++) {
        vec3 lightDirection = normalize(lights[i].position - vFragPos);
        result += calcPhongLight(lights[i], viewDirection, lightDirection);
    }
    //vec3 brightness = calcPhongLight(viewDirection, lightDirection);
    //vec3 R = reflect(-viewDirection, vNormal);
    vec3 R = refract(-viewDirection, vNormal, 1.0f / 2.42); //diamond

    vec4 texel = texture(cubeMap, R);

    fragColor = vec4((texel.rgb * result), 1.0);
    //fragTexture = texture(tex0, vTexCoord);
}
