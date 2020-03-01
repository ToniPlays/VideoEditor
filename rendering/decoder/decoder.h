#ifndef DECODER_H
#define DECODER_H

#include <QString>
#include <QRunnable>

class Decoder
{
public:
    Decoder();
    void DecodeFile(QString file);
private:
    bool isStopped;
    QString currentFile;
};

#endif // DECODER_H
