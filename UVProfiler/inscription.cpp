#include "inscription.h"

Inscription::~Inscription() {}

void Inscription::initInscriptionFileSystem() {   // Permet de serialiser la classe Inscription
    qRegisterMetaTypeStreamOperators<Inscription>("Inscription");
    qMetaTypeId<Inscription>(); // Teste la validité de la classe Inscription
}

void Inscription::serialize(QDataStream& stream) const {
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

QDataStream& operator<< (QDataStream& out, const Inscription& valeur) {
    valeur.serialize(out);
    return out;
}

QDataStream& operator>> (QDataStream& in, Inscription& valeur) {
    valeur.unserialize(in);
    return in;
}
