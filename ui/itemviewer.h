#ifndef VIDEOVIEWER_H
#define VIDEOVIEWER_H

#include <QWidget>
#include <QLabel>

class ItemViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ItemViewer(QWidget *parent = nullptr);
    void SetTitleText(QString text);

private:
    QLabel* label;
private slots:
    void SetText(QString text);
};

#endif // VIDEOVIEWER_H
