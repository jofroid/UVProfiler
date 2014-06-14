#ifndef SP_H
#define SP_H

#include <QString>
#include "uv.h"

class SP: public UV
{
public:
    SP(const QString nom, const QString code, const Saison saison, const unsigned int credits):\
        UV::UV(nom, code, saison) { getCredit().setSP(credits); }
    //Setters
    virtual void setLigneTSH(const LigneTSH ligneTSH)       {}
    virtual void setLigneTSH(const QString& ligneTSH)       {}
    virtual void setColonneTSH(const ColonneTSH colonneTSH) {}
    virtual void setColonneTSH(const QString& colonneTSH)   {}

    //Getters
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual const QString getCategorie() {return "SP";}
};

#endif // SP_H
