#include "projectmanager.h"
#include <QApplication>
#include <QDebug>

bool ProjectManager::isChanged = true;

void ProjectManager::SaveAndClose() {
    if(ProjectManager::isChanged) {
        Save();
    }
    QApplication::quit();
}
bool ProjectManager::Save() {
    isChanged = false;
    qDebug() << "Project was saved";
    return true;
}
