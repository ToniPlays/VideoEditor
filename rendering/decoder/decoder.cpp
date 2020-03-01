#include "decoder.h"
#include <QDebug>

Decoder::Decoder()
{

}
void Decoder::DecodeFile(QString file) {
    if(file != currentFile) {
        qDebug() << "File has changed";
        //Open new file
    }
}
