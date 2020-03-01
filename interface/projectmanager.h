#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H


class ProjectManager
{
public:
    static bool isChanged;
    static void SaveAndClose();
    static bool Save();
};

#endif // PROJECTMANAGER_H
