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
	CWebChartWidget *m_pWebWidget;
};

#endif