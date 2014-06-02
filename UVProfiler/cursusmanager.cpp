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
}
