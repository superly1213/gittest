#include <QFile>
#include <QDir>
#include <QWebChannel>
#include <QWebEngineView>
#include <QTextCodec>
#include <qdebug.h>
#include "connectbject.h"
#include "webchartwidget.h"

#pragma execution_character_set("utf-8")

CWebChartWidget::CWebChartWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	init();
}

CWebChartWidget::~CWebChartWidget()
{

}

void CWebChartWidget::init()
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

	m_pConnecter = new CConnectObject(this);

	// web½çÃæ
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject(QStringLiteral("qt_html_connecter"), m_pConnecter); 
	m_pWebView = new QWebEngineView(this);
	m_pWebView->setObjectName(QStringLiteral("m_pWebView"));
	m_pWebView->page()->setWebChannel(channel);

	QUrl baseUrl = QUrl::fromLocalFile(QDir::current().absoluteFilePath("."));
	QFile file("xmtj_web_chart.html");
	//QFile file("series.htm");
	//QFile file("xmtjchart.html");
	if (file.open(QIODevice::ReadOnly)){
		QTextStream stream(&file);
		QString content = stream.readAll();
		m_pWebView->setHtml(content, baseUrl);
	}
	m_pWebView->show();

	ui.horizontalLayout->addWidget(m_pWebView);

	QString strText = "sendStringToHtml---------";
	m_pConnecter->sendStringToHtml(strText);

	connect(ui.ckButton, SIGNAL(clicked()), this, SLOT(onSendSlot()));
}

void CWebChartWidget::showEvent(QShowEvent *event)
{
	if (m_pWebView)
	{
		m_pWebView->reload();
	}
	
	QWidget::showEvent(event);
}

void CWebChartWidget::recvStringFromHtml(const QString &text)
{
	qDebug() << text << "\n";
}


void CWebChartWidget::onSendSlot()
{
	QString text = ui.lineEdit->text().trimmed();
	if (text.isEmpty())
		return;

	m_pConnecter->sendStringToHtml(text);
}
