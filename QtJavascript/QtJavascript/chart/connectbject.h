#ifndef __INTERACT_OBJECT_H__
#define __INTERACT_OBJECT_H__

#include <QObject>
#include <QString>

class CWebChartWidget;

class CConnectObject : public QObject
{
	Q_OBJECT

public:
	CConnectObject(CWebChartWidget *parent);

	void sendStringToHtml(const QString &text);

	//Q_INVOKABLE recvStringFromHtmlSlot1(const QString &text);
	// 槽
public slots:
	// 可以被javascript调用
	void recvStringFromHtmlSlot(const QString &text);

	// 信号
signals:
	// 在javascript文件里面定义链接函数，
	// 然后发送信号触发javascript函数
	void sendStringToHtmlSignal(const QString &text);

private:
	CWebChartWidget *m_pWebWidget;
};

#endif