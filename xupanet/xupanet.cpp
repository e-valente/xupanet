#include "xupanet.h"
#include "ui_xupanet.h"
#include "youtubeurlhandler.h"

#include <QUrl>
#include <QtNetwork/QNetworkProxy>
#include <QWebSettings>
#include <QMessageBox>
#include <QShortcut>
#include <QKeySequence>
XupaNet::XupaNet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XupaNet)
{
    ui->setupUi(this);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(on_pushButton_clicked()));
}

XupaNet::~XupaNet()
{
    delete shortcut;
    delete ui;
}

void XupaNet::on_pushButton_clicked()
{
    //QNetworkProxy proxy(QNetworkProxy::HttpProxy, "95.87.239.115", 8080);
    //QNetworkProxy::setApplicationProxy(proxy);


    QString str = ui->urlField->text();
    //QUrl myurl(strurl);
    urlhandler = new YouTubeUrlHandler(str);
    if(!urlhandler->makeUrl())
    {
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setText("Invalid Url");
        msgbox.exec();
    }
    else{
        urlhandler->makeHtmlFile();
        QString strurl("file://" + qApp->applicationDirPath() + "/youtubevideo.html");
        QUrl myurl(strurl);
        ui->webView->load(myurl);
        ui->webView->show();
    }

    delete urlhandler;


    //() << "App path : " << strurl;
}

void XupaNet::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}
