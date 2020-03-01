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
    path = file;
    UiController::setTitle("Ready");
    return file != "";
}
bool FileUtils::OpenFiles(QStringList &files) {
    UiController::setTitle("Open files");
    QStringList f = QFileDialog::getOpenFileNames(nullptr, "Open files");
    files = f;
    UiController::setTitle("Ready");

    return f.length() > 0;
}
bool FileUtils::OpenDirectory(QString &path) {
    UiController::setTitle("Open directory");
    QString file = QFileDialog::getExistingDirectory(nullptr, "Open directory");
    path = file;
    UiController::setTitle("Ready");
    return true;
}
bool FileUtils::SaveFile(QString &path) {
    UiController::setTitle("Save file");
    QString file = QFileDialog::getSaveFileName(nullptr, "Save");
    return true;
}
