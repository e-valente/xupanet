#include "xupanet.h"
#include "ui_xupanet.h"

#include <QUrl>
#include <QtNetwork/QNetworkProxy>
#include <QWebSettings>

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



    /*antigo*/
    //QString strurl = ui->urlField->text();
    //QUrl myurl(strurl);

    QString strurl("file://" + qApp->applicationDirPath() + "/youtubevideo.html");
    QUrl myurl(strurl);
    ui->webView->load(myurl);
    ui->webView->show();

    //() << "App path : " << strurl;
}
