#ifndef ETUDIANTMANAGER_H
#define ETUDIANTMANAGER_H

#include <QMap>
#include <QString>
#include "etudiantdata.h"


class etudiantManager
{
private:
    static etudiantManager* _instance;
    QMap<QString, EtudiantData*> _etudiants;

    etudiantManager();
public:
    etudiantManager& getInstance() {
        if(!_instance)
            _instance = new etudiantManager;
        return *_instance;
    }
};

#endif // ETUDIANTMANAGER_H
