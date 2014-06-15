#include "filiere.h"


void Filiere::initFiliereFileSystem() {   // Permet de serialiser la classe Filiere
    qRegisterMetaTypeStreamOperators<Filiere>("Filiere");
    qMetaTypeId<Filiere>(); // Teste la validité de la classe Filiere
}

QDataStream& operator<< (QDataStream& out, const Filiere& Valeur)
{
    out << Valeur._nom
        << Valeur._code
        << Valeur._description
        << Valeur._creditsNecessaires
        << Valeur._branche->getCode();

    return out;
}
QDataStream& operator>> (QDataStream& in, Filiere& Valeur)
{
    in >> Valeur._nom;
    in >> Valeur._code;
    in >> Valeur._description;
    in >> Valeur._creditsNecessaires;
    QString code;
    in >> code;
    //Valeur._branche = CursusManager::getInstance().getBranche(code);

    return in;
}

