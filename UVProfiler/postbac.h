#ifndef POSTBAC_H
#define POSTBAC_H

#include "cursus.h"
#include <QString>


class PostBac: public Cursus
{
public:
    PostBac(const QString& n, const QString& c, const QString& d, const EnsCredits cn=0): Cursus::Cursus(n, c, d, cn){}
};

#endif // POSTBAC_H
