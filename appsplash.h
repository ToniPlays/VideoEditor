#ifndef APPSPLASH_H
#define APPSPLASH_H

#include <QMainWindow>

namespace Ui { class AppSplash; }

class AppSplash : public QMainWindow
{
    Q_OBJECT
public:
    AppSplash(QWidget *parent = nullptr);
    ~AppSplash();
    Ui::AppSplash *ui;
private slots:
    void SetProgress(QString text, float progress);
    void LoadApp();
};

#endif // APPSPLASH_H
