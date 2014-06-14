#ifndef ETUDIANTMANAGER_H
#define ETUDIANTMANAGER_H

/**
  * @file etudiantmanager.h
  */
#include <QMap>
#include <QString>
#include "etudiantdata.h"

/**
 * @brief The etudiantManager class Classe representant le manager d'etudiants
 */
class etudiantManager
{
private:
    /**
     * @brief _instance Instance de etudiantManager
     */
    static etudiantManager* _instance;
    /**
     * @brief _etudiants Map des differents etudiants
     */
    QMap<QString, EtudiantData*> _etudiants;
    /**
     * @brief etudiantManager Constructer de base
     */
    etudiantManager();
public:
    /*Getters*/
    etudiantManager& getInstance() {
        if(!_instance)
            _instance = new etudiantManager;
        return *_instance;
    }
};

#endif // ETUDIANTMANAGER_H
