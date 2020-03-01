#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDebug>
#include <utility/fileutils.h>
#include <ui/uicontroller.h>
#include <interface/projectmanager.h>
#include <ui/timeline.h>
#include <ui/previewwindow.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    new UiController(this);

    Timeline* timeline = new Timeline(nullptr);
    ui->splitter_3->addWidget(timeline);
    PreviewWindow* previewWindow = new PreviewWindow(timeline->sequence);
    ui->splitter->addWidget(previewWindow);
    SetTitle("Ready");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::SetTitle(QString text) {
    this->setWindowTitle(text + " - IntelliVideo");
}
void MainWindow::OpenTab(int tab) {
    ui->StackView->setCurrentIndex(tab);
}

void MainWindow::on_actionFile_triggered()
{
    QString path;
    if(!FileUtils::OpenFile(path)) return;
    qDebug() << "End is here";
}

void MainWindow::on_actionNew_triggered()
{
    QString path;
    if(!FileUtils::OpenFile(path)) return;
    qDebug() << "End is here";
}

void MainWindow::on_AssemblyBtn_clicked() { OpenTab(0); }
void MainWindow::on_TimelineBtn_clicked() { OpenTab(1); }
void MainWindow::on_RenderBtn_clicked() { OpenTab(2); }
void MainWindow::on_ConsoleBtn_clicked() { OpenTab(3); }

void MainWindow::on_actionExit_triggered()
{
    ProjectManager::SaveAndClose();
}
