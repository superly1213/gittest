#ifndef WEBCHARTWIDGET_H
#define WEBCHARTWIDGET_H

#include <QWidget>
#include "ui_webchartwidget.h"

class CConnectObject;
class QWebEngineView;
class CWebChartWidget : public QWidget
{
	Q_OBJECT

public:
	CWebChartWidget(QWidget *parent = 0);
	~CWebChartWidget();

	void recvStringFromHtml(const QString &text);

private slots:
	void onSendSlot();

private:
	void init();

protected:
	virtual void showEvent(QShowEvent *);

private:
	Ui::CWebChartWidget ui;
	CConnectObject *m_pConnecter;
	QWebEngineView *m_pWebView = nullptr;
};

#endif // WEBCHARTWIDGET_H
