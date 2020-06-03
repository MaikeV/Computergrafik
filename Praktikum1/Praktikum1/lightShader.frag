// ..
// Phong Parameters
layout (location = 0) in vec2 vTexCoord ;
layout (location = 1) in vec3 vNormal ;
layout (location = 2) in vec3 vFragPos ;

layout (location = 8) uniform vec3 uViewPosition;
layout (location = 9) uniform vec3 uLightPosition;
layout (location = 10) uniform float uKa; // Ambient
layout (location = 11) uniform float uKd; // Diffuse
layout (location = 12) uniform float uKs; // Specular
layout (location = 13) uniform float uShininess;
// ..

vec3 calcPhongLight (vec3 viewDirection , vec3 lightDirection ) {
    // Calculate Phong-Illumination here
    return ( ambient + diffuse + specular);
}

void main () {
    // ..
    // Calculate viewDirection & lightDirection -> normalise
    // Calculate Phong-Illumination: vec3 result

    vec4 texel = texture(<texture>, vTexCoord );
    fragColor = vec4(( texel . rgb * result ), 1.0);
}
