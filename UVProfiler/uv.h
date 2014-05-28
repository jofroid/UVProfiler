#ifndef UV_H
#define UV_H

#include "cursus.h"
#include "enscredits.h"
#include <QString> // J'utilise des QString, puisque de toute façon faudra convertir les strings pour les utiliser
                   // dans les objets Qt.
#include <QVector>

using namespace std;

enum Saison { P, A, PA, X };
        // faudrait vérifier si ya pas une convention de nommage des enum... (genre commencer par une maj)
        // X signifie que l'UV n'est plus dispo, après modifie si t'as une meilleur valeure à mettre.

class UV
{
private:
    QString _nom;
    QString _code;
    Saison _saison;
    QVector<Cursus*> _cursusAssocies;
    EnsCredits _creditsDelivres;
public:
    UV(const QString n, const QString c, const Saison s): _nom(n), _code(c), _saison(s), _cursusAssocies(0), _creditsDelivres(0){};
    virtual ~UV() =0;

    // Setters
    void setCredits(EnsCredits credits)      { _creditsDelivres = credits;    }
    void setNom(QString nom)                 { _nom = nom;                   }
    void setCode(QString code)               { _code = code;                 }
    void setSaison(Saison saison)            { _saison = saison;             }
    void addCursus(Cursus* cursus)           { _cursusAssocies.push_back(cursus); }
    void removeCursus(Cursus* cursus) {
            int i = _cursusAssocies.indexOf(cursus);
            if(i!=-1)
                _cursusAssocies.remove(i);
    }

    // Getters
    QString getNom()             { return _nom;            }
    QString getCode()            { return _code;           }
    Saison getSaison()           { return _saison;         }
    QVector<Cursus*> getCursus() { return _cursusAssocies; }
    EnsCredits getCredit()       { return _creditsDelivres; }
};

#endif // UV_H
