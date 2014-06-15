#include "cursus.h"

Cursus::~Cursus() {}

void Cursus::initCursusFileSystem() {   // Permet de serialiser la classe Cursus
    qRegisterMetaTypeStreamOperators<Cursus>("Cursus");
    qMetaTypeId<Cursus>(); // Teste la validité de la classe Cursus
}

void Cursus::serialize(QDataStream& stream) const {
    stream <<_nom
           <<_code
           <<_description
           <<_creditsNecessaires;
}

void Cursus::unserialize(QDataStream& stream) {
    stream >> _nom;
    stream >> _code;
    stream >> _description;
    stream >> _creditsNecessaires;
}

QDataStream& operator<< (QDataStream& out, const Cursus& valeur) {
    valeur.serialize(out);
    return out;
}

QDataStream& operator>> (QDataStream& in, Cursus& valeur) {
    valeur.unserialize(in);
    return in;
}

