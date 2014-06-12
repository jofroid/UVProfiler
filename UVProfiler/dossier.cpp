#include "dossier.h"

Dossier::Dossier(QString username) : _login(username), _postBac(0), _branche(0), _filiere(0), _mineur(0) {
    load();
}


// ----------------------------------
// -        LOAD DOSSIER
// ----------------------------------

void Dossier::load() {
    loadFromFile();
}

void Dossier::loadFromDB() { // Non fonctionnel ...

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


// ----------------------------------
// -        OTHER FUNCTIONS
// ----------------------------------

void Dossier::updateCredits() {
    if(!_postBac) { // Donc si PostBac est défini
        updateCreditsPostBac();
    }
    if(!_branche) { // Donc si Branche est définie
        updateCreditsBranche();
    }
}

void Dossier::updateCreditsPostBac() {
    // Parcourir toutes les inscriptions du tableau donc le cursus a la même valeur que _postBac, et additionner les
    //      credits dont la notes est supérieur à FX (en pratique, inférieur car c'est une enum).
    // Ou alors, rajouter un champ _créditsObtenus dans la classe Inscription, et une fonction updateCredits que l'on
    //      appelerai à chaque fois que l'on ajoute une note ou retire une UV.
    // C'est toi qui voit, mais je pense qu'on aura un soucis avec le pronostic du semestreEtranger, à moins qu'on
    //      rajoute un champ _creditsObtenus que l'on remplit à la fin du semestre à l'étranger avec le nombre de
    //      crédits obtenus...
}

void Dossier::updateCreditsBranche() {

}


