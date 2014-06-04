#include "cursusmanager.h"

CursusManager* CursusManager::_instance(0);

CursusManager::CursusManager() {
    load();
}

CursusManager& CursusManager::getInstance() {
    if(_instance)
        return *_instance;
    _instance = new CursusManager();
    return *_instance;
}

void CursusManager::load() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.exec("DROP TABLE cursus");
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
    db.close();

    loadBranche();
    loadFiliere();
    loadPostBac();
}

void CursusManager::loadBranche() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.exec("DROP TABLE branche");
    result.exec("CREATE TABLE IF NOT EXISTS branche (" \
                    "code           CHAR(10) PRIMARY KEY NOT NULL REFERENCES cursus(code)," \
                    "creditPCBNecessaire INT             NOT NULL);");

    QString query("SELECT c.code, c.nom, c.description, c.saison, c.CS, c.TM, c.TSH, c.SP, b. creditPCBNecessaire\
                  FROM cursus c, branche b\
                  WHERE c.code = b.code")

    if(! result.exec(qery))
            qDebug() << result.lastError();
    else{
        qDebug( "Chargement des branches" );
        QSqlRecord rec(result.record() );
        int colonnes = rec.count();

        for(int c(0); c<colonnes; c++) {

        }
    }
}

void CursusManager::loadFiliere() {
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

    QString query("SELECT * FROM ")

    if(! result.exec(qery))
            qDebug() << result.lastError();
    else{
        qDebug( "Chargement des branches" );
        QSqlRecord rec(result.record() );
        int colonnes = rec.count();

        for(int c(0); c<colonnes; c++) {

        }
    }
}

void CursusManager::loadPostBac()
