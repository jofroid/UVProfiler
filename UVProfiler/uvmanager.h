#ifndef UVMANAGER_H
#define UVMANAGER_H

#include <QString>
#include <QMap>
#include "uv.h"
#include "cs.h"
#include "tm.h"
#include "tsh.h"
#include "sp.h"
#include <QtSql>

class UTProfilerException{
public:
   UTProfilerException(const QString& message):info(message){}
   QString getInfo() const { return info; }
private:
   QString info;
};

enum typeOuverture { fichier, DB };

class UVManager {
private:
    UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);
    UVManager();
    ~UVManager();

    QMap<QString, UV*> _uvs;
    QString _file;
    enum typeOuverture _ouverture;
    bool _modification;

    void addItem(UV* uv);
    void saveToDB() const;
    void saveToFile() const;
    void loadFromDB();
    void loadFromFile();

    friend struct Handler;
    struct Handler{
       UVManager* instance;
       Handler():instance(0){}
       ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;
public:
    void load(){
        if(_ouverture == fichier)
            loadFromFile();
        else if(_ouverture == DB )
            loadFromDB();
        }
    void save(){
        if(_ouverture == fichier)
            saveToFile();
        else if(_ouverture == DB)
            saveToDB();
        }

    //       Setters
    // QMap<QString, UV*> _uvs;
    // unsigned int _nbUV;
    // unsigned int _nbMaxUV;
    // QString _file;
    // enum typeOuverture _ouverture;

    typeOuverture getOuverture()const   { return _ouverture;     }
    void setOuvertureFichier()          { _ouverture = fichier;  }
    void setOuvertureDB()               { _ouverture = DB;       }

    static UVManager& getInstance();
    static void libererInstance();
    void ajouterUV(const QString& code, const QString& nom, const Saison saison, const QString& categorie, unsigned int credits);
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);
    void afficherTable(const QString& table);
};

#endif // UVMANAGER_H
