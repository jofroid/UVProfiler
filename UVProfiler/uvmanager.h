#ifndef UVMANAGER_H
#define UVMANAGER_H

/**
  * @file uvmanager.h
  */
#include <QString>
#include <QMap>
#include "uv.h"
#include "cs.h"
#include "tm.h"
#include "tsh.h"
#include "sp.h"
#include <QtSql>

/**
 * @brief The UTProfilerException class Classe d'exception de l'UTProfiler
 */
class UTProfilerException{
public:
    /**
    * @brief UTProfilerException Constructeur de base
    * @param message Message d'erreur
    */
   UTProfilerException(const QString& message):info(message){}
   //Getters
   QString getInfo() const { return info; }
private:
   /**
    * @brief info Message d'erreur
    */
   QString info;
};


/**
 * @brief The typeOuverture enum Choix entre l'utilisation de la DB ou d'un fichier
 */
enum typeOuverture { fichier, DB };

/**
 * @brief The UVManager class Classe representant le manager d'UV
 */
class UVManager {
private:
    UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);
    UVManager();
    ~UVManager();

    /**
     * @brief _file Choix du mode de save/load
     */
    QString _file;
    bool _modification;
    /**
     * @brief _uvs Map des differentes UVs
     */
    QMap<QString, UV*> _uvs;
    /**
     * @brief _ouverture Type de chargement/sauvegarde
     */
    enum typeOuverture _ouverture;

    /**
     * @brief addItem Ajoute une UV au manager
     * @param uv Pointe sur l'UV a rajouter
     */
    void addItem(UV* uv);
    /**
     * @brief saveToDB Sauvegarde la liste d'UV dans la BDD
     */
    void saveToDB() const;
    /**
     * @brief saveToFile Sauvegarde la liste d'UV dans un fichier
     */
    void saveToFile() const;
    /**
     * @brief loadFromDB Charge la liste d'UV depuis la BDD
     */
    void loadFromDB();
    /**
     * @brief loadFromFile Charge la liste d'UV depuis un fichier
     */
    void loadFromFile();
    /**
     * @brief loadFromExample Charge une liste d'UV prédéfinie
     */
    void loadFromExample();

    friend struct Handler;
    /**
     * @brief The Handler struct Structure du handler du manager
     */
    struct Handler{
       UVManager* instance;
       Handler():instance(0){}
       ~Handler(){ if (instance) delete instance; instance=0; }
    };
    /**
     * @brief handler Handler du manager
     */
    static Handler handler;
public:
    /**
     * @brief load Charge les UV dans le manager
     */
    void load(){
        loadFromExample();
        /*if(_ouverture == fichier)
            loadFromFile();
        else if(_ouverture == DB )
            loadFromDB();*/
        }
    /**
     * @brief save Sauvegarde les UV dans le manager
     */
    void save(){
        if(_ouverture == fichier)
            saveToFile();
        else if(_ouverture == DB)
            saveToDB();
        }

    /**
     * @brief libererInstance Libere l'instance du manager
     */
    static void libererInstance();
    /**
     * @brief ajouterUV Ajoute une UV qui n'existe pas encore
     * @param code Code de l'UV
     * @param nom Nom de l'UV
     * @param saison Saison de l'UV
     * @param categorie Categorie de l'UV
     * @param credits Credits donnes par l'UV
     */
    void ajouterUV(const QString& code, const QString& nom, const Saison saison, const QString& categorie, unsigned int credits);
    /**
     * @brief afficherTable Affiche une table de la BDD
     * @param table Table a afficher
     */
    void afficherTable(const QString& table);

    //Setters
    void setOuvertureFichier()          { _ouverture = fichier;  }
    void setOuvertureDB()               { _ouverture = DB;       }

    //Getters
    typeOuverture getOuverture()const   { return _ouverture;     }
    static UVManager& getInstance();
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);

};

#endif // UVMANAGER_H
