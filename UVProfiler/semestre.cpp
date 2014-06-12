#include "semestre.h"



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
