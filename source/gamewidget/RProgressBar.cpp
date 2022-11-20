#include "RProgressBar.h"
#include <QPainter>
#include <QPainterPath>

RProgressBar::RProgressBar(QWidget* parent)
{
    bg.load(":img/images/grprogressbarbg.png");
	setPixmap(bg.scaled(QSize(70, 80)));
    setFixedSize(60, 80);
	maxProgress = 100;
	progress = 100;
}

void RProgressBar::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, width(), height(), bg);
	painter.drawPixmap(0, 0, width(), width(), img);
    QPen pen;
    pen.setStyle(Qt::PenStyle(1));//画笔风格


    pen.setWidth(2);//画笔宽度

	int d = 40;       //调节圆角的大小
	int r = d / 2;

	pen.setColor(Qt::white);//画笔颜色

	painter.setPen(pen);

	painter.setRenderHint(QPainter::Antialiasing);


	QPainterPath path;
	int padding = 2;
	int mWidth = width() - padding * 2 - r * 2;
	int mHeight = height() - padding * 2 - r * 2;
	int quarterCircle = 3.1415926 * 2 * r / 4;
	QPoint lt(padding, padding);
	QPoint rt(width() - padding, padding);
	QPoint rb(width() - padding, height() - padding);
	QPoint lb(padding, height() - padding);
	int length = (mWidth * 2 + mHeight * 2 + quarterCircle * 4) *progress / maxProgress;

	path.moveTo(lt.x()+r,lt.y());//左上(起点)
	if ((length -= mWidth) >= 0) {
		path.lineTo(rt.x() - r, rt.y());//右上
		if ((length -= quarterCircle) >= 0) {
			path.arcTo(rt.x() - d, rt.y(), d, d, 90.0f, -90.0f);//右上弧
			if ((length -= mHeight) >= 0) {
				path.lineTo(rb.x(), rb.y() - r);//右下
				if ((length -= quarterCircle) >= 0) {
					path.arcTo(rb.x() - d, rb.y() - d, d, d, 0.0f, -90.0f);//右下弧
					if ((length -= mWidth) >= 0) {
						path.lineTo(lb.x() + r, lb.y());//左下
						if ((length -= quarterCircle) >= 0) {
							path.arcTo(lb.x(), lb.y()-d, d, d, 270.0f, -90.0f);//左下弧
							if ((length -= mHeight) >= 0) {
								path.lineTo(lt.x(), lt.y() + r);//左上
								if ((length -= quarterCircle) >= 0)
									path.arcTo(lt.x(), lt.y(), d, d, 180.0f, -90.0f);//左上弧
								else
									path.arcTo(lt.x(), lt.y(), d, d, 180.0f, -90.0 * (length + quarterCircle) / quarterCircle);//左上弧
							}
							else
								path.lineTo(lb.x(), lt.y() + r -length);//左上
						}
						else
							path.arcTo(lb.x(), lb.y()-d, d, d, 270.0f, -90.0 * (length + quarterCircle) / quarterCircle);//左下弧
					}
					else
						path.lineTo(lb.x() + r -length, rb.y());//左下
				}
				else
					path.arcTo(rb.x() - d, rb.y() - d, d, d, 0.0f, -90.0 * (length + quarterCircle) / quarterCircle);//右下弧
			}
			else
				path.lineTo(rb.x(), rb.y() - r + length);//右下
		}
		else
			path.arcTo(rt.x() - d, rt.y(), d, d, 90.0f, -90.0 * (length + quarterCircle) / quarterCircle);//右上弧
	}
	else
		path.lineTo(rt.x()-r+ length, rt.y());//右上
	painter.drawPath(path);
	pen.setColor(QColor(0x40,0xE0,0xD0));//画笔颜色
	painter.setPen(pen);
	//设置字体大小.另可以根据画笔改变颜色等属性
	QFont font = painter.font();
	font.setPixelSize(10);//改变字体大小
	font.setFamily("Microsoft YaHei");
	painter.setFont(font);
	//将文字写在图片上，例如是int型的数字123，居中
	painter.drawText(0,0,width(), height()*0.9, Qt::AlignHCenter | Qt::AlignBottom, text);
}

void RProgressBar::setText(QString text)
{
	this->text = text;
	update();
}

void RProgressBar::setImg(QPixmap img)
{
	this->img = img;
}

void RProgressBar::setProgress(int progress)
{
	this->progress = progress;
	update();
}

void RProgressBar::setMaxProgress(int max)
{
	maxProgress = max;
}
