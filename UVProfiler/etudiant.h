#ifndef ETUDIANT_H
#define ETUDIANT_H

/**
  * @file etudiant.h
  */
#include <QString>
#include <QMap>
#include <QtSql>
#include "UVProfiler.h"
#include "dossier.h"
#include "etudiantdata.h"
#include "etudiantmanager.h"

/**
 * @brief The Etudiant class Represente un etudiant UTC
 */
class Etudiant : public EtudiantData
{
private:
    /**
     * @brief _dossier Map des dossiers lies a l'etudiant
     */
    Dossier* _dossier;
    /**
     * @brief _instance Instance unique de l'etudiant utilisateur en cours
     */
    static Etudiant* _instance;

    Etudiant(const EtudiantData& data);
    void loadDossier();
    void loadDossierFromFile();
    void loadDossierFromDB();
public:
    ~Etudiant();
    /**
     * @brief createAccount Cree un compte etudiant
     * @param login login de l'etudiant
     * @param nom Nom de l'etudiant
     * @param prenom Prenom de l'etudiant
     * @return L'instance unique de l'etudiant
     */
    static Etudiant& createAccount(QString login, QString nom, QString prenom);
    /**
     * @brief login Connecte un etudiant
     * @param username login de l'etudiant
     * @return L'instance unique de l'etudiant
     */
    static Etudiant& login(QString username);
    /**
     * @brief logout Deconnecte un etudiant
     */
    static void logout();

    /*Getters*/
    static Etudiant& getInstance();

    void setDossier(Dossier* dossier) { _dossier=dossier; }
    Dossier* getDossier() { return _dossier; }
};

#endif // ETUDIANT_H
