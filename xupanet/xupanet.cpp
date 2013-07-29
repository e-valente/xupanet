#include "xupanet.h"
#include "ui_xupanet.h"
#include "youtubeurlhandler.h"
#include "videorender.h"

#include <QUrl>
#include <QtNetwork/QNetworkProxy>
#include <QWebSettings>
#include <QMessageBox>
#include <QShortcut>
#include <QKeySequence>
#include <QThread>

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
    delete videorender;
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

        /*colocando na thread*/
        QThread *thread = new QThread;

        videorender = new VideoRender();
        videorender->moveToThread(thread);
        //conectar aqui uma msg de erro `a thread

        //faz bind() com a thread +  nosso metodo
        connect(thread, SIGNAL(started()), videorender, SLOT(process()));

        //conecta o sinal finished pra sair da thread
        connect(videorender, SIGNAL(finished()), thread, SLOT(quit()));

        connect(videorender, SIGNAL(finished()), videorender, SLOT(deleteLater()));
        connect(videorender, SIGNAL(finished()), thread, SLOT(deleteLater()));

        thread->start();

    }

    delete urlhandler;


    //() << "App path : " << strurl;
}

void XupaNet::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}
