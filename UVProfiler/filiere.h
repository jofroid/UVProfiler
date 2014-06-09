#ifndef FILIERE_H
#define FILIERE_H

#include <QVariant>
#include "cursus.h"
#include "branche.h"

class Filiere : public Cursus
{
protected:
    Branche* branche;
public:
    Filiere();
    Filiere(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0):\
        Cursus::Cursus(nom, code, description, creditsNecessaires) {}
};

#endif // FILIERE_H
