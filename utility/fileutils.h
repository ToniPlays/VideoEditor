#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QDir>

class FileUtils
{
public:
    static void SetDefaultPath(QString path);
    static void SetFilters(QString filter);
    static bool OpenFile(QString &path);
    static bool OpenFiles(QString &path);
    static bool OpenDirectory(QString &path);
    static bool SaveFile(QString &path);
private:
    static QString defaultPath;
    static QString filter;
};

#endif // FILEUTILS_H
