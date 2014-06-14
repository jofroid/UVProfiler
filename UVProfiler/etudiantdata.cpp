#include "etudiantdata.h"

EtudiantData::EtudiantData(const EtudiantData& copie) {
    _login = copie._login;
    _nom = copie._nom;
    _prenom = copie._prenom;
}

void EtudiantData::initEtudiantDataFileSystem() {
    qRegisterMetaTypeStreamOperators<EtudiantData>("EtudiantData");
    qMetaTypeId<EtudiantData>(); // Teste la validité de la classe EtudiantData
}

QDataStream& operator<< (QDataStream& out, const EtudiantData& Valeur)
{
    out << Valeur._login
        << Valeur._nom
        << Valeur._prenom;

    return out;
}
QDataStream& operator>> (QDataStream& in, EtudiantData& Valeur)
{
    in >> Valeur._login;
    in >> Valeur._nom;
    in >> Valeur._prenom;

    return in;
}
