#ifndef SEMESTRE_H
#define SEMESTRE_H

// Permet de stocker P14 par exemple


#include <QVariant>
#include <QString>
#include "UVProfiler.h"


class Semestre
{
protected:
    Saison _saison;
    unsigned int _annee;
public:
    Semestre(Saison saison = Aut, unsigned int annee = 0) : _saison(saison), _annee(annee) {}
    Semestre(const Semestre& copie) : _saison(copie._saison), _annee(copie._annee) {}

    static void initSemestreSystem();
    friend QDataStream& operator<< (QDataStream&, const Semestre&);
    friend QDataStream& operator>> (QDataStream&, Semestre&);
};

Q_DECLARE_METATYPE(Semestre)
QDataStream& operator<< (QDataStream& out, const Semestre& Valeur);
QDataStream& operator>> (QDataStream& in, Semestre& Valeur);



#endif // SEMESTRE_H
