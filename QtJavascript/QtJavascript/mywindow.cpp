#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "mywindow.h"
#include "CXmtjPage.h"
#include "./chart/webchartwidget.h"

CMyWindow::CMyWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	setAttribute(Qt::WA_TranslucentBackground);

	ui.titleBarWidget->installEventFilter(this);

	m_normalSize.setWidth(1200);
	m_normalSize.setHeight(800);

	m_fullScreenSize.setWidth(QApplication::desktop()->width());
	m_fullScreenSize.setHeight(QApplication::desktop()->height() - 40);
	//根据屏幕大小调整 最小大小
	if (QApplication::desktop()->height() < 800)
	{
		setMinimumSize(1200, QApplication::desktop()->height() - 40);
		setGeometry(0, 0, 1200, QApplication::desktop()->height() - 40);
		m_normalSize.setHeight(QApplication::desktop()->height() - 40);
	}
	//set

	connect(ui.homeButton, SIGNAL(clicked()), this, SLOT(onBtnHomeClicked()));
	connect(ui.webButton, SIGNAL(clicked()), this, SLOT(onBtnWebClicked()));
}

CMyWindow::~CMyWindow()
{

}


QWidget* CMyWindow::CreatePage()
{
	QWidget *pWidget = new CXmtjPage(this);

	if (m_pWidget)
	{
		ui.homeHLayout->removeWidget(m_pWidget);
		delete 	m_pWidget;
		m_pWidget = nullptr;
	}

	m_pWidget = pWidget;
	pWidget->setVisible(true);
	pWidget->setObjectName("m_pWidget");
	ui.homeHLayout->insertWidget(0, pWidget);

	return pWidget;
}

bool CMyWindow::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress && (obj == ui.titleBarWidget))
	{
		QMouseEvent *mevent = dynamic_cast<QMouseEvent *>(event);
		if (mevent)
		{
			if (mevent->button() == Qt::LeftButton)
			{
				m_DragPosition = mevent->pos();

				m_xPressRatio = m_DragPosition.x() / (width()*1.0);
				event->accept();
			}
		}
	}
	else if (event->type() == QEvent::MouseMove && (obj == ui.titleBarWidget))
	{
		QMouseEvent *mevent = dynamic_cast<QMouseEvent *>(event);
		if (mevent)
		{

				QPoint pos = QPoint(mevent->globalPos().x() - width() * m_xPressRatio, mevent->globalPos().y() - m_DragPosition.y());

				move(pos);
				event->accept();
		}
	}
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		if (!obj)
		{
			return true;
		}

		if (obj == ui.titleBarWidget)
		{
			onBtnMaxClicked();
		}

		return true;
	}
	else
	{
		// pass the event on to the parent class
		return QObject::eventFilter(obj, event);
	}
}


void CMyWindow::paintEvent(QPaintEvent *event)
{
	// 其他
	

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


void CMyWindow::onBtnHomeClicked()
{
	//CreatePage();
	
	QWidget *pWidget = new CWebChartWidget(this);

	if (m_pWidget)
	{
		ui.homeHLayout->removeWidget(m_pWidget);
		delete 	m_pWidget;
		m_pWidget = nullptr;
	}

	m_pWidget = pWidget;
	pWidget->setVisible(true);
	pWidget->setObjectName("m_pWidget");
	ui.homeHLayout->insertWidget(0, pWidget);

}

void CMyWindow::onBtnWebClicked()
{
	CreatePage();
}


void CMyWindow::onBtnMaxClicked()
{
	if (m_bMax)
	{
		ui.verticalLayout->setContentsMargins(5, 5, 5, 5);
		showWindowNormal();
	}
	else
	{
		ui.verticalLayout->setContentsMargins(0, 0, 0, 0);
		showWindowMaximized();
	}
}

void CMyWindow::showWindowNormal()
{
	resize(m_normalSize);
	m_bMax = false;
	move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);
}

void CMyWindow::showWindowMaximized()
{
	resize(m_fullScreenSize);
	//setWindowState(Qt::WindowMaximized);
	//this->setWindowState(Qt::WindowMaximized);
	m_bMax = true;
	move(0, 0);
}