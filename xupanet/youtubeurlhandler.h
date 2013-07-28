#ifndef YOUTUBEURLHANDLER_H
#define YOUTUBEURLHANDLER_H

#include <QObject>
#include <QString>
#include <QStringList>

class YouTubeUrlHandler : public QObject
{
    Q_OBJECT


private:
    QString url_str;
    QStringList mystrl_list;


public:
    explicit YouTubeUrlHandler(QObject *parent = 0);
    explicit YouTubeUrlHandler(QString &str);

    int makeUrl();
    int makeHtmlFile();

    
signals:
    
public slots:
    
};

#endif // YOUTUBEURLHANDLER_H
