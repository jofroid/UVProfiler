#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "cursus.h"
#include <QMap>
#include <QString>
#include <QtSql>

class CursusManager
{
private:
    QMap<QString, Cursus*> _cursus;
    static CursusManager* _instance;
    CursusManager();
    void load();
public:
    ~CursusManager() {}
    static CursusManager& getInstance();

    Cursus* getCursus(QString& cursus) {return NULL;}
};

#endif // CURSUSMANAGER_H
