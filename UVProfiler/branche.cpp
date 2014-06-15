#include "branche.h"

// ----------------------------------
// -     FILE FUNCTIONS
// ----------------------------------

 // Constructeur de recopie
Branche::Branche(const Branche& copie) : \
    Cursus(copie._nom, copie._code, copie._description, copie._creditsNecessaires), _creditsPCB(copie._creditsPCB) {}


void Branche::serialize(QDataStream &stream) const {
    Cursus::serialize(stream);
    stream << _creditsPCB;
}

void Branche::unserialize(QDataStream &stream) {
    Cursus::unserialize(stream);
    stream >> _creditsPCB;
}


// ----------------------------------
// -     OTHER FUNCTIONS
// ----------------------------------
