#include "etudiant.h"

Etudiant* Etudiant::_instance(NULL);

Etudiant::Etudiant(QString login, QString nom, QString prenom) : EtudiantData(login, nom, prenom) {

}

Etudiant::~Etudiant() {}



Etudiant& Etudiant::createAccount(QString username, QString nom, QString prenom) {
    if(!_instance) // Donc si un étudiant est déjà en cours d'utilisation
        delete _instance; // On déconnecte l'étudiant en cours
    _instance = new Etudiant(username, nom, prenom);
    return *_instance;
}

static Etudiant& login(QString username) {

}


