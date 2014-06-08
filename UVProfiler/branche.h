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
    Branche(): Cursus( "", "", "") {}
    Branche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0 ): \
        Cursus(nom, code, description, creditsNecessaires){}
    Branche(const Branche& copie);
    ~Branche() {}

    static void initBrancheSystem();
    friend QDataStream& operator<< (QDataStream&, const Branche&);
    friend QDataStream& operator>> (QDataStream&, Branche&);
};

Q_DECLARE_METATYPE(Branche)
QDataStream& operator<< (QDataStream& out, const Branche& Valeur);
QDataStream& operator>> (QDataStream& in, Branche& Valeur);


#endif // BRANCHE_H
