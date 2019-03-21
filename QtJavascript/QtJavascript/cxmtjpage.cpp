#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <qmath.h>
#include "cxmtjpage.h"

CXmtjPage::CXmtjPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	setAttribute(Qt::WA_TranslucentBackground);

	QPoint   m_pos;
	QSize    m_normalSize;
	QSize    m_fullScreenSize;
	m_pos.setX(0);
	m_pos.setY(0);
	m_normalSize.setWidth(1200);
	m_normalSize.setHeight(800);

	m_fullScreenSize.setWidth(QApplication::desktop()->width());
	m_fullScreenSize.setHeight(QApplication::desktop()->height() - 40);
	//根据屏幕大小调整 最小大小
//	if (QApplication::desktop()->height() < 800)
	{
		setMinimumSize(1200, QApplication::desktop()->height() - 40);
		setGeometry(0, 0, 1200, QApplication::desktop()->height() - 40);
		m_normalSize.setHeight(QApplication::desktop()->height() - 40);
	}
}

CXmtjPage::~CXmtjPage()
{

}

void CXmtjPage::paintEvent(QPaintEvent *event)
{
	// 绘制阴影

	int xLenght = 5;
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(xLenght, xLenght, this->width() - 2 * xLenght, this->height() - 2 * xLenght);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);
	for (int i = 0; i < xLenght; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(xLenght - i, xLenght - i, this->width() - (xLenght - i) * 2, this->height() - (xLenght - i) * 2);
		color.setAlpha(90 - qSqrt(i) * 40);
		painter.setPen(color);
		painter.drawPath(path);
	}

	//QWidget::paintEvent(event);
}