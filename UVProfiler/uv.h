#ifndef UV_H
#define UV_H

#include "cursus.h"
#include "enscredits.h"
#include "branche.h"
#include <QString>
#include <QVector>

using namespace std;

enum Saison { P, A, PA, X };

class UV
{
private:
    QString _nom;
    QString _code;
    Saison _saison;
    EnsCredits _creditsDelivres;
public:
    UV(const QString nom, const QString code, const Saison saison): _nom(nom), _code(code), _saison(saison), _creditsDelivres(0){}

    // Setters
    void setCredits(const EnsCredits credits)   { _creditsDelivres = credits;    }
    void setNom(const QString& nom)             { _nom = nom;                    }
    void setCode(const QString& code)           { _code = code;                  }
    void setSaison(Saison saison)               { _saison = saison;              }
    virtual void setLigneTSH(const LigneTSH ligneTSH)=0;
    virtual void setColonneTSH(const ColonneTSH colonneTSH)=0;
    virtual void setLigneTSH(const QString& ligneTSH)=0;
    virtual void setColonneTSH(const QString& colonneTSH)=0;

    // Getters
    const QString& getNom()const            { return _nom;            }
    const QString& getCode()const           { return _code;           }
    QString getSaison()const;
    static Saison getSaison(const QString& saison);
    const EnsCredits& getCredit()const      { return _creditsDelivres;}
    EnsCredits& getCredit()                 { return _creditsDelivres;}
    virtual const QString getCategorie()=0;
    virtual const QString getColonneTSH()=0;
    virtual const QString getLigneTSH()=0;

    //Autres méthodes

};

#endif // UV_H
