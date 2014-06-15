#ifndef SEMESTREETRANGER_H
#define SEMESTREETRANGER_H

/**
  * @file semestreetranger.h
  */
#include "UVProfiler.h"
#include "enscredits.h"
#include "inscription.h"
#include "semestre.h"
#include "cursus.h"

/**
 * @brief The SemestreEtranger class Classe representant un semestre a l'etranger (hors UTC). Herite de Inscription
 */
class SemestreEtranger: public Inscription
{
private:
    /**
     * @brief _pronosticCreditsMin Marge inferieur estimee des credits obtenus
     */
    EnsCredits _pronosticCreditsMin;
    /**
     * @brief _pronosticCreditsMax Marge superieur estimee des credits obtenus
     */
    EnsCredits _pronosticCreditsMax;
    /**
     * @brief _creditsObtenus Credits obtenus
     */
    EnsCredits _creditsObtenus;

public:
    /**
     * @brief SemestreEtranger Constructeur de base
     */
    SemestreEtranger() : Inscription(tsemestreEtranger), _pronosticCreditsMax(0), _pronosticCreditsMin(0) {}
    /**
     * @brief SemestreEtranger Constructeur de recopie
     * @param copie Reference d'un objet SemestreEtranger a recopier
     */
    SemestreEtranger(const SemestreEtranger& copie) :\
        Inscription(tsemestreEtranger, copie._semestre, copie._cursusEnCours), _pronosticCreditsMax(copie._pronosticCreditsMax),
        _pronosticCreditsMin(copie._pronosticCreditsMin), _creditsObtenus(copie._creditsObtenus) {}
    /**
     * @brief SemestreEtranger Constructeur de initialisant tous lesattributs de l'objet
     * @param semestre Semestre associe
     * @param cursus Cursus associe
     * @param pronosticCreditsMin Marge inferieur estimee des credits obtenus
     * @param pronosticCreditsMax Marge superieur estimee des credits obtenus
     */
    SemestreEtranger(const Semestre& semestre, Cursus* cursus, const EnsCredits& pronosticCreditsMin, const EnsCredits& pronosticCreditsMax):\
        Inscription(tsemestreEtranger, semestre, cursus), _pronosticCreditsMin(pronosticCreditsMin), _pronosticCreditsMax(pronosticCreditsMax){}

//SETTERS
    void setCreditsMin(const EnsCredits pronosticCreditsMin) { _pronosticCreditsMin = pronosticCreditsMin; }
    void setCreditsMax(const EnsCredits pronosticCreditsMax) { _pronosticCreditsMax = pronosticCreditsMax; }
    void setCreditsObtenus(const EnsCredits credits)         { _creditsObtenus      = credits;             }


//GETTERS
    EnsCredits getCreditsMin()  { return _pronosticCreditsMin;  }
    EnsCredits getCreditsMax()  { return _pronosticCreditsMax;  }
    EnsCredits getCredits()     { return _creditsObtenus;       }

    void serialize(QDataStream& stream) const;
    void unserialize(QDataStream& stream);


    //static void initSemestreEtrangerFileSystem();
    //friend QDataStream& operator<< (QDataStream&, const SemestreEtranger&);
    //friend QDataStream& operator>> (QDataStream&, SemestreEtranger&);

};

Q_DECLARE_METATYPE(SemestreEtranger)
/*
Q_DECLARE_METATYPE(SemestreEtranger)
QDataStream& operator<< (QDataStream& out, const SemestreEtranger& Valeur);
QDataStream& operator>> (QDataStream& in, SemestreEtranger& Valeur);*/


#endif // SEMESTREETRANGER_H
