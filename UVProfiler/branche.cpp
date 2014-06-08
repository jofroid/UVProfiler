#include "branche.h"

// ----------------------------------
// -     FILE FUNCTIONS
// ----------------------------------

 // Constructeur de recopie
Branche::Branche(const Branche& copie) : \
    Cursus(copie._nom, copie._code, copie._description, copie._creditsNecessaires), _creditsPCB(copie._creditsPCB) {}

void Branche::initBrancheSystem() {
    qRegisterMetaTypeStreamOperators<Branche>("Branche");
    qMetaTypeId<Branche>(); // Teste la validité de la classe Branche
}

QDataStream& operator<< (QDataStream& out, const Branche& Valeur)
{
    out << Valeur._nom
        << Valeur._code
        << Valeur._description
        << Valeur._creditsNecessaires
        << Valeur._creditsPCB;

    return out;
}
QDataStream& operator>> (QDataStream& in, Branche& Valeur)
{
    in >> Valeur._nom;
    in >> Valeur._code;
    in >> Valeur._description;
    in >> Valeur._creditsNecessaires;
    in >> Valeur._creditsPCB;

    return in;
}


// ----------------------------------
// -     OTHER FUNCTIONS
// ----------------------------------
