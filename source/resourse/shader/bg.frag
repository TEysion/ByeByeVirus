#version 330 core
out vec4 FragColor;
in vec2 TexCord;
uniform sampler2D m_texture;
uniform float dx;
uniform float dy;
void main(void)
{
    FragColor = texture(m_texture,vec2(TexCord.x+dx,TexCord.y+dy));
}
