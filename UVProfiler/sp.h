#ifndef SP_H
#define SP_H

#include <QString>
#include "uv.h"

class SP: public UV
{
public:
    SP(const QString n, const QString c, const Saison s, const unsigned int credits): UV::UV(n, c, s){  getCredit().setSP(credits); }
    virtual const QString getCategorie() {return "SP";}
};

#endif // SP_H
