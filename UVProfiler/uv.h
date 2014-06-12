#ifndef UV_H
#define UV_H

#include <QString>
#include <QVector>
#include "cursus.h"
#include "enscredits.h"
#include "branche.h"
#include "semestre.h" // Pour avoir l'enum Saison

using namespace std;

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
