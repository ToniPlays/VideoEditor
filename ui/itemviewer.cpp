#include "itemviewer.h"
#include <utility/style.h>
#include <ui/flowlayout.h>
#include <QVBoxLayout>

ItemViewer::ItemViewer(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(Style::Panel());
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);
    label = new QLabel(this);
    label->setStyleSheet(Style::Text());
    label->setMargin(4);
    label->setText("");
    layout->addWidget(label);

    QWidget* itemView = new QWidget(this);
    itemView->setStyleSheet(Style::Panel());
    itemView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    layout->addWidget(itemView);
}
void ItemViewer::SetTitleText(QString text) {
    label->setText(text);
}
void ItemViewer::SetText(QString text) {
    SetTitleText(text);
}
