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
        std::cout<<it.value()->getCode().toStdString();
        it.value()->getCredit().afficheEnsCredits();
        if(_notes[it.value()->getCode()] < FX) { // Donc si la notes est supérieur à FX (voir enum pour comprendre)
            total+=it.value()->getCredit();
        }
    }
    std::cout<<"\ntotal sem:\n"; total.afficheEnsCredits();
    return total;
}

void SemestreUTC::initSemestreUTCFileSystem() {
    qRegisterMetaTypeStreamOperators<SemestreUTC>("SemestreUTC");
    qMetaTypeId<SemestreUTC>(); // Teste la validité de la classe EnsCredits
}

QDataStream& operator<< (QDataStream& out, const SemestreUTC& Valeur)
{
    out << (int)Valeur._type
        << Valeur._semestre
        << Valeur._cursusEnCours->getCode();

    return out;
}
QDataStream& operator>> (QDataStream& in, SemestreUTC& Valeur)
{
    int retour(0);
    in >> retour; Valeur._type = (typeInscription)retour;
    in >> Valeur._semestre;
    QString code;
    in >> code;
    Valeur._cursusEnCours = CursusManager::getInstance().getCursus(code);

    return in;
}
