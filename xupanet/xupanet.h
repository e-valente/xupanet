#ifndef XUPANET_H
#define XUPANET_H

#include <QMainWindow>
#include <QShortcut>
#include "youtubeurlhandler.h"

namespace Ui {
class XupaNet;
}

class XupaNet : public QMainWindow
{
    Q_OBJECT
    
private:
    QShortcut *shortcut;
public:
    explicit XupaNet(QWidget *parent = 0);
     explicit XupaNet(QString &str);
    ~XupaNet();

    YouTubeUrlHandler *urlhandler;
    
private slots:
    void on_pushButton_clicked();

    void on_actionAbout_Qt_triggered();

private:
    Ui::XupaNet *ui;
};

#endif // XUPANET_H
