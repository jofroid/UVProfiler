#ifndef BRANCHE_H
#define BRANCHE_H

#include "cursus.h"

class Branche: public Cursus
{
private:
    unsigned int _creditsPCB;
    
public:
    Branche(const std::string& n, const std::string& c, const std::string& d, const EnsCredits cn=0 ): Cursus::Cursus(n, c, d, cn){}
};

#endif // BRANCHE_H
