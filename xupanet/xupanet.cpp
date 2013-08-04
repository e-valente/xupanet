#include "xupanet.h"
#include "ui_xupanet.h"
#include "youtubeurlhandler.h"

#include <QUrl>
#include <QtNetwork/QNetworkProxy>
#include <QWebSettings>
#include <QMessageBox>
#include <QShortcut>
#include <QKeySequence>
#include <QThread>

#include <string>

XupaNet::XupaNet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XupaNet)
{
    ui->setupUi(this);

    /*bug do QT: se deixar os plugins
     *habilitados teremos segmentation fault qdo tiver
     *video carregado (ou nao) e tentarmos clicar dentro da janela (ex: menu)
     */

    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(on_pushButton_clicked()));
}

XupaNet::~XupaNet()
{
    delete shortcut;
    delete ui;
}

QString XupaNet::get_proxy_ws()
{
    QString ws_url = "localhost";

    // TODO
    return NULL;
}

void XupaNet::on_pushButton_clicked()
{
    QNetworkProxy proxy(QNetworkProxy::HttpProxy, "95.87.239.115", 8080);
    QNetworkProxy::setApplicationProxy(proxy);

    QString str = ui->urlField->text();

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

        /*colocando na thread*/
        QThread *thread = new QThread;



        //faz bind() com a thread +  nosso metodo


        //this->moveToThread(thread);
        connect(thread, SIGNAL(started()), this, SLOT(renderVideo()));

        //conecta o sinal finished pra sair da thread
        connect(this, SIGNAL(renderVideoFinished()), thread, SLOT(quit()));

        // connect(this, SIGNAL(renderVideoFinished()), this, SLOT(deleteLater()));
        //connect(this, SIGNAL(renderVideoFinished()), thread, SLOT(deleteLater()));

        thread->start();

    }

    delete urlhandler;

}

void XupaNet::renderVideo()
{

    QString strurl("file://" + qApp->applicationDirPath() + "/youtubevideo.html");
    QUrl myurl(strurl);
    ui->webView->load(myurl);
    ui->webView->show();
    emit renderVideoFinished();

}

void XupaNet::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void XupaNet::on_action_Exit_triggered()
{
    qApp->closeAllWindows();
}

void XupaNet::on_actionProxy_List_triggered()
{
    proxylist = new ProxyList();
    proxylist->show();
}
