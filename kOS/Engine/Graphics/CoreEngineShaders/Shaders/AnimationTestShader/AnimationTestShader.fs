#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;
layout (location = 3) out vec3 gReflect;
layout (location = 4) out vec3 gMaterial;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;
in vec3 ReflectDir;
in mat3 tangentToWorld;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_ao1;
uniform sampler2D texture_roughness1;
struct Material 
{
    float reflectivity;
};
uniform Material material;

void main()
{    
    // store the fragment position vector in the first gbuffer texture
    gPosition = FragPos;
    // also store the per-fragment normals into the gbuffer
    gNormal = (texture2D(texture_normal1, TexCoords).rgb * 2.0 - 1.0) * tangentToWorld;
    // and the diffuse per-fragment color
    gAlbedoSpec.rgb = texture(texture_diffuse1, TexCoords).rgb;
    // store specular intensity in gAlbedoSpec's alpha component
    gAlbedoSpec.a = texture(texture_specular1, TexCoords).r;
    gReflect=ReflectDir;
    gMaterial.r=texture(texture_ao1, TexCoords).g;
    gMaterial.g=texture(texture_roughness1, TexCoords).r;
    gMaterial.b=material.reflectivity;

}