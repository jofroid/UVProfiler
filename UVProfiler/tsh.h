#ifndef TSH_H
#define TSH_H

#include "uv.h"
#include "branche.h" // contient les enum LigneTSH et ColonneTSH
#include "uvmanager.h"

class TSH : public UV
{
private:
    LigneTSH   _ligneTSH;
    ColonneTSH _colonneTSH;
public:
    TSH(const QString n, const QString c, const Saison s, const unsigned int credits, const LigneTSH ligneTSH=Communiquer, const ColonneTSH colonneTSH=Connaissances);
    virtual const QString getCategorie() {return "TSH";}

    // setters
    void setLigneTSH(const LigneTSH ligneTSH)           { _ligneTSH = ligneTSH;     }
    void setColonneTSH(const ColonneTSH colonneTSH)     { _colonneTSH = colonneTSH; }
    void setLigneTSH(const QString& ligneTSH);
    void setColonneTSH(const QString& colonneTSH);

    // getters
    const QString getLigneTSH();
    const QString getColonneTSH();
};

#endif // TSH_H
