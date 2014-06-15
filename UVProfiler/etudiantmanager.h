#ifndef ETUDIANTMANAGER_H
#define ETUDIANTMANAGER_H

/**
  * @file etudiantmanager.h
  */
#include <QMap>
#include <QString>
#include <QFile>
#include <QSettings>
#include <iostream>
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

    void loadExample();
    /**
     * @brief loadFromFile Charge des etudiants depuis un fichier
     */
    void loadFromFile();
    /**
     * @brief saveToFile Sauvegarde les etudiants dans un fichier
     */
    void saveToFile();
public:
    /**
     * @brief addEtudiant Ajoute un etudiant
     * @param data Etudiant a rajouter
     */
    void addEtudiant( EtudiantData& data) { _etudiants.insert(data.getLogin(), new EtudiantData( data)); }
    /**
     * @brief removeEtudiant Supprime un etudiant
     * @param login Login de l'etudiant a supprimer
     */
    void removeEtudiant( QString login) { _etudiants.remove(login); }
    /**
     * @brief close Ferme le manager
     */
    void close() { EtudiantManager* tmp(_instance); _instance = 0; delete tmp; }

    /*Getters*/
    static EtudiantManager& getInstance() {
        if(!_instance)
            _instance = new EtudiantManager;
        return *_instance;
    }
    EtudiantData& getEtudiant(QString login); // retourne un étudiant dont les champs sont vides en cas d'échec
    void printEtudiant();
};

#endif // ETUDIANTMANAGER_H
