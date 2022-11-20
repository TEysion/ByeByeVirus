#include "GameScene.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPushButton>
#include <cmath>
#include <thread>
#include "gameobject/ResourceEngine.h"
#include "gameobject/Virus.h"
#include "MainMenuScene.h"
#include "gameconfig/Config.h"

using namespace std;

void GameScene::on_updatePos()
{
    updatePos();
}
void GameScene::on_updatePaint()
{
    update();
}
void GameScene::on_addObject()
{
    //若无关卡数据
    if(stageData==nullptr)return;
    if(allNum==0)return;
    //读取一条关卡信息
    Message msg=stageData->getMessage();
    //若达到此物件出现设定时间
    if(Config::getMills()-gameStartTime>=msg.mills){
        //病毒
        if(msg.type==Message::VIRUS){
            enemy.push_back((Virus*)(msg.pObject));
        }
        //警告
        else if(msg.type==Message::WARN){
            if(msg.tip!=""){
                warning=true;
                warnMediaPlayer.play();
            }else{
                warning=false;
            }
            ui.label->setText(msg.tip);
        }
        //提示
        else if(msg.type==Message::TIP){
            ui.label_4->setText(msg.tip);
        }
        //掉落物资
        else if(msg.type==Message::DROPBUFF){
            materials.push_back((Material*)(msg.pObject));
        }
        //赋予buff
        else if(msg.type==Message::BUFF){
            if(msg.buff==Cell::AttackBuff)player.attackBuff();
            else if(msg.buff==Cell::FriendBuff)player.friendBuff();
            else if(msg.buff==Cell::ShootBuff)player.shootBuff();
            else if(msg.buff==Cell::SpeedBuff)player.speedBuff();
        }
        //若所有物件均已添加完毕
        if(false==stageData->next())addObjTimer.stop();
    }

}

GameScene::GameScene(QWidget* parent) : QOpenGLWidget(parent), indexBuf1x1(QOpenGLBuffer::IndexBuffer),indexBufMirror(QOpenGLBuffer::IndexBuffer),indexBuf3x3(QOpenGLBuffer::IndexBuffer),indexBuf10x10(QOpenGLBuffer::IndexBuffer),indexBufBg(QOpenGLBuffer::IndexBuffer), paintTimer(this) ,updatePosTimer(this), addObjTimer(this){
    setAttribute(Qt::WA_DeleteOnClose);
    int start=Config::getMills();
    initView();
    qDebug()<<"initView "<<Config::getMills()-start;start=Config::getMills();
    initial();
    qDebug()<<"initial "<<Config::getMills()-start;start=Config::getMills();
    initAudio();
    qDebug()<<"initAudio "<<Config::getMills()-start;start=Config::getMills();
    initMultiKeys();
}

GameScene::~GameScene(){
    makeCurrent();
    VAO1x1.release();
    VAO1x1.destroy();
    VAOMirror.release();
    VAOMirror.destroy();
    VAO3x3.release();
    VAO3x3.destroy();
    VAO10x10.release();
    VAO10x10.destroy();
    VAOBg.release();
    VAOBg.destroy();
    doneCurrent();

    delete textureVirus[0];
    delete textureVirus[1];
    delete textureVirus[2];
    delete textureVirus[3];
    delete textureBomb[0];
    delete textureBomb[1];
    delete textureBomb[2];
    delete textureCell;
    delete textureFriend;
    delete textureBullet;
    delete textureFont;
    delete textureBuff;
    delete textureBuffNutshell;
    delete textureBackground;
    delete textureWarn;
}

