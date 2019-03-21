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

	// ��
public slots:
	// ���Ա�javascript����
	void recvStringFromHtmlSlot(const QString &text);

	// �ź�
signals:
	// ��javascript�ļ����涨�����Ӻ�����
	// Ȼ�����źŴ���javascript����
	void sendStringToHtmlSignal(const QString &text);

private:
	QString _text;
	QString _recieveText;
	JsWidget *_jsWidget;
};

#endif