#ifndef CTJPAGE_H
#define CTJPAGE_H

#include <QWidget>
#include "ui_ctjpage.h"

class CTjPage : public QWidget
{
	Q_OBJECT

public:
	CTjPage(QWidget *parent = 0);
	~CTjPage();

private:
	Ui::CTjPage ui;
};

#endif // CTJPAGE_H
