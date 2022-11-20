#ifndef FILESAVESCENE_H
#define FILESAVESCENE_H
#include "ui_filesavescene.h"
#include <QWidget>
namespace Ui
{
class FileSaveScene;
}

class FileSaveScene : public QWidget
{
    Q_OBJECT

public:
    explicit FileSaveScene(QWidget *parent = nullptr);
    ~FileSaveScene();

private:
    Ui::FileSaveScene* ui;
    QVBoxLayout* layout;
};

#endif // FILESAVESCENE_H
