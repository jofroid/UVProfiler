#include "postbac.h"

void initPostBacSystem() {
    qRegisterMetaTypeStreamOperators<PostBac>("PostBac");
    qMetaTypeId<PostBac>(); // Teste la validité de la classe EnsCredits
}

QDataStream& operator<< (QDataStream& out, const PostBac& Valeur)
{
    out << Valeur._nom
        << Valeur._code
        << Valeur._description
        << Valeur._creditsNecessaires;

    return out;
}
QDataStream& operator>> (QDataStream& in, PostBac& Valeur)
{
    in >> Valeur._nom;
    in >> Valeur._code;
    in >> Valeur._description;
    in >> Valeur._creditsNecessaires;

    return in;
}
