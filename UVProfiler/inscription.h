#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QString>
#include <QMap>
#include "UVProfiler.h"
#include "uvmanager.h"
#include "semestre.h"
#include "cursus.h"
#include "uv.h"


class Inscription
{
protected:
    enum typeInscription { tsemestreUTC, tsemestreEtranger};
    typeInscription _type;
    Semestre _semestre;
    Cursus* _cursusEnCours;
public:
    Inscription( typeInscription type, const Semestre& semestre = Semestre(Aut,0), Cursus* cursus = NULLPTR): _semestre(semestre), _cursusEnCours(cursus), _type(type)
        {}
    virtual ~Inscription()=0;

    Cursus* getCursus() { return _cursusEnCours; }
    const Semestre& getSemestre() { return _semestre; }
    virtual EnsCredits getCredits()=0;
};

#endif // INSCRIPTION_H
