#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QDir>
#include <thread>
#include "ui_filesavescene.h"
#include "gamewidget/MPushButton.h"
#include "gameconfig//PlayerMessage.h"
#include "gameconfig/Config.h"
#include "FileSaveScene.h"
#include "MainMenuScene.h"

FileSaveScene::FileSaveScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileSaveScene)
{
    setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);
    //设置背景
    QPalette pal;
    QPixmap pixmap(":img/images/bg1.png");
    pal.setBrush(this->backgroundRole(), QBrush(pixmap));
    setPalette(pal);

    layout=ui->verticalLayout;

    //使Ui可自适应父窗口大小
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ui->verticalLayoutWidget);
    setLayout(mainLayout);

    QDir dir(Config::getDataFileDir());
    QStringList nameFilters;
    nameFilters << "*.p";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    for(int i=0;i<files.size();i++){
        QHBoxLayout* childlayout=new QHBoxLayout(this);
        childlayout->setSpacing(0);
        childlayout->setContentsMargins(QMargins(0,0,0,0));
        QWidget* child=new QWidget(this);
        child->setLayout(childlayout);
        child->setProperty("type","containerwidget");
        MPushButton* btnOldGame=new MPushButton();
        btnOldGame->setProperty("type","fill");
        qDebug()<<dir<<":AbsolutePath:"<<files[i];
        btnOldGame->setText(files[i].section('.', 0, 0)+"的存档");
        MPushButton* btnDelete=new MPushButton();
        btnDelete->setProperty("type","delete");
        btnDelete->setText("删除");
        childlayout->addWidget(btnOldGame);
        childlayout->addWidget(btnDelete);
        layout->addWidget(child);
        //监听点击事件
        connect(btnOldGame, &MPushButton::clicked, [=]() {
            qDebug()<<"filesi nickname="<<files[i];
            Config::initPlayerMessage(files[i]);
            (new MainMenuScene())->show();
            close();
            });
        connect(btnDelete, &MPushButton::clicked, [=]() {
            QFile fileTemp(Config::getDataFileDir()+"/"+files[i]);
            fileTemp.remove();
            delete btnDelete;
            delete btnOldGame;
            delete child;
            });


    }

    MPushButton* btnNewGame=new MPushButton();
    btnNewGame->setProperty("type","normalbtn");
    btnNewGame->setText("新游戏");
    layout->addWidget(btnNewGame);

    //监听点击事件，执行特效
    connect(btnNewGame, &MPushButton::clicked, [=]() {
        bool bRet = false;
        //单文本输入框
        QString text = QInputDialog::getText(this, "提示","请输入名字", QLineEdit::Normal, "", &bRet,Qt::WindowFlags(),Qt::InputMethodHints());
        if (bRet && !text.isEmpty())
        {
            PlayerMessage* pmsg=new PlayerMessage(text);
            pmsg->setProgress(1);
            Config::setPlayerMessage(pmsg);
            (new MainMenuScene())->show();
            close();
        }
        });
}

FileSaveScene::~FileSaveScene()
{
    delete ui;
}




