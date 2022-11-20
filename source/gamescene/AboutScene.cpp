#include "AboutScene.h"
#include "ui_aboutscene.h"
#include <QPixmap>
#include <QPalette>
AboutScene::AboutScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutScene)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    //设置背景
    QPalette pal;
    QPixmap pixmap(":img/images/bg1.png");
    pal.setBrush(this->backgroundRole(), QBrush(pixmap));
    setPalette(pal);
}

AboutScene::~AboutScene()
{
    delete ui;
}
