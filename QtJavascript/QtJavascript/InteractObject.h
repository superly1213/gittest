#ifndef __INTERACT_OBJECT_H__
#define __INTERACT_OBJECT_H__

#include <QObject>
#include <QString>

class JsWidget;

class InteractObject : public QObject
{
	Q_OBJECT

public:
	InteractObject(JsWidget *parent);

	void sendStringToHtml(const QString &text);

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
	QString _text;
	QString _recieveText;
	JsWidget *_jsWidget;
};

#endif