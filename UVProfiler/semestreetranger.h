#ifndef SEMESTREETRANGER_H
#define SEMESTREETRANGER_H

#include "enscredits.h"
#include "inscription.h"

class SemestreEtranger: public Inscription
{
private:
    EnsCredits _pronosticCreditsMin;
    EnsCredits _pronosticCreditsMax;

public:
    SemestreEtranger(const EnsCredits pronosticCreditsMin, const EnsCredits pronosticCreditsMax):_pronosticCreditsMin(pronosticCreditsMin), _pronosticCreditsMax(pronosticCreditsMax){}
};

//SETTERS
    void setCreditsMin(const EnsCredits pronosticCreditsMin) { _pronosticCreditsMin = pronosticCreditsMin; }
    void setCreditsMax(const EnsCredits pronosticCreditsMax) { _pronosticCreditsMax = pronosticCreditsMax; }

//GETTERS
    EnsCredits getCreditsMin()    {   return _pronosticCreditsMin;    }
    EnsCredits getCreditsMax()    {   return _pronosticCreditsMax;    }

#endif // SEMESTREETRANGER_H
