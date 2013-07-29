#include "videorender.h"
#include <QDebug>
VideoRender::VideoRender(QObject *parent) :
    QObject(parent)
{
    /*nao alocar nada na heap (i.e utilizando "new")  aqui
     *pois os recursos ficarao alocados na thread principal
     *Dúvidas? http://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
     */
}

void VideoRender::process()
{
    qDebug() << "process\n";
    emit finished();

}

