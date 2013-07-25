#include "xupanet.h"
#include "ui_xupanet.h"

#include <QUrl>
#include <QtNetwork/QNetworkProxy>

XupaNet::XupaNet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XupaNet)
{
    ui->setupUi(this);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
}

XupaNet::~XupaNet()
{
    delete ui;
}

void XupaNet::on_pushButton_clicked()
{
    QNetworkProxy proxy(QNetworkProxy::HttpProxy, "95.87.239.115", 8080);
    QNetworkProxy::setApplicationProxy(proxy);

    QString strurl = ui->urlField->text();
    QUrl myurl(strurl);
    ui->webView->load(myurl);
    ui->webView->show();
}
