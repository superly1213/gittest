#include "JsWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFile>
#include <QDir>
#include <QTextCodec>

JsWidget::JsWidget(QWidget *parent)
	: QWidget(parent)
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

	_interactObj = new InteractObject(this);

	// qt界面
	_edtContent = new QPlainTextEdit(this);
	_edtContent->setMinimumWidth(400);
	_edtInput = new QLineEdit(this);
	_btnSend = new QPushButton("发送文本", this);
	connect(_btnSend, SIGNAL(clicked()), this, SLOT(onSendSlot()));

	QHBoxLayout *hLayout1 = new QHBoxLayout();
	hLayout1->addWidget(_edtInput, 1);
	hLayout1->addWidget(_btnSend);
	QVBoxLayout *vLayout1 = new QVBoxLayout();
	vLayout1->addWidget(_edtContent, 1);
	vLayout1->addLayout(hLayout1);
	QGroupBox *qtGroup = new QGroupBox("Qt界面", this);
	qtGroup->setLayout(vLayout1);

	// web界面
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject(QStringLiteral("qt_html_connecter"), _interactObj);
	_webView = new QWebEngineView(this);
	_webView->page()->setWebChannel(channel);

	QUrl baseUrl = QUrl::fromLocalFile(QDir::current().absoluteFilePath("."));
	//QFile file("test.html");
	QFile file("xmtj_web_chart.html");
	
	if (file.open(QIODevice::ReadOnly)){
		QTextStream stream(&file);
		QString content = stream.readAll();
		_webView->setHtml(content, baseUrl);
	}
	_webView->show();
	QVBoxLayout *vLayout2 = new QVBoxLayout();
	vLayout2->addWidget(_webView, 1);
	QGroupBox *webGroup = new QGroupBox("Web界面", this);
	webGroup->setLayout(vLayout2);

	// 布局
	QHBoxLayout *mainLayout = new QHBoxLayout();
	mainLayout->addWidget(qtGroup);
	mainLayout->addWidget(webGroup);
	this->setLayout(mainLayout);

	this->setMinimumSize(800, 600);
}

void JsWidget::appendContent(const QString &text)
{
	_edtContent->appendPlainText(text);
}

JsWidget::~JsWidget()
{

}

void JsWidget::onSendSlot()
{
	QString text = _edtInput->text().trimmed();
	if (text.isEmpty())
		return;

	_interactObj->sendStringToHtml(text);
	_edtInput->setText("");
}

