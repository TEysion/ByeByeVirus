#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLExtraFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QSoundEffect>
#include <QPushButton>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <vector>
#include "gameconfig/StageData.h"
#include "gameobject/Virus.h"
#include "gameobject/Cell.h"
#include "gameobject/Material.h"
#include "gamewidget/RProgressBar.h"
#include "ui_gamescene.h"

class GameScene : public QOpenGLWidget, QOpenGLExtraFunctions
{
    Q_OBJECT

public slots:
    void on_updatePos();
    void on_updatePaint();
    void on_addObject();
    void endGame(bool win);//游戏结束
    void updatePos();//更新位置，被定时器间接调用
public:
    explicit GameScene(QWidget* parent = 0);
    ~GameScene();
    QPushButton* overTip;//结束提示
    Cell player;//玩家对象
    QMediaPlayer bgMediaPlayer;//背景音乐播放器，用于播放游戏音乐及胜利或死亡音乐
    QAudioOutput bgAudioOutput; //背景音乐音频输出
    QMediaPlayer mediaPlayer2;//音效播放器
    QAudioOutput audioOutput2; //音效播放器输出
    QMediaPlayer bombMediaPlayer;//音效播放器3
    QAudioOutput bombAudioOutput; //音效播放器输出3
    QMediaPlayer warnMediaPlayer;//警告音效播放器
    QAudioOutput warnAudioOutput; //警告音效播放器输出
    std::list<Virus*> enemy;//敌人
    std::list<Material*> materials;//掉落buff或debuff
    void initial();//初始化
    void initAudio();//初始化音频
    void initView();//初始化界面
    void initTexture();//初始化纹理
    void initMultiKeys();//初始化混合键
    void setStageData(GStageData* gadata);//设置关卡数据
    void startGame();//开始游戏
    void paintEvent(QPaintEvent* E);//系统虚函数，继承qwidget的，进行绘制界面
    void keyPressEvent(QKeyEvent* E);//系统虚函数，当按下某个建，系统自动调用
    void keyReleaseEvent(QKeyEvent* E);//系统虚函数，当按下某个建，系统自动调用
    void mouseMoveEvent(QMouseEvent* E);//鼠标事件系统自动调用 
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    void updateMaterial();
    void updateVirus();
    void updateCell();
    void updateBuff();
private:
    static bool textureHasInited;
    QOpenGLTexture* textureVirus[6];
    QOpenGLTexture* textureBomb[6];
    QOpenGLTexture* textureWarn;
    QOpenGLTexture* textureCell;
    QOpenGLTexture* textureFriend;
    QOpenGLTexture* textureBullet;
    QOpenGLTexture* textureFont;
    QOpenGLTexture* textureBuff;
    QOpenGLTexture* textureBuffNutshell;
    QOpenGLTexture* textureBackground;
    QOpenGLVertexArrayObject VAO1x1,VAOMirror,VAO3x3,VAO10x10,VAOBg;
    QOpenGLBuffer arrayBuf1x1,indexBuf1x1;
    QOpenGLBuffer arrayBufMirror,indexBufMirror;
    QOpenGLBuffer arrayBuf3x3,indexBuf3x3;
    QOpenGLBuffer arrayBuf10x10,indexBuf10x10;
    QOpenGLBuffer arrayBufBg,indexBufBg;
    QOpenGLShaderProgram shaderProgram3x3,shaderProgram10x10,shaderProgramBg;
    QVBoxLayout* layout;
    int gameStartTime;
    int beatNum;
    int allNum;
    int score;
    int buffLastTime[4];
    RProgressBar* buffProgressbar[4];
    GStageData* stageData;
    QTimer paintTimer;//刷新屏幕绘制定时器
    QTimer updatePosTimer;//更新位置定时器
    QTimer addObjTimer;//添加物品定时器（刷新敌人或物资）
    QLayout* baseLayout;
    bool warning;
    bool gameEnd;//游戏结束判断属性
    std::vector<std::vector<int>> multiKeys;
    Ui::Form ui;
};

#endif


