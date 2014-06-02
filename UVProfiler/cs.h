#ifndef CS_H
#define CS_H

#include <QString>
#include "uv.h"

class CS: public UV
{
public:
    CS(const QString n, const QString c, const Saison s): UV::UV(n, c, s){}
    virtual const QString getCategorie() {return QString("CS");}
};

#endif // CS_H
