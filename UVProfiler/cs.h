#ifndef CS_H
#define CS_H

#include <QString>
#include "uv.h"

class CS: public UV
{
public:
    CS(const QString n, const QString c, const Saison s, const unsigned int credits): UV::UV(n, c, s){   getCredit().setCS(credits); }
    virtual const QString getCategorie() {return QString("CS");}
    virtual void setLigneTSH(const LigneTSH ligneTSH){}
    virtual void setColonneTSH(const ColonneTSH colonneTSH){}
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual void setLigneTSH(const QString& ligneTSH){}
    virtual void setColonneTSH(const QString& colonneTSH){}
};

#endif // CS_H
