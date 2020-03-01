#include "style.h"

QString Style::Text() {
    return QString::fromUtf8("color: #B9B9B9");
}
QString Style::Panel() {
    return QString::fromUtf8("background-color: rgb(35, 35, 35);");
}
QString Style::Background() {
    return QString::fromUtf8("background-color: rgb(22, 22, 22);");
}
