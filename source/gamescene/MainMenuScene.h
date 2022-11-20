#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QWidget>
#include <QVBoxLayout>
#include "ui_mainmenuscene.h"
class MainMenuScene: public QWidget
{
    Q_OBJECT
public:

    explicit MainMenuScene(QWidget* parent = Q_NULLPTR);

private:
    void addStageLevelButton(int i);
    bool eventFilter(QObject *obj, QEvent *event);
    Ui::MainMenuScene ui;
    QVBoxLayout* layout;
};

#endif // MAINMENUSCENE_H
