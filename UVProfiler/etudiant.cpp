#include "etudiant.h"

Etudiant* Etudiant::_instance(NULL);

Etudiant::~Etudiant() {}



Etudiant& Etudiant::createAccount(QString login, QString nom, QString prenom) {
    if(!_instance) // Donc si un étudiant est déjà en cours d'utilisation
        delete _instance; // On déconnecte l'étudiant en cours
    EtudiantData data(login, nom, prenom);
    _instance = new Etudiant( data);
    return *_instance;
}

Etudiant& Etudiant::login(QString login) {
    if(!_instance) // Donc si un étudiant est déjà en cours d'utilisation
        delete _instance; // On déconnecte l'étudiant en cours
    EtudiantData data(EtudiantManager::getInstance().getEtudiant(login) );
    if(data.getLogin()== "" )
        throw UTProfilerException(QString("erreur dans Etudiant, le login ")+login+QString(" n'existe pas"));
    _instance = new Etudiant( data);
    return *_instance;
}

void Etudiant::logout() {
    if(!_instance)
        delete _instance;
}

