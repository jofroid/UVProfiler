#ifndef TM_H
#define TM_H

#include <QString>
#include "uv.h"

class TM: public UV
{
public:
    TM(const QString n, const QString c, const Saison s, const unsigned int credits): UV::UV(n, c, s){  getCredit().setTM(credits);}
    virtual const QString getCategorie() {return "TM";}
};

#endif // TM_H
