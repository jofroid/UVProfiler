#ifndef TSH_H
#define TSH_H

#include "uv.h"
#include "branche.h" // contient les enum LigneTSH et ColonneTSH

class TSH : public UV
{
protected:
    LigneTSH   _ligneTSH;
    ColonneTSH _colonneTSH;
public:
    TSH(const QString n, const QString c, const Saison s, const unsigned int credits, const LigneTSH ligneTSH=Communiquer, const ColonneTSH colonneTSH=Connaissances);
    virtual const QString getCategorie() {return "TSH";}

    // setters
    void setLigneTSH(const LigneTSH ligneTSH)         { _ligneTSH = ligneTSH;     }
    void setColonneTSH(const ColonneTSH colonneTSH)   { _colonneTSH = colonneTSH; }
    // j'ai pas surchargé setCredit, j'ai considéré qu'on pouvait avoir autrechose que des credits TSH

    // getters
    LigneTSH getLigneTSH()const   { return _ligneTSH;    }
    ColonneTSH getColonneTSh()const { return _colonneTSH;  }
};

#endif // TSH_H
