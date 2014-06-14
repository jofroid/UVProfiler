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
    EnsCredits _creditsObtenus;

public:
    SemestreEtranger(const Semestre& semestre, Cursus* cursus, const EnsCredits& pronosticCreditsMin, const EnsCredits& pronosticCreditsMax):\
        Inscription(tsemestreEtranger, semestre, cursus), _pronosticCreditsMin(pronosticCreditsMin), _pronosticCreditsMax(pronosticCreditsMax){}

//SETTERS
    void setCreditsMin(const EnsCredits pronosticCreditsMin) { _pronosticCreditsMin = pronosticCreditsMin; }
    void setCreditsMax(const EnsCredits pronosticCreditsMax) { _pronosticCreditsMax = pronosticCreditsMax; }
    void setCreditsObtenus(const EnsCredits credits)         { _creditsObtenus      = credits;             }


//GETTERS
    EnsCredits getCreditsMin()  { return _pronosticCreditsMin;  }
    EnsCredits getCreditsMax()  { return _pronosticCreditsMax;  }
    EnsCredits getCredits()     { return _creditsObtenus;       }

};


#endif // SEMESTREETRANGER_H
