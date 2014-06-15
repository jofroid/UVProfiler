#ifndef ETUDIANTMANAGER_H
#define ETUDIANTMANAGER_H

/**
  * @file etudiantmanager.h
  */
#include <QMap>
#include <QString>
#include <QFile>
#include <QSettings>
#include "etudiantdata.h"

/**
 * @brief The etudiantManager class Classe representant le manager d'etudiants
 */
class EtudiantManager
{
private:
    /**
     * @brief _instance Instance de etudiantManager
     */
    static EtudiantManager* _instance;
    /**
     * @brief _etudiants Map des differents etudiants
     */
    QMap<QString, EtudiantData*> _etudiants;
    /**
     * @brief etudiantManager Constructeur de base
     */
    EtudiantManager();
    ~EtudiantManager();

    void loadFromFile();
    void saveToFile();
public:

    void addEtudiant( EtudiantData& data) { _etudiants.insert(data.getLogin(), new EtudiantData( data)); }
    void removeEtudiant( QString login) { _etudiants.remove(login); }

    /*Getters*/
    static EtudiantManager& getInstance() {
        if(!_instance)
            _instance = new EtudiantManager;
        return *_instance;
    }

    EtudiantData& getEtudiant(QString login); // retourne un étudiant dont les champs sont vides en cas d'échec
};

#endif // ETUDIANTMANAGER_H
