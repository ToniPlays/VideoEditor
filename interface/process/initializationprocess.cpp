#include "initializationprocess.h"
#include <QDebug>
#include <QThread>

InitializationProcess::InitializationProcess()
{
    qDebug() << "System threads " << thread()->idealThreadCount();
}
void InitializationProcess::run() {
    QStringList items (QStringList() << "Effects" << "Transitions" << "Algorithms" << "Renderer" << "Audio" << "Interface" << "Finishing");

    for(int i = 0; i < items.length(); i++) {
        emit Progress(items[i], float(i) / float(items.length()));
        thread()->msleep(300);
    }

    emit Progress("Main", 1);
    emit onReady();
}
