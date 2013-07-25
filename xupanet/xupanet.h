#ifndef XUPANET_H
#define XUPANET_H

#include <QMainWindow>

namespace Ui {
class XupaNet;
}

class XupaNet : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit XupaNet(QWidget *parent = 0);
    ~XupaNet();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::XupaNet *ui;
};

#endif // XUPANET_H
