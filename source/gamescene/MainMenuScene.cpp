#include "MainMenuScene.h"
#include <QPushButton>
#include <QLabel>
#include <QScroller>
#include "GameScene.h"
#include "FileSaveScene.h"
#include "gamewidget/MPushButton.h"
#include "gameconfig/Config.h"
#include "AboutScene.h"
#include "HandBookscene.h"
void MainMenuScene::addStageLevelButton(int i){
    MPushButton* btn = new MPushButton;
    //显示文本
    btn->setText("关卡"+QString::number(i));
    layout->addWidget(btn);
    btn->setProperty("type","normalbtn");
    if(i>Config::getPlayerMessage()->getProgress())btn->setEnabled(false),btn->setText("未解锁"),btn->setAttribute(Qt::WA_TransparentForMouseEvents, true);  //鼠标事件穿透
    connect(btn, &MPushButton::clicked,this, [=]() {
        btn->zoom1(); //向下跳跃
        btn->zoom2(); //向上跳跃
        QTimer::singleShot(100, this, [=]() {
            //this->hide();
            GameScene* e=new GameScene;
            e->setStageData(new GStageData(i));
            e->show();
            e->startGame();
            this->close();
        });
    });
}

MainMenuScene::MainMenuScene(QWidget* parent) :QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui.setupUi(this);

    //设置背景
    QPalette pal;
    QPixmap pixmap(":img/images/bg1.png");
    pal.setBrush(this->backgroundRole(), QBrush(pixmap));
    this->setPalette(pal);

    //使Ui可自适应父窗口大小
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ui.verticalLayoutWidget_2);
    setLayout(mainLayout);

    layout=ui.verticalLayout;
    for(int i=1;i<=8;i++){
        addStageLevelButton(i);
    }
    MPushButton* btn = new MPushButton;
    //显示文本
    btn->setText("无尽模式");
    layout->addWidget(btn);
    btn->setProperty("type","normalbtn");
    if(9>Config::getPlayerMessage()->getProgress())btn->setEnabled(false),btn->setText("未解锁"),btn->setAttribute(Qt::WA_TransparentForMouseEvents, true);  //鼠标事件穿透
    connect(btn, &MPushButton::clicked,this, [=]() {
        btn->zoom1(); //向下跳跃
        btn->zoom2(); //向上跳跃
        QTimer::singleShot(100, this, [=]() {
            //this->hide();
            GameScene* e=new GameScene;
            e->setStageData(new GStageData(0));
            e->show();
            e->startGame();
            this->close();
        });
    });
    //使用事件过滤器
    ui.label_2->installEventFilter(this);
    ui.label_3->installEventFilter(this);
    ui.label_4->installEventFilter(this);
    //保存玩家信息
    Config::savePlayerMessage();

#ifdef Q_OS_ANDROID
    QScroller::grabGesture(ui.scrollArea,QScroller::LeftMouseButtonGesture);//TouchGesture
#endif

}

//事件过滤器，判断点击了哪个QLabel
bool MainMenuScene::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui.label_2)
    {
         if (event->type() == QEvent::MouseButtonPress)
         {
            (new AboutScene())->show();
            return true;
         }
    }
    else if(obj == ui.label_3)
    {
         if (event->type() == QEvent::MouseButtonPress)
         {
            (new FileSaveScene())->show();
            close();
            return true;
         }
    }
    else if(obj == ui.label_4)
    {
         if (event->type() == QEvent::MouseButtonPress)
         {
            (new HandBookScene())->show();

            return true;
         }
    }
    return false;
}
