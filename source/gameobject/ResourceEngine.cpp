#include "ResourceEngine.h"
ResourceEngine::ResourceEngine()
{

}
std::map<QString,QImage> ResourceEngine::imgMap;
void ResourceEngine::initRes()
{
    imgMap.insert(std::pair<QString,QImage>("nutshell1",QImage(":/img/images/nutshell1.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("nutshell2",QImage(":/img/images/nutshell2.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("nutshell3",QImage(":/img/images/nutshell3.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("nutshell4",QImage(":/img/images/nutshell4.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("bomb1",QImage(":/img/images/bomb1.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("bomb2",QImage(":/img/images/bomb2.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("bomb3",QImage(":/img/images/bomb3.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("whitecell",QImage(":/img/images/whitecell.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("pinkcell",QImage(":/img/images/pinkcell.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("dnabullet",QImage(":/img/images/dnabullet.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("font",QImage(":/img/images/font.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("buff",QImage(":/img/images/buff.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("buffnutshell",QImage(":/img/images/buffnutshell.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("bg1",QImage(":/img/images/bg1.png").mirrored()));
    imgMap.insert(std::pair<QString,QImage>("warn",QImage(":/img/images/warn.png").mirrored()));
}

const QImage& ResourceEngine::getRes(QString name)
{
    return imgMap[name];
}
