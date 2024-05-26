#version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 vertColor;

uniform sampler2D ourTexture;
uniform float opacity;

void main()
{
    vec4 color = texture(ourTexture, TexCoord) + vec4(vertColor, 0) * 0.0;
    FragColor = vec4(color.xyz, opacity);
    // FragColor = vec4(vertColor, 1.0);
}