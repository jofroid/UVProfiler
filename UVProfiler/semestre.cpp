#include "semestre.h"

bool Semestre::operator<(const Semestre& semestre) const{
    if(_annee == semestre._annee)
        return _saison < semestre._saison;
    return _annee < semestre._annee;
}

bool Semestre::operator>(const Semestre& semestre) const {
    if(_annee == semestre._annee)
        return _saison > semestre._saison;
    return _annee > semestre._annee;
}


void Semestre::initSemestreSystem() {
    qRegisterMetaTypeStreamOperators<Semestre>("Semestre");
    qMetaTypeId<Semestre>(); // Teste la validité de la classe EnsCredits
}

QDataStream& operator<< (QDataStream& out, const Semestre& Valeur) {
    out << Valeur._saison
        << Valeur._annee;
    return out;
}

QDataStream& operator>> (QDataStream& in, Semestre& Valeur){
    //in >> Valeur._saison; // <- en cours d'implémentation, mais plante encore
    in >> Valeur._annee;
    return in;
}
