#version 330 core
in vec2 coord;
out vec4 FragColor;

uniform vec2 uCenter;
uniform float uZoom;
uniform int uMaxIter;

void main() {
    vec2 c = uCenter + coord * uZoom;
    vec2 z = vec2(0.0, 0.0);
    int iter;
    for (iter = 0; iter < uMaxIter; ++iter) {
        if (dot(z, z) > 4.0) break;
        z = vec2(z.x * z.x - z.y * z.y + c.x, 2.0 * z.x * z.y + c.y);
    }
    float t = float(iter) / float(uMaxIter);
    FragColor = vec4(t, t * t, t * t * t, 1.0);
}
