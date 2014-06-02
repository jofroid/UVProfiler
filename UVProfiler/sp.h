#ifndef SP_H
#define SP_H

#include <QString>
#include "uv.h"

class SP: public UV
{
public:
    SP(const QString n, const QString c, const Saison s): UV::UV(n, c, s){}
    virtual const QString getCategorie() {return "SP";}
};

#endif // SP_H
