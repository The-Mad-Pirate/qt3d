#version 120

// TODO: Replace with a uniform block
uniform vec4 lightPosition = vec4(1.0, 1.0, 0.0, 1.0);
uniform vec3 lightIntensity = vec3(1.0, 1.0, 1.0);

// TODO: Replace with a struct
uniform vec3 ka;            // Ambient reflectivity
uniform float shininess;    // Specular shininess factor

uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;

varying vec3 position;
varying vec3 normal;
varying vec2 texCoord;

vec3 adsModel( const in vec3 pos, const in vec3 n )
{
    // Calculate the vector from the light to the fragment
    vec3 s = normalize( vec3( lightPosition ) - pos );

    // Calculate the vector from the fragment to the eye position
    // (origin since this is in "eye" or "camera" space)
    vec3 v = normalize( -pos );

    // Reflect the light beam using the normal at this fragment
    vec3 r = reflect( -s, n );

    // Calculate the diffuse component
    float diffuse = max( dot( s, n ), 0.0 );

    // Calculate the specular component
    float specular = 0.0;
    if ( dot( s, n ) > 0.0 )
        specular = ( shininess / ( 8.0 * 3.14 ) ) * pow( max( dot( r, v ), 0.0 ), shininess );

    // Lookup diffuse and specular factors
    vec3 diffuseColor = texture2D( diffuseTexture, texCoord ).rgb;
    vec3 specularColor = texture2D( specularTexture, texCoord ).rgb;

    // Combine the ambient, diffuse and specular contributions
    return lightIntensity * ( ( ka + diffuse ) * diffuseColor + specular * specularColor );
}

void main()
{
    gl_FragColor = vec4( adsModel( position, normalize( normal ) ), 1.0 );
}