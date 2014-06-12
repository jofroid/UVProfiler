#include "semestreutc.h"

SemestreUTC::SemestreUTC() {}

void SemestreUTC::setNote(const QString& nom, const Notes& note) {
    if( _choixUVs.contains(nom) ) { // Donc si l'UV est dans la liste des UV choisies
        _notes[nom] = note;
        return;
    }
    return; // On devrait lancer une exeption là, peut-être ...
}

void SemestreUTC::setNote(UV* uv, const Notes& note) {
    if( _choixUVs.contains(uv->getNom()) ) { // Donc si l'UV est dans la liste des UV choisies
        _notes[uv->getNom()] = note;
        return;
    }
    return; // On devrait lancer une exeption là, peut-être ...
}

