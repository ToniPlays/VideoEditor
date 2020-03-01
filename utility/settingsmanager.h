#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H
#include <QString>


class SettingsManager
{
public:
    SettingsManager();
    static QString getValue(QString key);
};

#endif // SETTINGSMANAGER_H
