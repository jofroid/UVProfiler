#ifndef TM_H
#define TM_H

#include <QString>
#include "uv.h"

class TM: public UV
{
public:
    TM(const QString n, const QString c, const Saison s, const unsigned int credits): UV::UV(n, c, s){  getCredit().setTM(credits);}
    virtual const QString getCategorie() {return "TM";}
    virtual void setLigneTSH(const LigneTSH ligneTSH){}
    virtual void setColonneTSH(const ColonneTSH colonneTSH){}
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual void setLigneTSH(const QString& ligneTSH){}
    virtual void setColonneTSH(const QString& colonneTSH){}
};

#endif // TM_H
