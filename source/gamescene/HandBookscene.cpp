#include "HandBookscene.h"
#include "ui_handbookscene.h"
#include <QPalette>
#include <QPixmap>
HandBookScene::HandBookScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandBookScene)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    //设置背景
    QPalette pal;
    QPixmap pixmap(":img/images/bg1.png");
    pal.setBrush(this->backgroundRole(), QBrush(pixmap));
    setPalette(pal);
}

HandBookScene::~HandBookScene()
{
    delete ui;
}
