#include "PlayerMessage.h"

PlayerMessage::PlayerMessage(QString nickname):nickname(nickname)
{

}

QString PlayerMessage::getNickname()
{
    return nickname;
}

void PlayerMessage::setProgress(int progress)
{
    this->progress=progress;
}

int PlayerMessage::getProgress()
{
    return progress;
}

std::ifstream& operator>>(std::ifstream& is,PlayerMessage& pmsg){
    int version;
    std::string temp;
    if(!is)return is;
    is>>temp;
    if(temp!="version")return is;
    is>>version;
    while(is){
        is>>temp;
        if(temp=="nickname"){is>>temp;pmsg.nickname=QString::fromUtf8(temp);}
        else if(temp=="progress"){is>>pmsg.progress;}
    }
    return is;
}

std::ofstream& operator<<(std::ofstream& os,PlayerMessage& pmsg){
    std::string temp;
    if(!os)return os;
    os<<"version"<<" "<<"01"<<std::endl;
    os<<"nickname"<<" "<<pmsg.nickname.toUtf8().data()<<std::endl;
    os<<"progress"<<" "<<pmsg.progress<<std::endl;
    return os;
}
