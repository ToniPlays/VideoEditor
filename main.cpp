#include "appsplash.h"
#include <QApplication>
#include <interface/process/initializationprocess.h>
#include <QThreadPool>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppSplash splashScreen;
    splashScreen.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    splashScreen.show();

    InitializationProcess* process = new InitializationProcess();
    splashScreen.connect(process, SIGNAL(Progress(QString, float)), SLOT(SetProgress(QString, float)));
    splashScreen.connect(process, SIGNAL(onReady()), SLOT(LoadApp()));
    QThreadPool::globalInstance()->start(process);
    return a.exec();
}
