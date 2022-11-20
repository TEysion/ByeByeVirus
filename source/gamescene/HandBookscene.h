#ifndef HANDBOOKSCENE_H
#define HANDBOOKSCENE_H

#include <QWidget>

namespace Ui {
class HandBookScene;
}

class HandBookScene : public QWidget
{
    Q_OBJECT

public:
    explicit HandBookScene(QWidget *parent = nullptr);
    ~HandBookScene();

private:
    Ui::HandBookScene *ui;
};

#endif // HANDBOOKSCENE_H
