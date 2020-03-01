#include "timeline.h"
#include <QVBoxLayout>
#include <QScrollBar>
#include <QDebug>
#include <QStyle>
#include <QScrollArea>
#include <QSplitter>

Timeline::Timeline(QWidget *parent) : QWidget(parent)
{
    setObjectName(QString::fromUtf8("timeline"));
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);"));
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setObjectName(QString::fromUtf8("verticalLayout_5"));
    layout->setContentsMargins(0, 0, 0, 0);

    QScrollArea* sequenceContainer = new QScrollArea(this);
    sequenceContainer->setFrameStyle(QFrame::NoFrame);
    sequenceContainer->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    QSplitter* splitter = new QSplitter(sequenceContainer);
    splitter->setLineWidth(4);
    splitter->setOrientation(Qt::Horizontal);
    splitter->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    splitter->setStyleSheet(QString::fromUtf8("background-color: rgb(22, 22, 22);"));

    QWidget* layerInfo = new QWidget(splitter);
    layerInfo->setMinimumSize(QSize(300, 250));
    layerInfo->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    layerInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);"));

    splitter->addWidget(layerInfo);

    QWidget* layers = new QWidget(splitter);
    layers->setMinimumSize(QSize(300, 250));
    layers->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    layers->setStyleSheet(QString::fromUtf8("background-color: rgb(35, 35, 35);"));

    splitter->addWidget(layers);

    sequenceContainer->setWidgetResizable(true);
    sequenceContainer->setWidget(splitter);
    layout->addWidget(sequenceContainer);

    QScrollBar* horizontalScrollBar = new QScrollBar(this);
    horizontalScrollBar->setOrientation(Qt::Horizontal);
    horizontalScrollBar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    layout->addWidget(horizontalScrollBar, Qt::AlignBottom);
    this->sequence = new Sequence(1920, 1080);
}
void Timeline::paintEvent(QPaintEvent *event) {
    this->style()->polish(this);
}

