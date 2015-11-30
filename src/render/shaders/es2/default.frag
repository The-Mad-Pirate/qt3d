#define FP highp

uniform FP vec3 ka;            // Ambient reflectivity
uniform FP vec3 kd;            // Diffuse reflectivity
uniform FP vec3 ks;            // Specular reflectivity
uniform FP float shininess;    // Specular shininess factor

uniform FP vec3 eyePosition;

varying FP vec3 position;
varying FP vec3 normal;

#pragma include light.inc.frag

void main()
{
    FP vec3 diffuseColor, specularColor;
    calculateLightColors(position, normal, eyePosition, shininess, diffuseColor, specularColor);
    gl_FragColor = vec4( ka + kd * diffuseColor + ks * specularColor, 1.0 );
}
