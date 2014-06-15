#include "cursus.h"

Cursus::~Cursus() {}

void Cursus::serialize(QDataStream& stream) {
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

QDataStream& operator<< (QDataStream& out, Cursus& valeur) {
    valeur.serialize(out);
    return out;
}

QDataStream& operator>> (QDataStream& in, Cursus& valeur) {
    valeur.unserialize(in);
    return in;
}

