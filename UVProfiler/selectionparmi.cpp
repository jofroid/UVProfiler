#include "selectionparmi.h"


void SelectionParmi::addUV(QString code) {
    _uvsNecessaires.insert( code, &UVManager::getInstance().getUV(code) );
}

void SelectionParmi::addUV(UV* uv) {
    _uvsNecessaires.insert( uv->getCode(), uv);
}


void SelectionParmi::removeUV(QString code) {
    _uvsNecessaires.remove(code);
}

void SelectionParmi::removeUV(UV* uv) {
    _uvsNecessaires.remove(uv->getCode());
}

bool SelectionParmi::validation() {
    Etudiant& etudiant = Etudiant::getInstance();
    QMap<Semestre, Inscription*>::const_iterator itIns;
    QMap<QString, Notes>::const_iterator itUV;
    QMap<QString, UV*>::const_iterator itUV2;

    int nbUVsuivies(_nbUvsNecessaires);
    for(itIns=etudiant.getDossier()->getInscriptions().constBegin(); itIns!=etudiant.getDossier()->getInscriptions().constEnd() && nbUVsuivies>0; itIns++) {
        if(itIns.value()->getType() == tsemestreUTC) {
            for(itUV=itIns.value()->getNotes().constBegin(); itUV!=itIns.value()->getNotes().constEnd() && nbUVsuivies>0; ++itUV) {
                //itUV vaut ici un pointeur sur une UV dans une Inscription, il reste à le comparer à nos UV necessaires
                for(itUV2=_uvsNecessaires.constBegin(); itUV2!=_uvsNecessaires.constEnd(); itUV2++) {
                    if(itUV2.value()->getCode() == itUV.key())
                        if(itUV.value() <FX) // donc si l'UV est validée
                            nbUVsuivies--;
                }

            }
        }
    }
}
