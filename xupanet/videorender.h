#ifndef VIDEORENDER_H
#define VIDEORENDER_H

#include <QObject>
#include <QString>

class VideoRender : public QObject
{
    Q_OBJECT
public:
    explicit VideoRender(QObject *parent = 0);
    
signals:
    void finished();
    void error(QString err);
    
public slots:
    void process();
    
};

#endif // VIDEORENDER_H