void GameScene::initializeGL()
{

    unsigned int indices[] = {0,1,2, 1,2,3};

    GLfloat vertices[]{
        //位置             //纹理坐标
        1.0f, 1.0f, 0.0f, 1.0f / 3, 1.0f / 3, // 右上角
        1.0f, -1.0f, 0.0f,1.0f / 3, 0.0f, // 右下角
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f / 3,// 左上角
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f// 左下角
    };

    GLfloat vertices2[]{
        //位置            /纹理坐标
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, // 右上角
        1.0f, -1.0f, 0.0f, 1.0f, 0.0f, // 右下角
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,// 左上角
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f// 左下角
    };

    GLfloat verticesMirror[]{
        //位置            //纹理坐标
        1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // 右上角
        1.0f, -1.0f, 0.0f, 0.0f, 0.0f, // 右下角
        -1.0f, 1.0f, 0.0f, 1.0f, 1.0f,// 左上角
        -1.0f, -1.0f, 0.0f, 1.0f, 0.0f// 左下角
    };

    GLfloat verticesFont[]{
        //位置             //纹理坐标
        1.0f, 1.0f, 0.0f, 1.0f/10, 1.0f/7, // 右上角
        1.0f, -1.0f, 0.0f, 1.0f/10, 0.0f, // 右下角
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f/7,// 左上角
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f// 左下角
    };

    GLfloat verticesBg[]{
        //位置             //纹理坐标
        1.0f, 1.0f, 0.0f, 0.6f, 0.6f, // 右上角
        1.0f, -1.0f, 0.0f, 0.6f, 0.3f, // 右下角
        -1.0f, 1.0f, 0.0f, 0.3f, 0.6f,// 左上角
        -1.0f, -1.0f, 0.0f, 0.3f, 0.3f// 左下角
    };

    qDebug()<<"初始化opengl";

    int start=Config::getMills();

    initializeOpenGLFunctions();//初始化opengl函数指针

    initTexture();

    //编译并连接顶点着色器与片段着色器
    shaderProgram3x3.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/test.vert");
    shaderProgram3x3.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/test.frag");
    shaderProgram3x3.link();
    shaderProgram3x3.bind();

    VAO3x3.create();
    VAO3x3.bind();
    arrayBuf3x3.create();
    indexBuf3x3.create();
    arrayBuf3x3.bind();
    arrayBuf3x3.allocate(vertices, sizeof(vertices));
    shaderProgram3x3.enableAttributeArray(0);
    shaderProgram3x3.setAttributeBuffer(0, GL_FLOAT, 0, 3, 5*sizeof(GLfloat));
    shaderProgram3x3.enableAttributeArray(1);
    shaderProgram3x3.setAttributeBuffer(1, GL_FLOAT, 3*sizeof(GLfloat), 2, 5*sizeof(GLfloat));
    indexBuf3x3.bind();
    indexBuf3x3.allocate(indices, sizeof(indices));

    VAO1x1.create();
    VAO1x1.bind();
    arrayBuf1x1.create();
    indexBuf1x1.create();
    arrayBuf1x1.bind();
    arrayBuf1x1.allocate(vertices2, sizeof(vertices2));
    shaderProgram3x3.enableAttributeArray(0);
    shaderProgram3x3.setAttributeBuffer(0, GL_FLOAT, 0, 3, 5*sizeof(GLfloat));
    shaderProgram3x3.enableAttributeArray(1);
    shaderProgram3x3.setAttributeBuffer(1, GL_FLOAT, 3*sizeof(GLfloat), 2, 5*sizeof(GLfloat));
    indexBuf1x1.bind();
    indexBuf1x1.allocate(indices, sizeof(indices));

    VAOMirror.create();
    VAOMirror.bind();
    arrayBufMirror.create();
    indexBufMirror.create();
    arrayBufMirror.bind();
    arrayBufMirror.allocate(verticesMirror, sizeof(verticesMirror));
    shaderProgram3x3.enableAttributeArray(0);
    shaderProgram3x3.setAttributeBuffer(0, GL_FLOAT, 0, 3, 5*sizeof(GLfloat));
    shaderProgram3x3.enableAttributeArray(1);
    shaderProgram3x3.setAttributeBuffer(1, GL_FLOAT, 3*sizeof(GLfloat), 2, 5*sizeof(GLfloat));
    indexBufMirror.bind();
    indexBufMirror.allocate(indices, sizeof(indices));


    //编译并连接顶点着色器与片段着色器
    shaderProgram10x10.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/font.vert");
    shaderProgram10x10.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/font.frag");
    shaderProgram10x10.link();
    shaderProgram10x10.bind();

    VAO10x10.create();
    VAO10x10.bind();
    arrayBuf10x10.create();
    indexBuf10x10.create();
    arrayBuf10x10.bind();
    arrayBuf10x10.allocate(verticesFont, sizeof(verticesFont));
    shaderProgram10x10.enableAttributeArray(0);
    shaderProgram10x10.setAttributeBuffer(0, GL_FLOAT, 0, 3, 5*sizeof(GLfloat));
    shaderProgram10x10.enableAttributeArray(1);
    shaderProgram10x10.setAttributeBuffer(1, GL_FLOAT, 3*sizeof(GLfloat), 2, 5*sizeof(GLfloat));
    indexBuf10x10.bind();
    indexBuf10x10.allocate(indices, sizeof(indices));


    //编译并连接顶点着色器与片段着色器
    shaderProgramBg.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/bg.vert");
    shaderProgramBg.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/bg.frag");
    shaderProgramBg.link();
    shaderProgramBg.bind();

    VAOBg.create();
    VAOBg.bind();
    arrayBufBg.create();
    indexBufBg.create();
    arrayBufBg.bind();
    arrayBufBg.allocate(verticesBg, sizeof(verticesBg));
    shaderProgramBg.enableAttributeArray(0);
    shaderProgramBg.setAttributeBuffer(0, GL_FLOAT, 0, 3, 5*sizeof(GLfloat));
    shaderProgramBg.enableAttributeArray(1);
    shaderProgramBg.setAttributeBuffer(1, GL_FLOAT, 3*sizeof(GLfloat), 2, 5*sizeof(GLfloat));
    indexBufBg.bind();
    indexBufBg.allocate(indices, sizeof(indices));
//    resize(Config::getW(), Config::getH());

    qDebug()<<"initGL "<<Config::getMills()-start;start=Config::getMills();

}

