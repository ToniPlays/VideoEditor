#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetTitle(QString text);
    void OpenTab(int tab);

private slots:
    void on_actionFile_triggered();

    void on_actionNew_triggered();

    void on_AssemblyBtn_clicked();

    void on_TimelineBtn_clicked();

    void on_RenderBtn_clicked();

    void on_ConsoleBtn_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
