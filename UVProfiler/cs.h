#ifndef CS_H
#define CS_H

#include <QString>
#include "uv.h"
#include "enscredits.h"

class CS: public UV
{
public:
    CS(const QString nom, const QString code, const Saison saison, const EnsCredits credits): UV::UV(nom, code, saison){   setCredits(credits); }
    virtual const QString getCategorie() {return QString("CS");}
    virtual void setLigneTSH(const LigneTSH ligneTSH){}
    virtual void setColonneTSH(const ColonneTSH colonneTSH){}
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual void setLigneTSH(const QString& ligneTSH){}
    virtual void setColonneTSH(const QString& colonneTSH){}
};

#endif // CS_H
