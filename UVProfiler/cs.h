#ifndef CS_H
#define CS_H

#include <QString>
#include "uv.h"
#include "enscredits.h"

class CS: public UV
{
public:
    CS(const QString nom, const QString code, const Saison saison, unsigned int credits):\
        UV::UV(nom, code, saison){ getCredit().setCS(credits); }
        // On considère que les CS ne donnent que des crédits CS
    virtual const QString getCategorie() {return QString("CS");}
    virtual void setLigneTSH(const LigneTSH ligneTSH)       {}
    virtual void setLigneTSH(const QString& ligneTSH)       {}
    virtual void setColonneTSH(const ColonneTSH colonneTSH) {}
    virtual void setColonneTSH(const QString& colonneTSH)   {}
    virtual const QString getColonneTSH()   {}
    virtual const QString getLigneTSH()     {}
};

#endif // CS_H
