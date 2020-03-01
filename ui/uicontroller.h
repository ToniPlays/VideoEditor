#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include <mainwindow.h>

class UiController : public QObject
{
    Q_OBJECT
public:
    UiController(MainWindow* window);
    ~UiController();
    static void setTitle(QString text);
    static void OpenTab(int tab);
private:
    static MainWindow* window;
    static void setFullscreen(bool isFullscreen);
};

#endif // UICONTROLLER_H
