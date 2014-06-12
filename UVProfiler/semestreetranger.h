#ifndef SEMESTREETRANGER_H
#define SEMESTREETRANGER_H

#include "UVProfiler.h"
#include "enscredits.h"
#include "inscription.h"
#include "semestre.h"
#include "cursus.h"


class SemestreEtranger: public Inscription
{
private:
    EnsCredits _pronosticCreditsMin;
    EnsCredits _pronosticCreditsMax;

public:
    SemestreEtranger(const Semestre& semestre, Cursus* cursus, const EnsCredits& pronosticCreditsMin, const EnsCredits& pronosticCreditsMax):\
        Inscription(semestre, cursus), _pronosticCreditsMin(pronosticCreditsMin), _pronosticCreditsMax(pronosticCreditsMax){}

//SETTERS
    void setCreditsMin(const EnsCredits pronosticCreditsMin) { _pronosticCreditsMin = pronosticCreditsMin; }
    void setCreditsMax(const EnsCredits pronosticCreditsMax) { _pronosticCreditsMax = pronosticCreditsMax; }

//GETTERS
    EnsCredits getCreditsMin()  { return _pronosticCreditsMin;  }
    EnsCredits getCreditsMax()  { return _pronosticCreditsMax;  }

};


#endif // SEMESTREETRANGER_H
