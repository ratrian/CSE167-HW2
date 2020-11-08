#version 330 core
// This is a sample fragment shader.

struct  Material {
    uniform vec3 ambient;
    uniform vec3 diffuse;
    uniform vec3 specular;
    uniform float shininess;
};

struct PointLight {
    uniform vec3 lightPos;
    uniform vec3 lightCol;
    uniform vec3 lightAtten;
};

// Inputs to the fragment shader are the outputs of the same name from the vertex shader.
// Note that you do not have access to the vertex shader's default output, gl_Position.
in float sampleExtraOutput;

uniform vec3 color;

// You can output many things. The first vec4 type output determines the color of the fragment
out vec4 fragColor;

void main()
{
    // Use the color passed in. An alpha of 1.0f means it is not transparent.
    fragColor = vec4(color, sampleExtraOutput);
}