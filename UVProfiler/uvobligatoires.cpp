#include "uvobligatoires.h"

UVObligatoires::UVObligatoires()
{
}

bool UVObligatoires::validation() {
    Etudiant& etudiant = Etudiant::getInstance();
    QMap<Semestre, Inscription*>::const_iterator itIns;
    QMap<QString, Notes>::const_iterator itUV;
    QMap<QString, UV*>::const_iterator itUV2;

    int nbUVsuivies(_uvObligatoires.size() );
    for(itIns=etudiant.getDossier()->getInscriptions().constBegin(); itIns!=etudiant.getDossier()->getInscriptions().constEnd() && nbUVsuivies>0; itIns++) {
        if(itIns.value()->getType() == tsemestreUTC) {
            for(itUV=itIns.value()->getNotes().constBegin(); itUV!=itIns.value()->getNotes().constEnd() && nbUVsuivies>0; ++itUV) {
                //itUV vaut ici un pointeur sur une UV dans une Inscription, il reste à le comparer à nos UV necessaires
                for(itUV2=_uvObligatoires.constBegin(); itUV2!=_uvObligatoires.constEnd(); itUV2++) {
                    if(itUV2.value()->getCode() == itUV.key())
                        if(itUV.value() <FX) // donc si l'UV est validée
                            nbUVsuivies--;
                }

            }
        }
    }
}

