#include "dossier.h"

Dossier::Dossier(QString username) : _login(username), _semestreB(0), _semestrePB(0),_postBac(0), _branche(0),
    _filiere(0), _mineur(0) {
    load();
}
Dossier::Dossier(DossierData& data) : _login(data.getlogin()), _semestreB(data.getSemestreB()),\
    _semestrePB(data.getSemestrePB()) {
    _postBac = CursusManager::getInstance().getPostBac(data.getPostBac());
    _branche = CursusManager::getInstance().getBranche(data.getBranche());
    _filiere = CursusManager::getInstance().getFiliere(data.getFiliere());
    _mineur  = CursusManager::getInstance().getFiliere(data.getMineur() );
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
    QSettings fichier("UVProfiler.ini", QSettings::IniFormat);


    fichier.beginGroup("dossier"); // Chargement du dossier
      DossierData data;
      const QStringList childKeys = fichier.childKeys();
      foreach (const QString& childKey, childKeys) {
          data = fichier.value(childKey, QVariant::fromValue(DossierData() )).value<DossierData>();
          if(data.getlogin()==_login)
              break; // On sort de la boucle car on a trouvé le dossier qui nous intéresse
      }
    fichier.endGroup();
    if(data.getlogin()==_login) {
        _postBac = CursusManager::getInstance().getPostBac(data.getPostBac());
        _branche = CursusManager::getInstance().getBranche(data.getBranche());
        _filiere = CursusManager::getInstance().getFiliere(data.getFiliere());
        _mineur  = CursusManager::getInstance().getFiliere(data.getFiliere());
        _semestreB  = data.getSemestreB();
        _semestrePB = data.getSemestrePB();
        updateCredits();
    }

}

void Dossier::loadFromExample() {

}

// ----------------------------------
// -        SAVE DOSSIER
// ----------------------------------

void Dossier::save() {
    saveToFile();
}

void Dossier::saveToFile() {
    QSettings fichier("UVProfiler.ini", QSettings::IniFormat);

    fichier.beginGroup("dossier"); // On sauvegarde la partie dossier

    DossierData data(*this);
    fichier.setValue(data.getlogin(), QVariant::fromValue(data));
    fichier.endGroup();
    fichier.sync();

    QSettings fichierInscription("Inscription.ini", QSettings::IniFormat);
    fichierInscription.beginGroup(data.getlogin()); // On sauvegarde la partie inscription
    QMap<Semestre, Inscription*>::iterator it;
    int i(0);
    for(it=_inscriptions.begin(); it!=_inscriptions.end(); it++) {std::cout<<i<<"\n";i++;
        fichierInscription.setValue("", QVariant::fromValue( *(it.value()) ) );
    }
    fichierInscription.endGroup();
    fichierInscription.sync();
}



// ----------------------------------
// -        OTHER FUNCTIONS
// ----------------------------------

void Dossier::updateCredits() {
    if(_postBac) { // Donc si PostBac est défini
        std::cout<<"on va maj les cred'\n";
        updateCreditsPostBac();
    }
    if(_branche) { // Donc si Branche est définie
        updateCreditsBranche();
    }
}

void Dossier::setCreditsPostBac(const EnsCredits& credits) { // Dans le cas où on a pas fait de TC
    if(!_postBac)
        _creditsTotauxPostBac=credits;
}

void Dossier::updateCreditsPostBac() {
    if(_postBac) { // Donc si on a fait la prépa intégrée de l'UT
        QMap<Semestre, Inscription*>::const_iterator it;
        EnsCredits total;
        for(it=_inscriptions.constBegin(); it!=_inscriptions.constEnd(); ++it) {
            if( it.value()->getCursus() == _postBac) { // Donc si l'inscription concerne notre postBac
                total+=it.value()->getCredits();
            }
        }
        _creditsTotauxPostBac=total;
    }
}

void Dossier::updateCreditsBranche() {
    if(_branche) { // Donc si on est en branche
        QMap<Semestre, Inscription*>::const_iterator it;
        EnsCredits total;
        for(it=_inscriptions.constBegin(); it!=_inscriptions.constEnd(); ++it) {
            if( it.value()->getCursus() == _branche) { // Donc si l'inscription concerne notre branche
                total+=it.value()->getCredits();
            }
        }
        _creditsTotauxBranche=total;
    }
}

void Dossier::updateCreditsFiliere() {
    if(_filiere) { // Donc si on est en filiere
        QMap<Semestre, Inscription*>::const_iterator it;
        EnsCredits total;
        for(it=_inscriptions.constBegin(); it!=_inscriptions.constEnd(); ++it) {
            if( it.value()->getCursus() == _filiere) { // Donc si l'inscription concerne notre branche
                total+=it.value()->getCredits();
            }
        }
        _creditsTotauxFiliere=total;
    }
}


