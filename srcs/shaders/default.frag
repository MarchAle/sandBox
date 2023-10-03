#version 330 core
in vec3 fragColor; // Received color from vertex shader
out vec4 FragColor;

void main() {
    FragColor = vec4(fragColor, 1.0);
}