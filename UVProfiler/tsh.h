#ifndef TSH_H
#define TSH_H

#include "uv.h"
#include "branche.h" // contient les enum LigneTSH et ColonneTSH

class TSH : public UV
{
protected:
    LigneTSH    _ligneTSH;
    ColonneTSH _colonneTSH;
public:
    TSH(LigneTSH ligneTSH, ColonneTSH colonneTSH);

    // setters
    void setLigneTSH(LigneTSH ligneTSH)         { _ligneTSH = ligneTSH;     }
    void setColonneTSH(ColonneTSH colonneTSH)   { _colonneTSH = colonneTSH; }
    // j'ai pas surchargé setCredit, j'ai considéré qu'on pouvait avoir autrechose que des credits TSH

    // getters
    LigneTSH getLigneTSH()   { return _ligneTSH;    }
    ColonneTSH getColonneTSh() { return _colonneTSH;  }
};

#endif // TSH_H
