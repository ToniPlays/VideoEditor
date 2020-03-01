#include "fileutils.h"
#include <QFileDialog>
#include <QDebug>
#include <ui/uicontroller.h>

QString FileUtils::defaultPath;
QString FileUtils::filter;

void FileUtils::SetDefaultPath(QString path)
{
    FileUtils::defaultPath = path;
}
void FileUtils::SetFilters(QString filter) {
    FileUtils::filter = filter;
}
bool FileUtils::OpenFile(QString &path) {
    UiController::setTitle("Open file");
    QString file = QFileDialog::getOpenFileName(nullptr, "Open file");
    return file != "";
}
bool FileUtils::OpenFiles(QString &path) {
    UiController::setTitle("Open files");
    return true;
}
bool FileUtils::OpenDirectory(QString &path) {
    UiController::setTitle("Open directory");
    return true;
}
bool FileUtils::SaveFile(QString &path) {
    UiController::setTitle("Save file");
    QString file = QFileDialog::getSaveFileName(nullptr, "Save");
    return true;
}
