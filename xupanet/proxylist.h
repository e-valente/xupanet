#ifndef PROXYLIST_H
#define PROXYLIST_H

#include <QtNetwork/QNetworkAccessManager>
#include <QWidget>

namespace Ui {
    class ProxyList;
    class WSConsumer;
}

class WSConsumer : public QObject
{
    Q_OBJECT

public:

    WSConsumer(QObject *parent = 0);
    ~WSConsumer();

    QNetworkAccessManager nam;
    QString ip_addr;
    QString port_addr; 

public slots:
    void onFinished();
};

class ProxyList : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProxyList(QWidget *parent = 0);
    ~ProxyList();
    
private slots:
    
    void on_pushButtonSetDefaultProxies_clicked();
    void on_pushButtonSynchronizeProxies_clicked();

private:
    
    WSConsumer* ws_obj;
    Ui::ProxyList* ui;

};

#endif // PROXYLIST_H
