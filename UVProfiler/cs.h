#ifndef CS_H
#define CS_H

#include "QString"
#include "uv.h"

class CS: public UV
{
public:
    CS(const QString n, const QString c, const Saison s): UV::UV(n, c, s){}
};

#endif // CS_H
