#ifndef TSH_H
#define TSH_H

/**
  * @file TSH.h
  */
#include "uv.h"
#include "branche.h" // contient les enum LigneTSH et ColonneTSH
#include "uvmanager.h"

/**
 * @brief The TSH class Classe representant une TSH. Herite de UV
 */
class TSH : public UV
{
private:
    /**
     * @brief _ligneTSH Categorie dans la ligne du profile TSH
     */
    LigneTSH   _ligneTSH;
    /**
     * @brief _colonneTSH Categorie dans le colonne du profile TSH
     */
    ColonneTSH _colonneTSH;
public:
    /**
     * @brief TSH Constructeur de base
     * @param nom Nom de la TSH
     * @param code Code de la TSH
     * @param saison Saison pendant laquelle la TSH est enseignee
     * @param credits Nombre de credits TSH donne par la TSH
     * @param ligneTSH Categorie dans la ligne du profile TSH
     * @param colonneTSH Categorie dans le colonne du profile TSH
     */
    TSH(const QString nom, const QString code, const Saison saison, const unsigned int credits, const LigneTSH ligneTSH=Communiquer, const ColonneTSH colonneTSH=Connaissances);
    virtual const QString getCategorie() {return "TSH";}

    // setters
    void setLigneTSH(const LigneTSH ligneTSH)           { _ligneTSH = ligneTSH;     }
    void setLigneTSH(const QString& ligneTSH);
    void setColonneTSH(const ColonneTSH colonneTSH)     { _colonneTSH = colonneTSH; }
    void setColonneTSH(const QString& colonneTSH);

    // getters
    const QString getLigneTSH();
    const QString getColonneTSH();
};

#endif // TSH_H
