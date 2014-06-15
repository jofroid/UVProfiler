#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

/**
  * @file cursusmanaher.h
  */
#include "cursus.h"
#include "branche.h"
#include "filiere.h"
#include "postbac.h"
#include <QFile>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QtSql>

/**
 * @brief The CursusManager class Classe representant le manager de cursus
 */
class CursusManager
{
private:
    /**
     * @brief _branche Map de l'ensemble des cursus de type branche
     */
    QMap<QString, Branche*> _branche;
    /**
     * @brief _filiere Map de l'ensemble des cursus de type filiere
     */
    QMap<QString, Filiere*> _filiere;
    /**
     * @brief _postBac Map de l'ensemble des cursus de type postBac
     */
    QMap<QString, PostBac*> _postBac;
    /**
     * @brief _instance Instance de l'objet unique CursusManager
     */
    static CursusManager* _instance;
    /**
     * @brief CursusManager Constructeur qui charge l'ensemble des Cursus dans le manager
     */
    CursusManager();
    /**
     * @brief loadBrancheFromFile Charge les branches dans le manager par un fichier
     */
    void loadBrancheFromFile();
    /**
     * @brief loadFiliereFromFile Charge les filieres dans le manager par un fichier
     */
    void loadFiliereFromFile();
    /**
     * @brief loadPostBacFromFile Charge les cursus postbac dans le manager par un fichier
     */
    void loadPostBacFromFile();
    /**
     * @brief loadBrancheFromDB Charge les branches dans le manager par BDD
     */
    void loadBrancheFromDB(); // Si on rajoute un nouveau cursus, on a juste à rajouter une fonction ici
    /**
     * @brief loadFiliereFromDB Charge les filieres dans le manager par BDD
     */
    void loadFiliereFromDB();
    /**
     * @brief loadPostBacFromDB Charge les cursus postbac dans le manager par BDD
     */
    void loadPostBacFromDB();
    /**
     * @brief saveBrancheToFile Sauvegarde les branches du manager dans un fichier
     */
    void saveBrancheToFile();
    /**
     * @brief saveFiliereToFile Sauvegarde les filieres du manager dans un fichier
     */
    void saveFiliereToFile();
    /**
     * @brief savePostBacToFile Sauvegarde les cursus postbac du manager dans un fichier
     */
    void savePostBacToFile();
public:
    ~CursusManager() {}
    /**
     * @brief getInstance Cree une instance unique de CursusManager
     * @return _instance
     */
    static CursusManager& getInstance();
    /**
     * @brief save Sauvegarde l'ensemble des cursus dans le manager soit par fichier, soit par BDD
     */
    void save();
    /**
     * @brief load Charge l'ensemble des cursus dans le manager soit par fichier, soit par BDD
     */
    void load();
    /**
     * @brief printBranche Affiche les branches
     */
    void printBranche();
    /**
     * @brief printFiliere Affiche les filieres
     */
    void printFiliere();
    /**
     * @brief printPostBac Affiche les cursus postbac
     */
    void printPostBac();
    /**
     * @brief addBranche Ajoute une branche au le manager
     * @param nom Nom de la branche
     * @param code Code de la branche
     * @param description Description de la branche
     * @param creditsNecessaires Nombre de credits necessaire a la validation de la branche
     */
    void addBranche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires = EnsCredits() );
    /**
     * @brief addFiliere Ajoute une branche au le manager
     * @param nom Nom de la filiere
     * @param code Code de la filiere
     * @param description Description de la filiere
     * @param creditsNecessaires Nombre de credits necessaire a la validation de la filiere
     */
    void addFiliere(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires = EnsCredits() );
    /**
     * @brief addPostBac Ajoute un cursus post-BAC au le manager
     * @param nom Nom du postbac
     * @param code Code du postbac
     * @param description Description du postbac
     * @param creditsNecessaires Nombre de credits necessaire a la validation du postbac
     */
    void addPostBac(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires = EnsCredits() );

    /*Getters*/
    Branche* getBranche(QString& branche) {
        if(_branche.contains(branche) )
            return _branche[branche]; }
    Filiere* getFiliere(QString& filiere) {
        if(_filiere.contains(filiere) )
            return _filiere[filiere]; }
    PostBac* getPostBac(QString& postBac) {
        if(_postBac.contains(postBac) )
            return _postBac[postBac]; }
};

#endif // CURSUSMANAGER_H
