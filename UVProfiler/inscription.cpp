#include "inscription.h"

Inscription::~Inscription() {}

void Inscription::serialize(QDataStream& stream) {
    stream <<(int)_type
           <<_semestre
           <<_cursusEnCours->getCode();
}

void Inscription::unserialize(QDataStream& stream) {
    int a(0);
    stream>>a; _type=(typeInscription)a;
    stream>>_semestre;
    QString code;
    stream>>code; CursusManager::getInstance().getCursus(code);
}

QDataStream& operator<< (QDataStream& out, Inscription& valeur) {
    valeur.serialize(out);
    return out;
}

QDataStream& operator>> (QDataStream& in, Inscription& valeur) {
    valeur.unserialize(in);
    return in;
}
