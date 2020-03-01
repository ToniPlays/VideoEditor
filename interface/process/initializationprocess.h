#ifndef INITIALIZATIONPROCESS_H
#define INITIALIZATIONPROCESS_H

#include <QObject>
#include <QRunnable>

class InitializationProcess : public QObject, public QRunnable
{
    Q_OBJECT
public:
    InitializationProcess();
    void run() override;
signals:
    void onReady();
    void Progress(QString text, float progress);
};

#endif // INITIALIZATIONPROCESS_H
