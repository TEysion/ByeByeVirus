/********************************************************************************
** Form generated from reading UI file 'filesavescene.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESAVESCENE_H
#define UI_FILESAVESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSaveScene
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FileSaveScene)
    {
        if (FileSaveScene->objectName().isEmpty())
            FileSaveScene->setObjectName(QString::fromUtf8("FileSaveScene"));
        FileSaveScene->resize(500, 700);
        FileSaveScene->setWindowOpacity(5.000000000000000);
        verticalLayoutWidget = new QWidget(FileSaveScene);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 501, 701));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(400, 150));
        label->setMaximumSize(QSize(400, 150));
        label->setSizeIncrement(QSize(400, 100));
        label->setBaseSize(QSize(400, 100));
        label->setStyleSheet(QString::fromUtf8("border-image:url(:/img/images/title.png);"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FileSaveScene);

        QMetaObject::connectSlotsByName(FileSaveScene);
    } // setupUi

    void retranslateUi(QWidget *FileSaveScene)
    {
        FileSaveScene->setWindowTitle(QCoreApplication::translate("FileSaveScene", "\346\266\210\347\201\255\347\227\205\346\257\222", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileSaveScene: public Ui_FileSaveScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESAVESCENE_H
