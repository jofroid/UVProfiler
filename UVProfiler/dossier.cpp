#include "dossier.h"

Dossier::Dossier(QString username) : _login(username) {
    load();
}


// ----------------------------------
// -        LOAD DOSSIER
// ----------------------------------

void Dossier::load() {
    loadFromFile();
}

void Dossier::loadFromDB() { // Non fonctionnel ...
    /*     int _semestrePB; // semestre Post-Bac
    int _semestreB;  // semestre Branche
    QString _login;
    PostBac* _postBac;
    Branche* _branche;
    Filiere* _filiere;
    Filiere* _mineur;
    QMap<QString, Inscription*> _inscriptions;
    */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.exec("DROP TABLE dossier");
    result.exec("CREATE TABLE IF NOT EXISTS dossier (" \
                    "username       VARCHAR PRIMARY KEY NOT NULL," \
                    "semestrePB     VARCHAR                     ," \
                    "semestreB      VARCHAR                     ," \
                    "PostBac        VARCHAR                     ," \
                    "Branche        VARCHAR                     ," \
                    "Filiere        VARCHAR                     ," \
                    "Mineur         VARCHAR                    );");

    QString query = "SELECT semestrePB, semestreB, PostBac, Branche, Filiere, Mineur FROM dossier WHERE username='"+_login+"';";
    if(result.exec(query) )
    {   // Donc si l'utilisateur est dans la table, on va charger toutes les infos du dossier
        _semestrePB=(result.value("semestrePB ")).toInt();
        _semestreB =(result.value("semestreB  ")).toInt();
        /*_postBac   =CursusManager::getInstance.getCursus((result.value("postBac    ")).toString() );
        _branche   =CursusManager::getInstance.getCursus((result.value("branche    ")).toString() );
        _filiere   =CursusManager::getInstance.getCursus((result.value("filiere    ")).toString() );
        _mineur    =CursusManager::getInstance.getCursus((result.value("mineur     ")).toString() );*/
    }
}

void Dossier::loadFromFile() {

}
