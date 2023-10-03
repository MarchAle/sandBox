#version 330 core
layout(location = 0) in vec2 position;
layout(location = 1) in vec3 color; // Color attribute

out vec3 fragColor; // Output color to fragment shader

void main() {
    gl_Position = vec4(position, 0.0, 1.0);
    fragColor = color; // Pass the color to the fragment shader
}