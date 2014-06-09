#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QString>
#include <QMap>
#include "semestre.h"
#include "cursus.h"
#include "uv.h"


class Inscription
{
protected:
    Semestre _semestre;
    Cursus* _cursusEnCours;
    QMap<QString, UV*> _choixUVs;
public:
    Inscription();
};

#endif // INSCRIPTION_H
