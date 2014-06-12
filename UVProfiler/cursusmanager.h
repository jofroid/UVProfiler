#ifndef CURSUSMANAGER_H
#define CURSUSMANAGER_H

#include "cursus.h"
#include "branche.h"
#include "filiere.h"
#include "postbac.h"
#include <QFile>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QtSql>

class CursusManager
{
private:
    QMap<QString, Branche*> _branche;
    QMap<QString, Filiere*> _filiere;
    QMap<QString, PostBac*> _postBac;
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
    void printBranche();
    void printFiliere();
    void printPostBac();

    void addBranche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires = EnsCredits() );
    void addPostBac(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires = EnsCredits() );

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
