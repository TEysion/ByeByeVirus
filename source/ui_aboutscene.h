/********************************************************************************
** Form generated from reading UI file 'aboutscene.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSCENE_H
#define UI_ABOUTSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutScene
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *AboutScene)
    {
        if (AboutScene->objectName().isEmpty())
            AboutScene->setObjectName(QString::fromUtf8("AboutScene"));
        AboutScene->resize(500, 700);
        verticalLayout = new QVBoxLayout(AboutScene);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(AboutScene);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(AboutScene);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_4 = new QLabel(AboutScene);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        label_3 = new QLabel(AboutScene);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(AboutScene);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        retranslateUi(AboutScene);

        QMetaObject::connectSlotsByName(AboutScene);
    } // setupUi

    void retranslateUi(QWidget *AboutScene)
    {
        AboutScene->setWindowTitle(QCoreApplication::translate("AboutScene", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("AboutScene", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; color:#ff0000;\">\345\205\263\344\272\216\346\270\270\346\210\217</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AboutScene", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#ffaa7f;\">1.\345\274\200\345\217\221\346\210\220\345\221\230\357\274\232\350\221\233\346\224\277\351\224\237\357\274\210\347\273\204\351\225\277\357\274\211 \351\251\254\347\221\236\346\263\211\357\274\210\347\273\204\345\221\230\357\274\211</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("AboutScene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#ffaa7f;\">2.\345\220\204\347\247\215\347\227\205\346\257\222\343\200\201buff\345\233\276\347\211\207\344\275\277\347\224\250PS\350\275\257\344\273\266\350\216\267\345\276\227</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("AboutScene", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#ffaa7f;\">3.\346\270\270\346\210\217\344\270\2728\345\205\263\344\273\245\345\217\212\351\200\232\345\205\263\345\220\216\345\217\257\350\247\243\351\224\201\346\227\240\345\260\275\346\250\241\345\274\217</span></p><p><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#ffaa7f;\">\357\274\210\345\217\252\346\234\211\346\227\240\345\260\275\346\250\241\345\274\217\344\274\232\346\216\211\350\220\275buff\357\274\211</span></p></body></html>", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutScene: public Ui_AboutScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSCENE_H
