#include "uicontroller.h"

MainWindow* UiController::window;

UiController::UiController(MainWindow* window)
{
    this->window = window;
    setFullscreen(true);
}
UiController::~UiController() {
    delete window;
}
void UiController::setTitle(QString text) {
    window->SetTitle(text);
}
void UiController::OpenTab(int tab) {
    window->OpenTab(tab);
}
void UiController::setFullscreen(bool isFullscreen) {
    if(!isFullscreen)
        window->showNormal();
    else window->showMaximized();
}
