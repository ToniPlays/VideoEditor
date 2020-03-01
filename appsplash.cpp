#include "appsplash.h"
#include <ui_AppSplash.h>
#include <mainwindow.h>
#include <QDebug>

AppSplash::AppSplash(QWidget *parent) : QMainWindow(parent), ui(new Ui::AppSplash)
{
    ui->setupUi(this);
}
AppSplash::~AppSplash()
{
    delete ui;
}
void AppSplash::SetProgress(QString text, float progress) {
    ui->progress->setText(QString::number(int(progress * 100)) + "% Loading " + text);
}
void AppSplash::LoadApp() {
    MainWindow* mainWin = new MainWindow();
    mainWin->show();
    this->close();
}
