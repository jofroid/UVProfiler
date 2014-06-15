#include "criteresvalidationfiliere.h"

CriteresValidationFiliere::CriteresValidationFiliere() {}

void CriteresValidationFiliere::serialize(QDataStream& stream) const {}

void CriteresValidationFiliere::unserialize(QDataStream& stream) {}

QDataStream& operator<< (QDataStream& out, const CriteresValidationFiliere& valeur) {
    valeur.serialize(out);
    return out;
}

QDataStream& operator>> (QDataStream& in, CriteresValidationFiliere& valeur) {
    valeur.unserialize(in);
    return in;
}
