#ifndef TM_H
#define TM_H

/**
  * @file TM.h
  */
#include <QString>
#include "uv.h"

/**
 * @brief The TM class Classe representant une TM. Herite de UV
 */
class TM: public UV
{
public:
    /**
     * @brief TM Constructeur de base
     * @param nom Nom de la TM
     * @param code Code de la TM
     * @param saison Saison ou la TM est enseignee
     * @param credits Nombre de credits donne par la TM
     */
    TM(const QString nom, const QString code, const Saison saison, const unsigned int credits):\
        UV::UV(nom, code, saison) { getCredit().setTM(credits); }
    //Setters
    virtual void setLigneTSH(const LigneTSH ligneTSH)       {}
    virtual void setLigneTSH(const QString& ligneTSH)       {}
    virtual void setColonneTSH(const ColonneTSH colonneTSH) {}
    virtual void setColonneTSH(const QString& colonneTSH)   {}

    //Getters
    virtual const QString getColonneTSH()   {}
    virtual const QString getLigneTSH()     {}
    virtual const QString getCategorie() {return "TM";}
};

#endif // TM_H
