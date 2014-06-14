#ifndef SEMESTRE_H
#define SEMESTRE_H

/**
  * @file semestre.h
  */
// Permet de stocker P14 par exemple


#include <QVariant>
#include <QString>
#include "UVProfiler.h"

/**
 * @brief The Semestre class Classe representant un semestre
 */
class Semestre
{
protected:
    /**
     * @brief _saison Saison du semestre
     */
    Saison _saison;
    /**
     * @brief _annee Annee du semestre
     */
    unsigned int _annee;
public:
    /**
     * @brief Semestre Constructeur de base
     * @param saison Saison du semestre
     * @param annee Annee du semestre
     */
    Semestre(Saison saison = Aut, unsigned int annee = 0) : _saison(saison), _annee(annee) {}
    /**
     * @brief Semestre Constructeur de recopie
     * @param copie Reference d'un objet Semestre a copier
     */
    Semestre(const Semestre& copie) : _saison(copie._saison), _annee(copie._annee) {}

    /**
     * @brief operator < Surcharge de l'operateur <
     * @param semestre
     * @return Resultat de l'operation logique
     */
    bool operator<(const Semestre& semestre) const;
    /**
     * @brief operator > Sucharge de l'operateur >
     * @param semestre
     * @return Resultat de l'operation logique
     */
    bool operator>(const Semestre& semestre) const;

    static void initSemestreSystem();
    friend QDataStream& operator<< (QDataStream&, const Semestre&);
    friend QDataStream& operator>> (QDataStream&, Semestre&);
};

Q_DECLARE_METATYPE(Semestre)
QDataStream& operator<< (QDataStream& out, const Semestre& Valeur);
QDataStream& operator>> (QDataStream& in, Semestre& Valeur);



#endif // SEMESTRE_H
