#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "cursus.h"
#include "branche.h"
#include "filiere.h"
#include "postbac.h"
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
    void loadBrancheFromFile();
    void loadFiliereFromFile();
    void loadPostBacFromFile();
    void loadBrancheFromDB(); // Si on rajoute un nouveau cursus, on a juste à rajouter une fonction ici
    void loadFiliereFromDB();
    void loadPostBacFromDB();

    void saveBrancheToFile();
    void saveFiliereToFile();
    void savePostBacToFile();
public:
    ~CursusManager() {}
    static CursusManager& getInstance();
    void save();
    void print();

    Cursus* getCursus(QString& cursus) {return NULL;}
};

#endif // CURSUSMANAGER_H
