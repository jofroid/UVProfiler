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
protected:
    QString _nom;
    QString _code;
    QString _description;
    Saison _saison;
    //QVector<QString> _theme; // plus simple à gérer qu'un tableau de string.
    //G:En relisant le sujet, j'ai l'impression qu'on se prend la tete pour rien. Je propose une bete liste d'UV désirees et non desirees pour l'autocompletion
    QVector<Cursus*> _cursusAssocies;
    EnsCredits _creditsDelivres;
public:
    UV();
    virtual ~UV() =0;

    // Setters
    void setCredits(EnsCredits credits)      { _creditsDelivres = credits;    }
    void setNom(QString nom)                 { _nom = nom;                   }
    void setCode(QString code)               { _code = code;                 }
    void setDescription(QString description) { _description = description;   }
    void setSaison(Saison saison)            { _saison = saison;             }
    //void addTheme(QString theme)             { _theme.push_back( theme);     }
    /*void removeTheme(QString theme) {
            int i = _theme.indexOf(theme);   // On trouve la première occurence de theme
            if(i!=-1)                        // Donc s'il y a une occurence de theme dans le QVector
                _theme.remove(i);            // On la supprime du QVector
        }
    */
    void addCursus(Cursus* cursus)           { _cursusAssocies.push_back(cursus); }
    void removeCursus(Cursus* cursus) {
            int i = _cursusAssocies.indexOf(cursus);
            if(i!=-1)
                _cursusAssocies.remove(i);
    }

    // Getters
    QString getNom()             { return _nom;            }
    QString getCode()            { return _code;           }
    QString getDescription()     { return _description;    }
    Saison getSaison()           { return _saison;         }
    //QVector<QString> getTheme()  { return _theme;          }
    QVector<Cursus*> getCursus() { return _cursusAssocies; }
    EnsCredits getCredit()       { return _creditsDelivres; }
};

#endif // UV_H
