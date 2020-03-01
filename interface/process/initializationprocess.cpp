#include "initializationprocess.h"
#include <QDebug>
#include <QThread>

InitializationProcess::InitializationProcess()
{
    qDebug() << "System threads " << thread()->idealThreadCount();
}
void InitializationProcess::run() {
    QStringList items (QStringList() << "Initializing" << "Effects" << "Transitions" << "Algorithms" <<
                       "Renderer" << "Audio" << "Interface" << "Finishing");
    int j = 0;
    for(int i = 0; i < items.length(); i++) {
        while(j <= i * float(100) / float(items.length() - 1)) {
            emit Progress(items[i], float(j) / float(100));
            thread()->msleep(25);
            j++;
        }
    }

    emit Progress("Main", 1);
    emit onReady();
}
