#ifndef BRANCHE_H
#define BRANCHE_H

#include <QString>
#include "cursus.h"

enum ColonneTSH { DemarchesEtPratiques, Connaissances     };
enum LigneTSH   { Concevoir, Communiquer, OrganiserManager};

class Branche: public Cursus
{
private:
    unsigned int _creditsPCB;
    
public:
    Branche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0 ): \
        Cursus(nom, code, description, creditsNecessaires){}
};

#endif // BRANCHE_H
