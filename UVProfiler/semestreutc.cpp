#include "semestreutc.h"



void SemestreUTC::setNote(const QString& code, const Notes& note) {
    if( _choixUVs.contains(code) ) { // Donc si l'UV est dans la liste des UV choisies
        _notes[code] = note;
        return;
    }
    return; // On devrait lancer une exeption là, peut-être ...
}

void SemestreUTC::setNote(UV* uv, const Notes& note) {
    if( _choixUVs.contains(uv->getCode()) ) { // Donc si l'UV est dans la liste des UV choisies
        _notes[uv->getCode()] = note;
        return;
    }
    return; // On devrait lancer une exeption là, peut-être ...
}

EnsCredits SemestreUTC::getCredits() {
    EnsCredits total;
    QMap<QString, UV*>::const_iterator it;
    for(it=_choixUVs.constBegin(); it!=_choixUVs.constEnd(); ++it) {
        if(_notes[it.value()->getCode()] < FX) { // Donc si la notes est supérieur à FX (voir enum pour comprendre)
            total+=it.value()->getCredit();
        }
    }
}


