#include "semestreetranger.h"


/*
void SemestreEtranger::initSemestreEtrangerFileSystem() {   // Permet de serialiser la classe SemestreEtranger
    qRegisterMetaTypeStreamOperators<SemestreEtranger>("SemestreEtranger");
    qMetaTypeId<SemestreEtranger>(); // Teste la validité de la classe SemestreEtranger
}

QDataStream& operator<< (QDataStream& out, const SemestreEtranger& Valeur)
{
    out << Valeur._pronosticCreditsMin
        << Valeur._pronosticCreditsMax
        << Valeur._creditsObtenus;

    return out;
}
QDataStream& operator>> (QDataStream& in, SemestreEtranger& Valeur)
{
    in >> Valeur._pronosticCreditsMin;
    in >> Valeur._pronosticCreditsMax;
    in >> Valeur._creditsObtenus;

    return in;
} */

void SemestreEtranger::serialize(QDataStream &stream) {
    Inscription::serialize( stream);
    serialize(stream);
    stream << _pronosticCreditsMax
           << _pronosticCreditsMin
           << _creditsObtenus;
}

void SemestreEtranger::unserialize(QDataStream &stream) {
    Inscription::unserialize( stream);
    unserialize(stream);
    stream >> _pronosticCreditsMax;
    stream >> _pronosticCreditsMin;
    stream >> _creditsObtenus;
}
