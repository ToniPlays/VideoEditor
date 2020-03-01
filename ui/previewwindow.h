#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QLabel>
#include <utility/sequence.h>

class PreviewWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWindow(Sequence* sequence);

private:
    Sequence* sequence;
    QLabel* previewImage;
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void SetPreviewImage(QImage image);
    void ResizeView(int w, int h);
};

#endif // PREVIEWWINDOW_H
