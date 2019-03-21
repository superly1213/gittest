#include "JsWidget.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include "CXmtjPage.h"
#include "mywindow.h"
//github test add modify
int main(int argc, char *argv[])
{
	

	QApplication a(argc, argv);
	/*JsWidget w;
	w.show();*/
	CMyWindow w;//CXmtjPage 
	w.show();
	return a.exec();
}
