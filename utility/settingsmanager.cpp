#include "settingsmanager.h"

SettingsManager::SettingsManager()
{

}
QString SettingsManager::getValue(QString key) {
    return "No settings here for " + key;
}
