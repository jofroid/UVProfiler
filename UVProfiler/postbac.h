#ifndef POSTBAC_H
#define POSTBAC_H
#include "cursus.h"

class PostBac: public Cursus
{
public:
    PostBac(const std::string& n, const std::string& c, const std::string& d, const EnsCredits cn=0): Cursus::Cursus(n, c, d, cn){}
};

#endif // POSTBAC_H
