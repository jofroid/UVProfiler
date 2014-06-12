#include "cursusmanager.h"

CursusManager* CursusManager::_instance(0);

CursusManager::CursusManager() {
    EnsCredits::initEnsCreditsSystem();
    load();
}
CursusManager& CursusManager::getInstance() {
    if(_instance)
        return *_instance;
    _instance = new CursusManager();
    return *_instance;
}
void CursusManager::printBranche() {
    QMap<QString, Branche*>::const_iterator it;
    for(it = _branche.constBegin(); it!=_branche.constEnd(); ++it)
        std::cout<<"Branche "<<it.value()->getNom().toStdString()<<" présente\n";
    // L'operateur de flux n'étant pas défini sur QString, je converti le nom en std::string
}
void CursusManager::printFiliere() {
    QMap<QString, Filiere*>::const_iterator it;
    for(it = _filiere.constBegin(); it!=_filiere.constEnd(); ++it)
        std::cout<<"Filiere "<<it.value()->getNom().toStdString()<<" présente\n";
    // L'operateur de flux n'étant pas défini sur QString, je converti le nom en std::string
}
void CursusManager::printPostBac() {
    QMap<QString, PostBac*>::const_iterator it;
    for(it = _postBac.constBegin(); it!=_postBac.constEnd(); ++it)
        std::cout<<"PostBac "<<it.value()->getNom().toStdString()<<" présent\n";
    // L'operateur de flux n'étant pas défini sur QString, je converti le nom en std::string
}

// ----------------------------------
// -        ADD CURSUS
// ----------------------------------

void CursusManager::addBranche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires) {
    _branche.insert(code, new Branche(nom, code, description, creditsNecessaires) );
}

void CursusManager::addPostBac(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires ) {
    _postBac.insert(code, new PostBac(nom, code, description, creditsNecessaires) );
}


// ----------------------------------
// -        LOAD CURSUS
// ----------------------------------

void CursusManager::load() {
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    //result.exec("DROP TABLE cursus;");
    result.exec("CREATE TABLE IF NOT EXISTS cursus (" \
                    "code           CHAR(10) PRIMARY KEY NOT NULL," \
                    "nom            TEXT                 NOT NULL," \
                    "description    CHAR(5)              NOT NULL," \
                    "SAISON         CHAR(2)              NOT NULL," \
                    "CS             INT                          ," \
                    "TM             INT                          ," \
                    "TSH            INT                          ," \
                    "SP             INT                          );");
    db.commit();
    db.close(); */

    loadBrancheFromFile();
    loadFiliereFromFile();
    loadPostBacFromFile();
}

void CursusManager::loadBrancheFromFile() {
    if( !_branche.isEmpty() ) {
        qDeleteAll(_branche);  // Supprime toutes les branches contenu dans _branche avec des delete :D
        _branche.clear();      // vide la QMap
    }

    QSettings fichier("Cursus.ini", QSettings::IniFormat);

    fichier.beginGroup("Branche"); // Lit uniquement la partie concernant les branches
    const QStringList childKeys = fichier.childKeys(); // Obtient la liste des clés
    foreach (const QString& childKey, childKeys) {
        Branche* branche = new Branche(fichier.value(childKey, QVariant::fromValue(Branche() )).value<Branche>() );
        _branche.insert(branche->getNom(), branche);
    }
    fichier.endGroup(); //*/
}

void CursusManager::loadFiliereFromFile() { /*
    if( !_cursus.isEmpty() ) {
        qDeleteAll(_cursus);  // Supprime tous les cursus contenu dans _cursus avec des delete :D
        _cursus.clear();      // vide la QMap
    }

    QSettings fichier("Cursus.ini", QSettings::IniFormat);

    fichier.beginGroup("Filiere"); // Lit uniquement la partie concernant les branches
    const QStringList childKeys = fichier.childKeys(); // Obtient la liste des clés
    foreach (const QString& childKey, childKeys) {
        Cursus* filiere = new Filiere(fichier.value(childKey, QVariant::fromValue(Filiere() )).value<Filiere>() );
        _cursus.insert(branche->getNom(), filiere);
    }
    fichier.endGroup(); //*/
}

void CursusManager::loadPostBacFromFile() {

}

void CursusManager::loadBrancheFromDB() { /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open() )
        std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    //result.exec("DROP TABLE branche;");
    result.exec("CREATE TABLE IF NOT EXISTS branche (" \
                    "code                CHAR(10) PRIMARY KEY NOT NULL REFERENCES cursus(code)," \
                    "creditPCBNecessaire INT                  NOT NULL);");

    QString query("SELECT c.code, c.nom, c.description, c.saison, c.CS, c.TM, c.TSH, c.SP, b.creditPCBNecessaire\
                  FROM cursus c, branche b\
                  WHERE c.code = b.code");

    if(! result.exec(query))
            qDebug() << result.lastError();
    else{
        qDebug("Chargement des branches" );
        QSqlRecord rec(result.record() );
        //int colonnes = rec.count();

        for(int row(0); result.next(); row++) {
            //Branche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0 )

            //EnsCredits(unsigned int CS=0, unsigned int TM=0, unsigned int TSH=0, unsigned int SP=0)
            EnsCredits credit(result.value(5).toInt(), result.value(6).toInt(), result.value(7).toInt(),\
                              result.value(8).toInt());
            Branche* branche= new Branche(result.value(1).toString(), result.value(0).toString(), result.value(2).toString(), credit);
            _branche.insert(result.value(1).toString(), branche);
        }
    }


    db.commit();
    db.close(); //*/
}

void CursusManager::loadFiliereFromDB() { /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.exec("DROP TABLE filiere");
    result.exec("CREATE TABLE IF NOT EXISTS filiere (" \
                    "code           CHAR(10) PRIMARY KEY NOT NULL REFERENCES cursus(code),"
                    "branche           CHAR(10) NOT NULL REFERENCES branche(code),"
                    "creditPCFNecessaire INT             NOT NULL);");

    QString query("SELECT * FROM filiere");

    if(! result.exec(query))
            qDebug() << result.lastError();
    else{
        qDebug( "Chargement des branches" );
        QSqlRecord rec(result.record() );
        int colonnes = rec.count();

        for(int c(0); c<colonnes; c++) {

        }
    }

    db.commit();
    db.close();*/
}

void CursusManager::loadPostBacFromDB() {

}


// ----------------------------------
// -         SAVE CURSUS
// ----------------------------------

void CursusManager::save() {
    saveBrancheToFile();
    saveFiliereToFile();
    savePostBacToFile();
}

void CursusManager::saveBrancheToFile() {
    QSettings fichier("Cursus.ini", QSettings::IniFormat);

    fichier.beginGroup("Branche");
    QMap<QString, Branche*>::const_iterator it;
    for(it = _branche.constBegin(); it!=_branche.constEnd(); ++it) {
        fichier.setValue(it.value()->getNom(), QVariant::fromValue( *it.value() ));
    }
    fichier.endGroup();
    fichier.sync(); //*/

    std::cout<<"Save complete !\n";
}

void CursusManager::saveFiliereToFile() {

}

void CursusManager::savePostBacToFile() {

}

