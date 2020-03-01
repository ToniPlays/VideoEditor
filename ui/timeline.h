#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <utility/sequence.h>

class Timeline : public QWidget
{
    Q_OBJECT
public:
    explicit Timeline(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    Sequence* sequence;
signals:

};

#endif // TIMELINE_H
