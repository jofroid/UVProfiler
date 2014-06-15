#ifndef SP_H
#define SP_H

/**
  * @file sp.h
  */
#include <QString>
#include "uv.h"

/**
 * @brief The SP class Classe representant une SP. Herite de UV
 */
class SP: public UV
{
public:
    /**
     * @brief SP Constructeur de base
     * @param nom Nom de la SP
     * @param code Code de la SP
     * @param saison Saison pendant laquelle la SP est enseignee
     * @param credits Nombre de credits SP donne par la SP
     */
    SP(const QString nom, const QString code, const Saison saison, const unsigned int credits):\
        UV::UV(nom, code, saison) { getCredit().setSP(credits); }
    //Setters
    virtual void setLigneTSH(const LigneTSH ligneTSH)       {}
    virtual void setLigneTSH(const QString& ligneTSH)       {}
    virtual void setColonneTSH(const ColonneTSH colonneTSH) {}
    virtual void setColonneTSH(const QString& colonneTSH)   {}

    //Getters
    virtual const QString getColonneTSH(){}
    virtual const QString getLigneTSH(){}
    virtual const QString getCategorie() {return "SP";}
};

#endif // SP_H
