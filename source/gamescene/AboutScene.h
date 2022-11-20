#ifndef ABOUTSCENE_H
#define ABOUTSCENE_H

#include <QWidget>

namespace Ui
{
class AboutScene;
}

class AboutScene : public QWidget
{
    Q_OBJECT

public:
    explicit AboutScene(QWidget *parent = nullptr);
    ~AboutScene();

private:
    Ui::AboutScene *ui;
};

#endif // ABOUTSCENE_H
