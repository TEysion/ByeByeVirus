#include <QDateTime>
#include <QDir>
#include <QStandardPaths>
#include <fstream>
#include "gameconfig/Config.h"
#include "gameobject/Object.h"

int Config::fps = 60;
int Config::WIDTH = 500;
int Config::HEIGHT = 700;
PlayerMessage* Config::playerMessage=nullptr;

void Config::fpsCount()
{
	static long long lastTime = 0;
	static int count = 0;
    int interval = 500;
    long long t = Config::getMills();
	++count;
	if (lastTime == 0) {
		lastTime = t;
		count = 0;
	}
	else if (lastTime > 0 && (t - lastTime) > interval) {
        int last=fps;
		fps = count * 1000 / (t - lastTime);
        if(abs(fps-last)<=1)fps=last;
		count = 0;
		lastTime = t;
    }
}

void Config::updateWH(int w, int h)
{
    WIDTH=w;
    HEIGHT=h;
    Object::ey=((float)h)/w;
}

int Config::getW()
{
    return WIDTH;
}

int Config::getH()
{
    return HEIGHT;
}

int Config::getFps()
{
    return fps;
}

float Config::mapping(float v, float startOld, float endOld, float startNew, float endNew)
{
    float result=startNew+(v-startOld)*(endNew-startNew)/(endOld-startOld);
    return result;
}
void Config::setPlayerMessage(PlayerMessage *playerMessage)
{
    if(Config::playerMessage!=nullptr)delete Config::playerMessage;
    Config::playerMessage=playerMessage;
}

PlayerMessage *Config::getPlayerMessage()
{
    return playerMessage;
}

void Config::initPlayerMessage(QString nickname)
{
    qDebug()<<"path="<<(QString(getDataFileDir())+nickname);
    std::ifstream is((QString(getDataFileDir())+"/"+nickname).toLocal8Bit().data(),std::ios::binary);
    PlayerMessage* pmsg=new PlayerMessage("");
    is>>*pmsg;
    setPlayerMessage(pmsg);
    is.close();
}

void Config::savePlayerMessage()
{

    qDebug()<<"nickname="<<playerMessage->getNickname();
    QString path=getDataFileDir()+"/"+playerMessage->getNickname()+".p";
    // 判断文件夹是否存在，不存在则创建
    QDir dir(getDataFileDir());
    qDebug()<<"PATH="<<dir.absolutePath();
    if(!dir.exists()){
        bool ismkdir = dir.mkpath(".");
        if(!ismkdir)
            qDebug() << "Create path fail";
        else
            qDebug() << "Create fullpath success" ;
    }
    else{
        qDebug() << "fullpath exist" ;
    }

    std::ofstream os(path.toLocal8Bit().data(),std::ios::binary);
    if(!os)qDebug()<<"error";
    os<<*playerMessage;
    os.close();
    qDebug()<<"SAVE"<<path;
}

QString Config::getDataFileDir()
{
#ifdef Q_OS_ANDROID
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
#else
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/消灭病毒/";
#endif
}

int Config::getMills()
{
    return QDateTime::currentMSecsSinceEpoch()%1000000000;
}


