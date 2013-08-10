#include "proxylist.h"
#include "ui_proxylist.h"

#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QIODevice>
#include <QUrl>
#include <QString>
#include <QStringList>


void WSConsumer::onFinished()
{
        qDebug() << "FOOBAR";
        QStringList list;
        QIODevice * content = static_cast<QIODevice*>(QObject::sender());
        QString response = content->readAll();
        response = response.split(QRegExp("</*html>"))[1];
        list = response.split(QRegExp(":"));
        
        this->ip_addr =  list[0];
        this->port_addr = list[1].remove('\n'); 
        content->deleteLater();
}

ProxyList::ProxyList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProxyList)
{
    ui->setupUi(this);
}

ProxyList::~ProxyList()
{
    delete ui;
}

void ProxyList::on_pushButtonSetDefaultProxies_clicked()
{
    ui->lineEditProxy1->setText("95.87.239.115");
    ui->lineEditPort1->setText("8080");

    ui->lineEditProxy2->setText("218.25.249.188");
    ui->lineEditPort2->setText("81");

    ui->lineEditProxy3->setText("222.29.45.27");
    ui->lineEditPort3->setText("1080");

    ui->lineEditProxy4->setText("109.207.61.206");
    ui->lineEditPort4->setText("8090");

    ui->lineEditProxy5->setText("177.206.131.63");
    ui->lineEditPort5->setText("3128");
}


void ProxyList::on_pushButtonSynchronizeProxies_clicked()
{
    //TODO
    //-> sync with our webservice [ok]
    //-> and update lineEdits     [  ]

    QNetworkAccessManager nam;
    WSConsumer obj;
    QNetworkReply * reply = nam.get(
            QNetworkRequest(QUrl("http://localhost:8080/proxy"))
    );

    QObject::connect(reply, SIGNAL(finished()), &obj, SLOT(onFinished()));
    
    qDebug() << obj.ip_addr;
    qDebug() << obj.port_addr;
}
