#ifndef XUPANET_H
#define XUPANET_H

#include <QMainWindow>
#include <QShortcut>
#include <QWebSettings>
#include "youtubeurlhandler.h"
#include "proxylist.h"

#include <string>

namespace Ui {
    class XupaNet;
}

class XupaNet : public QMainWindow
{
    Q_OBJECT
    
private:
    QShortcut *shortcut;
    ProxyList *proxylist;


public:
    explicit XupaNet(QWidget *parent = 0);
    explicit XupaNet(QString &str);
    ~XupaNet();

    YouTubeUrlHandler *urlhandler;

    QString get_proxy_ws();
    
private slots:
    void on_pushButton_clicked();

    void on_actionAbout_Qt_triggered();

    /*duvidas com as threads?
     *http://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
     */

    //metodo executado em outra thread
    void renderVideo();

    void on_action_Exit_triggered();

    void on_actionProxy_List_triggered();

signals:
    void renderVideoFinished();

private:
    Ui::XupaNet *ui;
};

#endif // XUPANET_H
