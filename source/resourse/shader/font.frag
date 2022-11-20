#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec2 TexCord;
uniform sampler2D textureVirus;
uniform sampler2D textureCell;
uniform int whichOneInNine;
void main(void)
{
    FragColor = texture(textureVirus,vec2(TexCord.x+float(whichOneInNine%10)/10.0,TexCord.y+float(whichOneInNine/10)/10.0));

    //FragColor = texture(textureVirus,vec2(TexCord.x+whichOneInNine%10/10.0,TexCord.y+whichOneInNine/10/10.0));
    //FragColor = (1,0.1,1);
}
