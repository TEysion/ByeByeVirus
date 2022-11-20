/********************************************************************************
** Form generated from reading UI file 'mainmenuscene.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUSCENE_H
#define UI_MAINMENUSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuScene
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *base;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *MainMenuScene)
    {
        if (MainMenuScene->objectName().isEmpty())
            MainMenuScene->setObjectName(QString::fromUtf8("MainMenuScene"));
        MainMenuScene->resize(500, 700);
        verticalLayoutWidget_2 = new QWidget(MainMenuScene);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, -1, 501, 701));
        base = new QVBoxLayout(verticalLayoutWidget_2);
        base->setSpacing(0);
        base->setObjectName(QString::fromUtf8("base"));
        base->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        base->addItem(verticalSpacer_2);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(400, 150));
        label->setMaximumSize(QSize(400, 150));
        label->setStyleSheet(QString::fromUtf8("border-image:url(:/img/images/title.png);"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        base->addWidget(label, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        base->addItem(verticalSpacer);

        scrollArea = new QScrollArea(verticalLayoutWidget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(400, 0));
        scrollArea->setMaximumSize(QSize(400, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 377, 600));
        scrollAreaWidgetContents->setMinimumSize(QSize(300, 600));
        scrollAreaWidgetContents->setMaximumSize(QSize(400, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 361, 651));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        base->addWidget(scrollArea, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, 25, 50, 15);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setSizeIncrement(QSize(10, 10));
        label_2->setBaseSize(QSize(10, 10));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"background-image: url(:img/images/about.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"background-color:#aa000000;\n"
"border-radius: 15px;\n"
"color: transparent;\n"
"margin-top: 5px;\n"
"margin-bottom: 5px;\n"
"margin-right: 0px;\n"
"margin-left: 0px;\n"
"}\n"
".QLabel:hover{\n"
"background-color:#50000000;\n"
"color: white;\n"
"text-align: center;\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"background-image: url(:img/images/book.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"background-color:#aa000000;\n"
"border-radius: 15px;\n"
"color: transparent;\n"
"margin-top: 5px;\n"
"margin-bottom: 5px;\n"
"margin-right: 0px;\n"
"margin-left: 0px;\n"
"}\n"
".QLabel:hover{\n"
"background-color:#50000000;\n"
"color: white;\n"
"text-align: center;\n"
"}\n"
""));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 170));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        label_3->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"background-image: url(:img/images/save.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"background-color:#aa000000;\n"
"border-radius: 15px;\n"
"color: transparent;\n"
"margin-top: 5px;\n"
"margin-bottom: 5px;\n"
"margin-right: 0px;\n"
"margin-left: 0px;\n"
"}\n"
".QLabel:hover{\n"
"background-color:#50000000;\n"
"color: white;\n"
"text-align: center;\n"
"}\n"
""));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);


        base->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        base->addItem(verticalSpacer_4);

        base->setStretch(1, 1);
        base->setStretch(3, 3);
        base->setStretch(4, 1);

        retranslateUi(MainMenuScene);

        QMetaObject::connectSlotsByName(MainMenuScene);
    } // setupUi

    void retranslateUi(QWidget *MainMenuScene)
    {
        MainMenuScene->setWindowTitle(QCoreApplication::translate("MainMenuScene", "\346\266\210\347\201\255\347\227\205\346\257\222", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainMenuScene", "\345\205\263\344\272\216", nullptr));
        label_4->setText(QCoreApplication::translate("MainMenuScene", "\345\233\276\351\211\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainMenuScene", "\345\255\230\346\241\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuScene: public Ui_MainMenuScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUSCENE_H
