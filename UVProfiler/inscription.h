#ifndef INSCRIPTION_H
#define INSCRIPTION_H

/**
  * @file inscription.h
  */
#include <QString>
#include <QMap>
#include "UVProfiler.h"
#include "uvmanager.h"
#include "semestre.h"
#include "cursus.h"
#include "uv.h"

/**
 * @brief The Inscription class Classe abstraite representant une inscription a un semestre (liste d'UV, cursus en cours...)
 */
class Inscription
{
protected:
    /**
     * @brief The typeInscription enum Enumeartion du type de l'inscription : a l'UTC ou a l'etranger
     */
    enum typeInscription { tsemestreUTC, tsemestreEtranger};
    /**
     * @brief _type Type de l'inscription
     */
    typeInscription _type;
    /**
     * @brief _semestre Semestre de l'inscription
     */
    Semestre _semestre;
    /**
     * @brief _cursusEnCours Cursus en cours de l'inscription
     */
    Cursus* _cursusEnCours;
public:
    /**
     * @brief Inscription Constructeur de base
     * @param type Type de l'inscription
     * @param semestre Semestre de l'inscription
     * @param cursus Cursus en cours de l'inscription
     */
    Inscription( typeInscription type, const Semestre& semestre = Semestre(Aut,0), Cursus* cursus = NULLPTR): _semestre(semestre), _cursusEnCours(cursus), _type(type)
        {}
    /**
     * @brief ~Inscription Destructeur virtuel permettant de rendre la classe abstraite
     */
    virtual ~Inscription()=0;

    /*Getters*/
    Cursus* getCursus() { return _cursusEnCours; }
    const Semestre& getSemestre() { return _semestre; }
    virtual EnsCredits getCredits()=0;
};

#endif // INSCRIPTION_H
