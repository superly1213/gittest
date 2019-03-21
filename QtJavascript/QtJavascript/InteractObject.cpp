#include "InteractObject.h"
#include "JsWidget.h"


InteractObject::InteractObject(JsWidget *parent)
: QObject(parent)
, _jsWidget(parent)
{ 
	
}

void InteractObject::sendStringToHtml(const QString &text)
{
	emit sendStringToHtmlSignal(text);
}

/*!
This slot is invoked from the HTML client side and the text displayed on the server side.
*/
void InteractObject::recvStringFromHtmlSlot(const QString &text)
{
	_jsWidget->appendContent("Received string: " + text);
}