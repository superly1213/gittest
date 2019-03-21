#ifndef CXMTJPAGE_H
#define CXMTJPAGE_H

#include <QWidget>
#include "ui_cxmtjpage.h"

class CXmtjPage : public QWidget
{
	Q_OBJECT

public:
	CXmtjPage(QWidget *parent = 0);
	~CXmtjPage();

protected:
	virtual void paintEvent(QPaintEvent * event);

private:
	Ui::CXmtjPage ui;
};

#endif // CXMTJPAGE_H
