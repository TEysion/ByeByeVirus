#pragma once
#include <QLabel>
class RProgressBar : public QLabel
{
public:
    explicit RProgressBar(QWidget* parent = 0);//构造函数
	void paintEvent(QPaintEvent*);
	void setText(QString text);
	void setImg(QPixmap img);
	void setProgress(int progress);
	void setMaxProgress(int max);
private:
	int maxProgress;
	int progress;
	QPixmap bg;
	QPixmap img;
	QString text;
	QList<QPointF> points; // 进度曲线的顶点数组
};

