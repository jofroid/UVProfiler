#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QVariant>

// Permet de stocker P14 par exemple

class Semestre
{
protected:
    enum Saison {A, P};
    //Q_DECLARE_METATYPE(Saison)
    //QDataStream& operator<<(QDataStream& out, Semestre::Saison s);
    //QDataStream& operator>> (QDataStream& in, Semestre::Saison& s);

    Saison _saison;
    unsigned int _annee;
public:
    Semestre(Saison saison = A, unsigned int annee=00) : _saison(saison), _annee(annee) {}
    Semestre(const Semestre& copie) : _saison(copie._saison), _annee(copie._annee) {}

    static void initSemestreSystem();
    friend QDataStream& operator<< (QDataStream&, const Semestre&);
    friend QDataStream& operator>> (QDataStream&, Semestre&);
};

Q_DECLARE_METATYPE(Semestre)
QDataStream& operator<< (QDataStream& out, const Semestre& Valeur);
QDataStream& operator>> (QDataStream& in, Semestre& Valeur);


#endif // SEMESTRE_H
