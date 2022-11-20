/********************************************************************************
** Form generated from reading UI file 'handbookscene.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDBOOKSCENE_H
#define UI_HANDBOOKSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandBookScene
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label;

    void setupUi(QWidget *HandBookScene)
    {
        if (HandBookScene->objectName().isEmpty())
            HandBookScene->setObjectName("HandBookScene");
        HandBookScene->resize(535, 644);
        verticalLayout = new QVBoxLayout(HandBookScene);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(HandBookScene);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 511, 620));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(0, 0));
        layoutWidget = new QWidget(scrollAreaWidgetContents_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 658, 623));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("min-height:200px;"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("min-height:150px;"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("background-image:url(:/img/images/mrq04.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"min-height:80px;"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("min-height:80px;"));

        gridLayout->addWidget(label_2, 2, 1, 2, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("min-height:80px;"));

        gridLayout->addWidget(label_7, 5, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("background-image:url(:/img/images/mrq03.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"min-height:150px;"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("background-image:url(:/img/images/mrq02.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"min-height:100px;"));

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-image:url(:/img/images/mrq01.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"min-height:100px;"));

        gridLayout->addWidget(label, 0, 0, 2, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(HandBookScene);

        QMetaObject::connectSlotsByName(HandBookScene);
    } // setupUi

    void retranslateUi(QWidget *HandBookScene)
    {
        HandBookScene->setWindowTitle(QCoreApplication::translate("HandBookScene", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("HandBookScene", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ff0000;\">\347\242\260\346\222\236\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa00;\">\347\211\271\346\200\247\357\274\232\346\227\240\357\274\210\345\217\252\345\205\267\346\234\211\346\234\200\346\231\256\351\200\232\347\232\204\347\211\271\347\202\271\357\274\214\345\220\221\345\211\215\344\273\245\345\217\212\345\267\246\345\217\263\347\247\273\345\212\250\357\274\211</span></p><p><span style=\" color:#ffaa00;\">\345\216\237\345\236\213\357\274\232SARS\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa7f;\">tips:\351\235\236\345\205\270\347\227\205\346\257\222\345\261\236\344\272\216\345\206\240\347\212\266\347\227\205\346\257\222\357\274\214\346\230\257\344\270\200\347\247\215\350\265\267\347\227\205\346\200\245\343\200\201</span></p><p><span style=\" color:#ffaa7f;\">\344\274\240\346\222\255\345\277\253\343\200\201\347\227\205\346\255\273\347\216\207\351\253\230\347\232\204\344\274"
                        "\240\346\237\223\347\227\205\343\200\202</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("HandBookScene", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ff0000;\">\351\230\262\345\276\241\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa00;\">\347\211\271\346\200\247\357\274\232\345\205\267\346\234\211\350\276\203\351\253\230\347\232\204\347\224\237\345\221\275\345\200\274</span></p><p><span style=\" color:#ffaa00;\">\345\216\237\345\236\213\357\274\232\347\213\202\347\212\254\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa7f;\">tips:\347\213\202\347\212\254\347\227\205\346\202\243\350\200\205\357\274\214\345\270\270\350\241\250\347\216\260\344\270\272\351\253\230\345\272\246\345\205\264\345\245\213\345\222\214\346\277\200\345\212\250\357\274\214</span></p><p><span style=\" color:#ffaa7f;\">\346\201\220\346\260\264\346\200\225\346\260\264\347\255\211\347\227\207\347\212\266\343\200\202</span></p></body></html>", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("HandBookScene", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ff0000;\">\350\206\250\350\203\200\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa00;\">\347\211\271\346\200\247\357\274\232\344\275\223\347\247\257\344\274\232\347\252\201\347\204\266\345\217\230\345\244\247</span></p><p><span style=\" color:#ffaa00;\">\345\216\237\345\236\213\357\274\232\351\251\254\347\247\213\346\263\242\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa7f;\">tips:\351\251\254\347\247\213\346\263\242\347\227\205\346\257\222\346\230\257\344\270\200\347\247\215\346\262\231\347\262\222\347\227\205\346\257\222\357\274\214</span></p><p><span style=\" color:#ffaa7f;\">\350\257\245\347\227\205\346\257\222\347\224\261\350\200\201\351\274\240\346\220\272\345\270\246\343\200\202</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("HandBookScene", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700; color:#ff0000;\">\345\217\230\351\200\237\347\227\205\346\257\222</span></p><p><span style=\" color:#ffaa00;\">\347\211\271\346\200\247\357\274\232\344\274\232\347\252\201\347\204\266\345\212\240\351\200\237\345\220\221\345\211\215\357\274\214\344\270\224\344\274\232\345\220\216\351\200\200</span></p><p><span style=\" color:#ffaa00;\">\345\216\237\345\236\213\357\274\232\344\270\231\350\202\235\347\227\205\346\257\222</span></p><p><span style=\" font-size:10pt; color:#ffaa7f;\">tips:\350\257\245\347\227\205\346\257\222\345\217\257\345\257\274\350\207\264\350\202\235\350\204\217\346\205\242\346\200\247\347\202\216\347\227\207\345\235\217\346\255\273\357\274\214</span></p><p><span style=\" font-size:10pt; color:#ffaa7f;\">\344\270\273\350\246\201\347\224\261\350\276\223\350\241\200\343\200\201\345\220\270\346\257\222\344\274\240\346\222\255\343\200\202</span></p></body></html>", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HandBookScene: public Ui_HandBookScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDBOOKSCENE_H
