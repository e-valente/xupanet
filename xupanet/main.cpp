#include "xupanet.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    int screenWidth, screenHeight;
    int w, h;
    int x, y;

    QApplication a(argc, argv);
    XupaNet window;
    QDesktopWidget *desktop = QApplication::desktop();

    screenHeight = desktop->height();
    screenWidth = desktop->width();

   // qDebug() <<"dimensoes: altura: " << screenHeight << "largura: " << screenWidth;

    // Para nao ficar uma janela grande e tosca
    w = 1000;
    h = 700;

    y = (screenHeight - h)/2;
    x = (screenWidth - w) /2;

    window.resize(w, h);
    window.move(x, y);

    window.show();
    
    return a.exec();
}
