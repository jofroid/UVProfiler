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

/**
 * @brief The Etudiant class Represente un etudiant UTC
 */
class Etudiant : public EtudiantData
{
private:
    /**
     * @brief _dossier Map des dossiers lies a l'etudiant
     */
    QMap<QString, Dossier*> _dossier;
    /**
     * @brief _instance Instance unique de l'etudiant utilisateur en cours
     */
    static Etudiant* _instance;
    /**
     * @brief Etudiant Constructeur de base
     * @param username login de l'etudiant
     * @param nom Nom de l'etudiant
     * @param prenom Prenom de l'etudiant
     */
    Etudiant(QString username, QString nom, QString prenom);
public:
    ~Etudiant();
    /**
     * @brief createAccount Cree un compte etudiant
     * @param username login de l'etudiant
     * @param nom Nom de l'etudiant
     * @param prenom Prenom de l'etudiant
     * @return L'instance unique de l'etudiant
     */
    static Etudiant& createAccount(QString username, QString nom, QString prenom);
    /**
     * @brief login Connecte un etudiant
     * @param username login de l'etudiant
     * @return L'instance unique de l'etudiant
     */
    static Etudiant& login(QString username);
    /**
     * @brief logout Deconnecte un etudiant
     * @return true si la deconnection a fonctionne, false sinon
     */
    static bool logout();

    /*Getters*/
    static Etudiant& getInstance();
};

#endif // ETUDIANT_H
