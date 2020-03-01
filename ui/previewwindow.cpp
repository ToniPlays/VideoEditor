#include "previewwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QSlider>

PreviewWindow::PreviewWindow(Sequence* sequence) {

    setMinimumSize(QSize(0, 250));
    setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);"));
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 0, 0, 0);
    QLabel* title = new QLabel(this);
    title->setText(QString::number(sequence->size.width()) + "x" + QString::number(sequence->size.height()));
    title->setMargin(8);
    title->setStyleSheet(QString::fromUtf8("color: #b9b9b9;"));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
    title->setSizePolicy(sizePolicy1);
    vLayout->addWidget(title);

    QWidget* imageContainer = new QWidget(this);
    imageContainer->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QVBoxLayout* imageLayout = new QVBoxLayout();
    imageLayout->setAlignment(Qt::AlignCenter);
    imageContainer->setLayout(imageLayout);

    previewImage = new QLabel(imageContainer);
    previewImage->setText("Image");
    previewImage->setMargin(4);
    previewImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    previewImage->setSizePolicy(sizePolicy1);
    vLayout->addWidget(imageContainer);

    QImage image = QImage(QSize(256, 144), QImage::Format_RGB32);
    image.fill(Qt::black);
    previewImage->setPixmap(QPixmap::fromImage(image));

    QSlider* TimelineBar = new QSlider(this);
    TimelineBar->setOrientation(Qt::Horizontal);

    vLayout->addWidget(TimelineBar);

    this->sequence = sequence;
    ResizeView(sequence->size.width(), sequence->size.height());
}
void PreviewWindow::SetPreviewImage(QImage image) {
    this->previewImage->setPixmap(QPixmap::fromImage(image));
    this->previewImage->setScaledContents(true);
}
void PreviewWindow::resizeEvent(QResizeEvent* event) {
    QSize size = previewImage->parentWidget()->size();
    ResizeView(size.width(), size.height());
}
void PreviewWindow::ResizeView(int w, int h) {
    float ratio = float(w) / float(h);
    float sRatioW = float(sequence->size.width()) / float(sequence->size.height());

    if(ratio >= sRatioW) w = sRatioW * h;
    else {
        float sRatioH = float(sequence->size.height()) / float(sequence->size.width());
        h = sRatioH * w;
    }
    previewImage->resize(w, h);
    QPixmap p = previewImage->pixmap()->copy();
    if(p.isNull() && w > 0 && h > 0) {
        QImage image = QImage(QSize(256, 144), QImage::Format_RGB32);
        image.fill(Qt::black);
        p = QPixmap::fromImage(image);
    }
    previewImage->setPixmap(p.scaled(w, h));
}
