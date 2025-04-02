#version 410 core

in vec3 fragColor;
in vec3 fragV;
out vec4 color;

void main()
{
    color = vec4(fragColor, 1.0);
}