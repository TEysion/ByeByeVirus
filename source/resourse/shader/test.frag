#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCord;
uniform sampler2D textureVirus;
uniform sampler2D textureCell;
uniform int whichOneInNine;
void main(void)
{
    FragColor = texture(textureVirus,vec2(TexCord.x+float(whichOneInNine%3)/3.0,TexCord.y+float(whichOneInNine/3)/3.0));
    //FragColor = texture(textureVirus,TexCord);
    //FragColor = (1,0.2,0.1);
}
