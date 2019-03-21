#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include "ui_mywindow.h"

class CMyWindow : public QWidget
{
	Q_OBJECT

public:
	CMyWindow(QWidget *parent = 0);
	~CMyWindow();


	QWidget* CreatePage();


private slots:
	void onBtnHomeClicked();
	void onBtnWebClicked();
	void onBtnMaxClicked();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *ev);
	virtual void paintEvent(QPaintEvent * event);

	void showWindowNormal();
	void showWindowMaximized();

private:
	Ui::CMyWindow ui;
	QPoint  m_DragPosition;
	float   m_xPressRatio;
	QWidget *m_pWidget = nullptr;
	bool m_bMax = false;
	QSize    m_normalSize;
	QSize    m_fullScreenSize;
};

#endif // MYWINDOW_H
