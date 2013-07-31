#include "youtubeurlhandler.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>

YouTubeUrlHandler::YouTubeUrlHandler(QObject *parent) :
    QObject(parent)
{
    qDebug() << "url handler constructor";
}


YouTubeUrlHandler::YouTubeUrlHandler(QString &str)
{
    url_str.append(str);
}

int YouTubeUrlHandler::makeUrl()
{
    mystrl_list = url_str.split(QRegExp("(v=|&)"));
    // qDebug() << "url list:" << mystrl_list.at(0);
    qDebug() << "url list:" << mystrl_list;

    if(!mystrl_list.at(0).contains(QRegExp("youtube.com")))
        return 0;

    else return 1;
}

int YouTubeUrlHandler::makeHtmlFile()
{
    QString htmlContent_before = "<html><head><title>vai..</title></head> <body> indo...<br><br>"
            "<object width=\"1000\" height=\"450\"> <param name=\"movie\" value=\"https://youtube.googleapis.com/v/Ly89ntuVr9U\" />"
            "<param name=\"wmode\" value=\"transparent\" />";

    QString htmlContent_Video = "<embed src=\"https://youtube.googleapis.com/v/" + mystrl_list.at(1) + "\"";

    QString htmlContent_after =   "type=\"application/x-shockwave-flash\""
            "wmode=\"transparent\" width=\"1000\" height=\"450\" />"
            "</object> </body> </html> ";

    QFile file("youtubevideo.html");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    stream << htmlContent_before;
    stream << htmlContent_Video;
    stream << htmlContent_after;
    stream.flush();
    file.close();

    return 1;

}
