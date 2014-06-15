#ifndef CS_H
#define CS_H

/**
 * @file cs.h
 */

#include <QString>
#include "uv.h"
#include "enscredits.h"

/**
 * @brief The CS class Classe representant une CS. Herite de la classe UV
 */
class CS: public UV
{
public:
    /**
     * @brief CS Constructeur d'une CS
     * @param nom Nom de la CS
     * @param code Code de la CS
     * @param saison Saison pendant laquelle la CS est enseignee
     * @param credits Nombre de crédits CS donne par l'UV
     */
    CS(const QString nom, const QString code, const Saison saison, unsigned int credits):\
        UV::UV(nom, code, saison){ getCredit().setCS(credits); }
        // On considère que les CS ne donnent que des crédits CS

    /*Getters*/
    virtual const QString getCategorie() {return QString("CS");} 
    virtual const QString getColonneTSH()   {}
    virtual const QString getLigneTSH()     {}

    /*Setters*/
    virtual void setLigneTSH(const LigneTSH ligneTSH)       {}
    virtual void setLigneTSH(const QString& ligneTSH)       {}
    virtual void setColonneTSH(const ColonneTSH colonneTSH) {}
    virtual void setColonneTSH(const QString& colonneTSH)   {}
};

#endif // CS_H
