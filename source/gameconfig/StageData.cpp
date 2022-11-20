#include "StageData.h"
#include "gameobject/Cell.h"
#include "gameobject/Virus.h"
#include "gameobject/VirusDefensive.h"
#include "gameobject/VirusSpike.h"
#include "gameobject/VirusSwell.h"
#include "gameobject/Material.h"
GStageData::GStageData()
{
    void tempStage01(GStageData& gsdata,int which);
    tempStage01(*this,6);
    it=messages.begin();
    setAll();
    at=0;
}

GStageData::GStageData(int stage)
{
    void tempStage01(GStageData& gsdata,int which);
    tempStage01(*this,stage);
    it=messages.begin();
    setAll();
    at=0;
    this->stage=stage;
}

int interval=500;
void tempStage01(GStageData& gsdata,int which){
    switch(which){
    case 0:
        for(int i=1;i<=900;i++){
            int timeControl = 1000 - i*2;
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(interval*i+timeControl,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(interval*i+timeControl,new VirusSwell((rand()%21-10)/10.0,1.1f,10+i+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(interval*i+timeControl,new VirusSpike((rand()%21-10)/10.0,1.1f,10+i+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(interval*i+timeControl,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 4:
                gsdata<<Message(interval*i+timeControl,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }

        for(int i=1;i<=600;i++){
            srand(time(NULL)+i);
            if(rand()%15==0)
                gsdata<<Message(interval*i/2+3000-i,new Material(),Message::DROPBUFF);
        }
        gsdata<<Message(1000,"指挥中心：无尽模式", Message::TIP);
        gsdata<<Message(3000,"", Message::TIP);

        for(int i=0;i<10;i++){
            if(i%2==0){
                Message msg0(900*i+10000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(900*i+10000,"", Message::WARN);
                gsdata<<msg0;
            }
        }

        gsdata.sort();


        break;

    case 01:
        for(int i=1;i<=30;i++){
            srand(time(NULL)+i);
            Virus* v=new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.);
            gsdata<<Message(500*i,v,Message::VIRUS);
        }
        gsdata<<Message(1000,"指挥中心：你好，新出生的保卫细胞", Message::TIP);
        gsdata<<Message(2000,"指挥中心：守护这里是你的使命", Message::TIP);
        gsdata<<Message(3000,"指挥中心：现在，为了这个身体......", Message::TIP);
        gsdata<<Message(4000,"指挥中心：不顾一切地！！！", Message::TIP);
        gsdata<<Message(5000,"指挥中心：前进吧！！！", Message::TIP);
        gsdata<<Message(7000,"", Message::TIP);
        gsdata.sort();
        break;
    case 02:
        for(int i=1;i<=50;i++){
            srand(time(NULL)+i);
            switch(rand()%3){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
            case 2:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了膨胀病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 03:
        for(int i=1;i<=50;i++){
            srand(time(NULL) + i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
            case 3:
                gsdata<<Message(800*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了变速病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 04:
        for(int i=1;i<=40;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(800*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(800*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(800*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(800*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了防御病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 05:
        for(int i=1;i<=10;i++){
            srand(time(NULL)+i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(1000*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(1000*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(1000*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(1000*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(500*i+5000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(500*i+5000,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=40;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(8000+300*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(8000+300*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(8000+300*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(8000+300*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(10000,"指挥中心：病毒越来越多了，\n"
                             "试试升级后的弹药吧", Message::TIP);
        gsdata<<Message(13000,"", Message::TIP);
        gsdata<<Message(12000,Cell::Buff::ShootBuff);
        //gsdata<<Message(12000,Cell::Buff::SpeedBuff);
        gsdata.sort();
        break;
    case 06:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(1000+500*i,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(1000+500*i,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=120;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(300*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(300*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(300*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(300*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(10,"指挥中心：为你提高了弹药杀伤力", Message::TIP);
        gsdata<<Message(2000,"", Message::TIP);
        gsdata<<Message(0,Cell::Buff::ShootBuff);
        gsdata<<Message(0,Cell::Buff::AttackBuff);
        gsdata.sort();
        break;
    case 07:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(1000+500*i,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(1000+500*i,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=250;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(200*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(200*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(200*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(200*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(0,Cell::Buff::ShootBuff);
        gsdata<<Message(0,Cell::Buff::AttackBuff);
        gsdata<<Message(3000,"未知的声音:要顶不住了吗？", Message::TIP);
        gsdata<<Message(4000,"未知的声音:我来帮你！", Message::TIP);
        gsdata<<Message(5000,"", Message::TIP);
        gsdata<<Message(5000,Cell::Buff::FriendBuff);
        gsdata.sort();
        break;
    case 8:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(500*i+10000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(500*i+10000,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=120;i++){
            srand(time(NULL)+i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(500*i,new VirusSpike((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        for(int i=1;i<=300;i++){
            srand(time(NULL)+i*i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(500*i,new VirusSpike((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(3000,"???:要顶不住了吗？", Message::TIP);
        gsdata<<Message(4000,"???:我来帮你！", Message::TIP);
        gsdata<<Message(5000,"", Message::TIP);
        gsdata<<Message(6000,Cell::Buff::FriendBuff);
        gsdata.sort();
        break;
    }

}



bool GStageData::operator>>(Message &msg)
{
    if(it!=messages.end()){
        msg=*it;
        it++;
        at++;
        return true;
    }
    else{
        return false;
    }
}

void GStageData::operator<<(const Message &msg)
{
    messages.push_back(msg);
    all=messages.size();
}

Message &GStageData::getMessage()
{
    return *it;
}

bool GStageData::next()
{
    if((++it)!=messages.end()){
        return true;
    }
    else{
        it=messages.begin();
        return false;
    }
}

int GStageData::getAllNum()
{
    return all;
}

void GStageData::sort()
{
    messages.sort([=](Message m1,Message m2){
        return m1.mills<m2.mills;
    });
}

void GStageData::setAll()
{
    all=0;
    for(std::list<Message>::iterator it=messages.begin();it!=messages.end();it++)
        if(it->type==Message::VIRUS)
            ++all;
}

int GStageData::getStage()
{
    return stage;
}

Message::Message(int mills, Object* pObject,MessageType type):mills(mills),pObject(pObject),type(type)
{
}

Message::Message(int mills, QString tip, MessageType type):mills(mills),tip(tip),type(type)
{
}

Message::Message(int mills, int buff):mills(mills),buff(buff),type(BUFF)
{
}


