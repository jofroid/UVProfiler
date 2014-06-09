#include "semestre.h"

void Semestre::initSemestreSystem() {
    qRegisterMetaTypeStreamOperators<Semestre>("Semestre");
    qMetaTypeId<Semestre>(); // Teste la validité de la classe EnsCredits
}

QDataStream& operator<< (QDataStream& out, const Semestre& Valeur) {
    out //<< Valeur._saison
        << Valeur._annee;
    return out;
}

QDataStream& operator>> (QDataStream& in, Semestre& Valeur){
    // in >> Valeur._saison; // <- en cours d'implémentation, mais plante encore
    in >> Valeur._annee;
    return in;
}
/*
QDataStream& operator<<(QDataStream& out, Semestre::Saison s) {
    switch (s) {
    case A: return out << "A";
    case P: return out << "P";
    default: return out << (int) s;
    }
    return out;
}

QDataStream& operator>> (QDataStream& in, Semestre::Saison& s){
    int a;
    in >> a;
    s(Semestre::Saison(a));
    return in;
} //*/
