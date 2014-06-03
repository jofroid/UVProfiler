#ifndef SP_H
#define SP_H

#include <QString>
#include "uv.h"

class SP: public UV
{
public:
    SP(const QString n, const QString c, const Saison s, const unsigned int credits): UV::UV(n, c, s){  getCredit().setSP(credits); }
    virtual const QString getCategorie() {return "SP";}
    virtual void setLigneTSH(const LigneTSH ligneTSH){}
    virtual void setColonneTSH(const ColonneTSH colonneTSH){}
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual void setLigneTSH(const QString& ligneTSH){}
    virtual void setColonneTSH(const QString& colonneTSH){}
};

#endif // SP_H