void GameScene::resizeGL(int w, int h)
{
    int newW=w,newH=h;
    Config::updateWH(newW,newH);
}

void GameScene::paintGL()
{
    Config::fpsCount();

    glClear(GL_COLOR_BUFFER_BIT);

    //开启透明通道
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //绘制背景
    {
        shaderProgramBg.bind();
        VAOBg.bind();
        textureBackground->bind(0);
        static float dx=0;
        static float dy=0;
        dx+=(rand()%9-4)/50000.0;
        dy+=0.0016;
        if(dy>=2)dy=0;
        shaderProgramBg.setUniformValue("dx", dx);
        shaderProgramBg.setUniformValue("dy", dy);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    }

    //抗体子弹
    shaderProgram3x3.bind();
    VAO3x3.bind();
    textureBullet->bind(0);
    for (std::list<Bullet>::iterator it = player.cBullets.begin(); it != player.cBullets.end(); ++it) {
        QMatrix4x4 transMatrix;
        transMatrix.translate( it->getOpenglX(), it->getOpenglY(), 0);
        transMatrix.scale(it->getOpenglW()/2, it->getOpenglH()/2,1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        if(it->getAttack()>=2) shaderProgram3x3.setUniformValue("whichOneInNine", 1);
        else shaderProgram3x3.setUniformValue("whichOneInNine", 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    }

    //保卫细胞
    {
        VAO1x1.bind();
        textureCell->bind(0);
        QMatrix4x4 transMatrix;
        transMatrix.translate(player.getOpenglX(), player.getOpenglY(), 0);
        transMatrix.scale(player.getOpenglR(),player.getOpenglR()/Object::ey,1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        shaderProgram3x3.setUniformValue("whichOneInNine", 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    }

    //朋友细胞
    {
        textureFriend->bind(0);
        if(player.friengAtLeft) VAO1x1.bind();
        else VAOMirror.bind();
        QMatrix4x4 transMatrix;
        transMatrix.translate(player.friendX ,player.friendY, 0);
        transMatrix.scale(player.getOpenglR(),player.getOpenglR()/Object::ey,1);
        transMatrix.rotate(atan((player.friendY-player.getOpenglY())/(player.friendX-player.getOpenglX()))*180/3.14159,0,0,1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        shaderProgram3x3.setUniformValue("whichOneInNine", 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    }


    //绘制病毒
    for (std::list<Virus*>::iterator it = enemy.begin(); it != enemy.end(); ++it) {
        shaderProgram3x3.bind();
        VAO3x3.bind();
        textureVirus[(*it)->getType()]->bind(0);
        QMatrix4x4 transMatrix;
        transMatrix.translate( (*it)->getOpenglX(), (*it)->getOpenglY(), 0);
        transMatrix.scale((*it)->getOpenglR(),(*it)->getOpenglR()/Object::ey,1);
        transMatrix.rotate((*it)->getRotation(), 0, 0, 1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        if((*it)->destroyed){
            textureBomb[(*it)->getColor()%3]->bind(0);
            shaderProgram3x3.setUniformValue("whichOneInNine", (int)(*it)->bombIndex);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
            continue;
        }
        shaderProgram3x3.setUniformValue("whichOneInNine", (*it)->getColor());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        shaderProgram10x10.bind();
        VAO10x10.bind();
        textureFont->bind();
        QMatrix4x4 transMatrix2;
        QMatrix4x4 scaleMatrix2;
        QString bloodStr=QString::number((*it)->getBlood());
        float fontWidth=(*it)->getOpenglR()/2;
        if(bloodStr.length()%2==0){
            transMatrix2.translate( (*it)->getOpenglX()-(bloodStr.length())/2*fontWidth+fontWidth/2, (*it)->getOpenglY(), 0);
        }
        else{
            transMatrix2.translate( (*it)->getOpenglX()-bloodStr.length()/2*fontWidth, (*it)->getOpenglY(), 0);
        }
        scaleMatrix2.scale((*it)->getOpenglR()/4,(*it)->getOpenglR()/Object::ey/4,1);
        for(int i=0;i<bloodStr.length();i++){
            shaderProgram10x10.setUniformValue("theMatricx", transMatrix2*scaleMatrix2);
            shaderProgram10x10.setUniformValue("whichOneInNine", QString(bloodStr[i]).toInt());
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
            transMatrix2.translate(fontWidth , 0 , 0);
        }
    }

    //绘制buff
    shaderProgram3x3.bind();
    VAO3x3.bind();
    for (std::list<Material*>::iterator it = materials.begin(); it != materials.end(); ++it) {
        textureBuff->bind(0);
        QMatrix4x4 transMatrix;
        transMatrix.translate( (*it)->getOpenglX(), (*it)->getOpenglY(), 0);
        transMatrix.scale((*it)->getOpenglR(),(*it)->getOpenglR()/Object::ey,1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        shaderProgram3x3.setUniformValue("whichOneInNine", (*it)->materialType);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        textureBuffNutshell->bind(0);
        transMatrix.rotate((*it)->getRotation(),0,0,1);
        shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
        shaderProgram3x3.setUniformValue("whichOneInNine", 0);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    }

    //警告框
    if(warning){
        VAO1x1.bind();
        textureWarn->bind(0);
        for (int i = 0; i < 1; i++) {
            QMatrix4x4 transMatrix;
            shaderProgram3x3.setUniformValue("theMatricx", transMatrix);
            shaderProgram3x3.setUniformValue("whichOneInNine", 0);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        }
    }

}

void GameScene::initAudio() {
    bgMediaPlayer.setAudioOutput(&bgAudioOutput);//设置音频输出
    bgMediaPlayer.setSource(QUrl("qrc:///music/musics/bg"+QString::number(rand()%3+1)+".wav"));//设置音乐路径
    mediaPlayer2.setAudioOutput(&audioOutput2);//设置音效输出
    mediaPlayer2.setSource(QUrl("qrc:///music/musics/biu.wav"));//设置音效路径
    bombMediaPlayer.setAudioOutput(&bombAudioOutput);//设置音效输出
    bombMediaPlayer.setSource(QUrl("qrc:///music/musics/bomb.wav"));//设置音效路径
    warnMediaPlayer.setAudioOutput(&warnAudioOutput);//设置音效输出
    warnMediaPlayer.setSource(QUrl("qrc:///music/musics/warn.wav"));//设置音效路径
}

void GameScene::initView() {
    ui.setupUi(this);
    layout = ui.verticalLayout;
    layout->setDirection(QBoxLayout::BottomToTop);//设置布局方向
    layout->addStretch();
    buffProgressbar[0]=nullptr;
    buffProgressbar[1]=nullptr;
    buffProgressbar[2]=nullptr;
    buffProgressbar[3]=nullptr;
}

void GameScene::initTexture()
{
    int start=Config::getMills();
    textureVirus[0] =new QOpenGLTexture(ResourceEngine::getRes("nutshell1"));
    textureVirus[1]=new QOpenGLTexture(ResourceEngine::getRes("nutshell2"));
    textureVirus[2]=new QOpenGLTexture(ResourceEngine::getRes("nutshell3"));
    textureVirus[3]=new QOpenGLTexture(ResourceEngine::getRes("nutshell4"));
    textureBomb[0] = new QOpenGLTexture(ResourceEngine::getRes("bomb1"));
    textureBomb[1] = new QOpenGLTexture(ResourceEngine::getRes("bomb2"));
    textureBomb[2] = new QOpenGLTexture(ResourceEngine::getRes("bomb3"));
    textureCell = new QOpenGLTexture(ResourceEngine::getRes("whitecell"));
    textureFriend = new QOpenGLTexture(ResourceEngine::getRes("pinkcell"));
    textureBullet = new QOpenGLTexture(ResourceEngine::getRes("dnabullet"));
    textureFont = new QOpenGLTexture(ResourceEngine::getRes("font"));
    textureBuff = new QOpenGLTexture(ResourceEngine::getRes("buff"));
    textureBuffNutshell = new QOpenGLTexture(ResourceEngine::getRes("buffnutshell"));
    textureBackground=new QOpenGLTexture(ResourceEngine::getRes("bg1"));
    textureWarn=new QOpenGLTexture(ResourceEngine::getRes("warn"));
    qDebug()<<"initTexture "<<Config::getMills()-start;
}

void GameScene::initMultiKeys()
{
    std::vector<int> multiKey0;
    multiKey0.push_back(1);
    multiKey0.push_back(Qt::Key_Up);
    multiKey0.push_back(Qt::Key_Up);
    multiKey0.push_back(Qt::Key_Down);
    multiKey0.push_back(Qt::Key_Down);
    multiKeys.push_back(multiKey0);
    std::vector<int> multiKey1;
    multiKey1.push_back(1);
    multiKey1.push_back(Qt::Key_Left);
    multiKey1.push_back(Qt::Key_Right);
    multiKey1.push_back(Qt::Key_Left);
    multiKey1.push_back(Qt::Key_Right);
    multiKeys.push_back(multiKey1);
    std::vector<int> multiKey2;
    multiKey2.push_back(1);
    multiKey2.push_back(Qt::Key_B);
    multiKey2.push_back(Qt::Key_A);
    multiKey2.push_back(Qt::Key_B);
    multiKey2.push_back(Qt::Key_A);
    multiKeys.push_back(multiKey2);
    std::vector<int> multiKey3;
    multiKey3.push_back(1);
    multiKey3.push_back(Qt::Key_M);
    multiKey3.push_back(Qt::Key_R);
    multiKey3.push_back(Qt::Key_Q);
    multiKey3.push_back(Qt::Key_5);
    multiKey3.push_back(Qt::Key_2);
    multiKey3.push_back(Qt::Key_1);
    multiKeys.push_back(multiKey3);
}

void GameScene::initial()
{
    score = 0;
    beatNum = 0;
    warning = false;
    connect(&updatePosTimer, &QTimer::timeout, this, &GameScene::on_updatePos);
    updatePosTimer.setInterval(12);
    connect(&addObjTimer, &QTimer::timeout, this, &GameScene::on_addObject);
    addObjTimer.setInterval(10);
    connect(&paintTimer, &QTimer::timeout, this, &GameScene::on_updatePaint);
    paintTimer.setInterval(10);
}

void GameScene::setStageData(GStageData* gsdata)
{
    stageData=gsdata;
    allNum = stageData->getAllNum();
}

void GameScene::startGame()
{
    qDebug()<<"开始游戏";
    gameEnd=false;
    score = 0;
    beatNum = 0;
    warning = false;
    gameStartTime=Config::getMills();
    bgMediaPlayer.play();//播放
    updatePosTimer.start();
    paintTimer.start();
    addObjTimer.start();
}

void GameScene::endGame(bool win)
{
    gameEnd=true;
    if(win){
        player.gameWin=true;
        bgMediaPlayer.setSource(QUrl::fromLocalFile("qrc:///music/musics/pass.wav"));
        //若当前通关关卡是已解锁的最后一个关卡，则解锁下一关卡
        if(Config::getPlayerMessage()->getProgress()==stageData->getStage())
            Config::getPlayerMessage()->setProgress(stageData->getStage()+1);
    }else{
        bgMediaPlayer.setSource(QUrl::fromLocalFile("qrc:///music/musics/fail.wav"));
        updatePosTimer.stop();
        paintTimer.stop();
        addObjTimer.stop();
    }

    bgMediaPlayer.play();//播放背景音乐（通关音乐或失败音乐）

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(QMargins(0, 0, 0, 0));
    QLabel* bg=new QLabel;
    bg->setGeometry(0, 0, 500, 700);
    bg->setMargin(0);
    bg->setStyleSheet("QLabel{font:30px;color:white;background-color:rgb(0,0,0);}");

    QGraphicsOpacityEffect* m_pGraphicsOpacityEffect1;
    QPropertyAnimation* m_pOpacityAnimation1;

    m_pGraphicsOpacityEffect1 = new QGraphicsOpacityEffect(bg);
    m_pGraphicsOpacityEffect1->setOpacity(1.0);
    bg->setGraphicsEffect(m_pGraphicsOpacityEffect1);
    layout->addWidget(bg);

    m_pOpacityAnimation1 = new QPropertyAnimation(m_pGraphicsOpacityEffect1, "opacity", this);
    m_pOpacityAnimation1->setDuration(3000);
    m_pOpacityAnimation1->setStartValue(0);
    m_pOpacityAnimation1->setEndValue(1.0);
    m_pOpacityAnimation1->start();

    QTimer::singleShot(2500,this, [=] {
        overTip = new QPushButton();
        if(win){
            overTip->setText("继续前进");
        }
        else{
            overTip->setText("你的付出永垂不朽......");
        }

        updatePosTimer.stop();
        paintTimer.stop();
        addObjTimer.stop();
        connect(overTip,&QPushButton::clicked,this, [=]() {
            (new MainMenuScene())->show();
            close();
        });

        overTip->setGeometry(0, 0, 500, 700);
        overTip->setStyleSheet("QLabel{font:30px;color:white;background-color:rgb(0,0,0);}");
        layout->addWidget(overTip);
        layout->removeWidget(bg);
        QGraphicsOpacityEffect* m_pGraphicsOpacityEffect1;
        QPropertyAnimation* m_pOpacityAnimation1;
        m_pGraphicsOpacityEffect1 = new QGraphicsOpacityEffect(overTip);
        m_pGraphicsOpacityEffect1->setOpacity(1.0);
        overTip->setGraphicsEffect(m_pGraphicsOpacityEffect1);
        m_pOpacityAnimation1 = new QPropertyAnimation(m_pGraphicsOpacityEffect1, "opacity", this);
        m_pOpacityAnimation1->setDuration(1000);
        m_pOpacityAnimation1->setStartValue(0);
        m_pOpacityAnimation1->setEndValue(1.0);
        m_pOpacityAnimation1->start();
        });
}

void GameScene::paintEvent(QPaintEvent* E)
{
    QOpenGLWidget::paintEvent(E);
    QPainter painter(this);
    ui.label_3->setText("fps: " + QString::number(Config::getFps()));//显示帧率
    if(stageData->getStage()==0)ui.label_2->setText("存活时间：" + QString::number((Config::getMills() - gameStartTime)/1000) + "s");//无尽模式
    else ui.label_2->setText("本关进度：" + QString::number(beatNum*100/(allNum==0?1:allNum)));//关卡模式
    if((allNum==0||beatNum*100/allNum==100)&&!gameEnd)endGame(true);//若所有病毒均被打败，获胜游戏
}

void GameScene::keyPressEvent(QKeyEvent* E)
{
    for(std::vector<vector<int>>::iterator it=multiKeys.begin();it!=multiKeys.end();it++){
         if(E->key()==(*it)[(*it)[0]])(*it)[0]++;
         else (*it)[0]=1;
         if(it->size()==(*it)[0]){
             (*it)[0]=1;
             switch(it-multiKeys.begin()){
             case 0:player.speedBuff();break;
             case 1:player.attackBuff();break;
             case 2:player.shootBuff();break;
             case 3:player.friendBuff();break;
             }
         }
    }
    player.keyPressEvent(E);
}

void GameScene::keyReleaseEvent(QKeyEvent *E)
{
    player.keyReleaseEvent(E);
}

void GameScene::mouseMoveEvent(QMouseEvent* E)
{
    if (gameEnd)return;//若游戏结束，禁用鼠标拖动
    player.mouseMoveEvent(E);
}

void GameScene::updatePos()
{
    srand(time(NULL));
    //更新分数
    score += 1;
    //更新buff剩余时间
    updateBuff();
    //遍历我方细胞及其子弹，更新位置
    updateCell();
    //遍历物资，更新物资位置
    updateMaterial();
    //遍历敌方病毒，更新病毒位置
    updateVirus();
}

void GameScene::updateMaterial()
{
    for (list<Material*>::iterator it = materials.begin(); it != materials.end();)
    {
        (*it)->updatePos();//更新物资的位置
        //判断细胞与物资碰撞
        if ((*it)->collide(player))
        {
            QPixmap img;
            img.load((*it)->imgPath);
            buffLastTime[(*it)->materialType]=10000;
            if(buffProgressbar[(*it)->materialType]==nullptr){
                buffProgressbar[(*it)->materialType] = new RProgressBar;
                buffProgressbar[(*it)->materialType]->setMaxProgress(10000);
                buffProgressbar[(*it)->materialType]->setImg(img);
                switch((*it)->materialType){
                case 0:
                    buffProgressbar[(*it)->materialType]->setText("伤害加倍");
                    player.attackBuff();
                    break;
                case 1:
                    buffProgressbar[(*it)->materialType]->setText("并肩作战");
                    player.friendBuff();
                    break;
                case 2:
                    buffProgressbar[(*it)->materialType]->setText("双倍产出");
                    player.shootBuff();
                    break;
                case 3:
                    buffProgressbar[(*it)->materialType]->setText("射速提高");
                    player.speedBuff();
                    break;
                }
                ui.verticalLayout->addWidget(buffProgressbar[(*it)->materialType]);
            }

            if (it == materials.begin())
            {
                materials.erase(it);
                it = materials.begin();
            }
            else
            {
                materials.erase(it--);
                ++it;
            }
        }
        else if ((*it)->getOpenglY() < -1)
        {
            if (it == materials.begin())
            {
                materials.erase(it);
                it = materials.begin();
            }
            else
            {
                materials.erase(it--);
                ++it;
            }
        }
        else ++it;
    }
}

void GameScene::updateVirus()
{
    for (list<Virus*>::iterator it = enemy.begin(); it != enemy.end();)
    {
        (*it)->updatePos();//更新敌人的位置
        //判断敌方与我方是否有碰撞，若碰撞，结束游戏
        if ((*it)->collide(player)&&!(*it)->destroyed){
            endGame(false);
            update();
            return;
        }
        //判断我方子弹与敌方细胞是否有碰撞，若碰撞，敌方细胞生命减少
        for (list<Bullet>::iterator it2 = player.cBullets.begin(); it2 != player.cBullets.end();)
        {
            if (it2->collide(**it))
            {
                (*it)->onAttacked(*it2);
                mediaPlayer2.play();//播放一次射击音效
                //在子弹列表中移除此子弹
                if (it2 == player.cBullets.begin())
                {
                    player.cBullets.erase(it2);
                    it2 = player.cBullets.begin();
                }
                else
                {
                    player.cBullets.erase(it2--);
                    ++it2;
                }
            }
            else ++it2;
        }
        //敌方已死亡但未播放完死亡动画
        if (((*it)->getBlood()) <= 0&&(*it)->destroyed!=true)
        {
            bombMediaPlayer.play();
            (*it)->destroyed=true;
        }
        //敌方已死亡且播放完死亡动画
        if (((*it)->destroyed)&&(*it)->bombIndex==9)
        {
            if (it == enemy.begin())
            {
                delete(*it);
                enemy.erase(it);
                it = enemy.begin();
            }
            else
            {
                delete(*it);
                enemy.erase(it--);
                ++it;
            }
            beatNum++;
        }
        else ++it;
    }

}

void GameScene::updateCell()
{
    //更新己方位置
    player.updatePos();
    player.shoot();//射击
    for (list<Bullet>::iterator it = player.cBullets.begin(); it != player.cBullets.end();)
    {
        it->updatePos();//只是更新子弹位置，没有画子弹
        if (it->getOpenglY() > 1) //如果需要删除子弹
        {
            if (it == player.cBullets.begin()) //如果是头节点
            {
                player.cBullets.erase(it);//删除子弹
                it = player.cBullets.begin();//it是野指针了，所以让其指向当前头节点
            }
            else
            {
                player.cBullets.erase(it--);//如果不是头节点，直接删除
                ++it;
            }
        }
        else ++it;
    }
}

void GameScene::updateBuff()
{
    for(int i=0;i<4;i++){
        if (buffProgressbar[i] != nullptr)buffProgressbar[i]->setProgress(buffLastTime[i]);
        if (buffProgressbar[i] != nullptr && (buffLastTime[i] -= (1000 / Config::getFps())) < 0) {
            delete(buffProgressbar[i]);
            switch(i){
                case 0: player.cancelAttackBuff(); break;
                case 1: player.cancelFriendBuff(); break;
                case 2: player.cancelShootBuff(); break;
                case 3: player.cancelSpeedBuff(); break;
            }
            buffProgressbar[i] = nullptr;
        }
    }
}
