#ifndef JSWIDGET_H
#define JSWIDGET_H
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include <QWebEngineView>
#include <QWebChannel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "InteractObject.h"

class JsWidget : public QWidget
{
	Q_OBJECT

public:
	JsWidget(QWidget *parent = 0);
	~JsWidget();

public:
	void appendContent(const QString &text);

private slots:
	void onSendSlot();

private:
	QWebEngineView *_webView;
	InteractObject *_interactObj;

	QPlainTextEdit *_edtContent;
	QLineEdit *_edtInput;
	QPushButton *_btnSend;
};

#endif // JSWIDGET_H
