#ifndef UV_H
#define UV_H

/**
  * @file uv.h
  */
#include <QString>
#include <QVector>
#include "cursus.h"
#include "enscredits.h"
#include "branche.h"
#include "semestre.h" // Pour avoir l'enum Saison

using namespace std;

/**
 * @brief The UV class Classe abstraite representant une UV
 */
class UV
{
private:
    /**
     * @brief _nom Nom de l'UV
     */
    QString _nom;
    /**
     * @brief _code Code del'UV
     */
    QString _code;
    /**
     * @brief _saison Saison pendant laquelle l'UV est enseignee
     */
    Saison _saison;
    /**
     * @brief _creditsDelivres Ensmble de credits donne par l'UV
     */
    EnsCredits _creditsDelivres;
public:
    /**
     * @brief UV Constructeur de base
     * @param nom Nom de l'UV
     * @param code Code de l'UV
     * @param saison Saison pendant laquelle l'UV est enseignee
     */
    UV(const QString nom, const QString code, const Saison saison): _nom(nom), _code(code), _saison(saison), _creditsDelivres(0){}

    // Setters
    void setCredits(const EnsCredits credits)   { _creditsDelivres = credits;    }
    void setNom(const QString& nom)             { _nom = nom;                    }
    void setCode(const QString& code)           { _code = code;                  }
    void setSaison(Saison saison)               { _saison = saison;              }

    // Getters
    const QString& getNom()const            { return _nom;            }
    const QString& getCode()const           { return _code;           }
    QString getSaison()const;
    static Saison getSaison(const QString& saison);
    const EnsCredits& getCredit()const      { return _creditsDelivres;}
    EnsCredits& getCredit()                 { return _creditsDelivres;}
    virtual const QString getCategorie() =0;
    virtual const QString getColonneTSH()=0;
    virtual const QString getLigneTSH()  =0;


};

#endif // UV_H
