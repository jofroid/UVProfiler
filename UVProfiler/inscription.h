#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QString>
#include <QMap>
#include "UVProfiler.h"
#include "semestre.h"
#include "cursus.h"
#include "uv.h"


class Inscription
{
protected:
    Semestre _semestre;
    Cursus* _cursusEnCours;
public:
    Inscription( const Semestre& semestre = Semestre(Aut,0), Cursus* cursus = NULLPTR): _semestre(semestre), _cursusEnCours(cursus)
        {}
    virtual ~Inscription()=0;
};

#endif // INSCRIPTION_H
