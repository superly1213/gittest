#include "connectbject.h"
#include "webchartwidget.h"


CConnectObject::CConnectObject(CWebChartWidget *parent)
: QObject(parent)
, m_pWebWidget(parent)
{ 
	
}

void CConnectObject::sendStringToHtml(const QString &text)
{
	emit sendStringToHtmlSignal(text);
}

/*!
This slot is invoked from the HTML client side and the text displayed on the server side.
*/
void CConnectObject::recvStringFromHtmlSlot(const QString &text)
{
	m_pWebWidget->recvStringFromHtml(text);
}