#ifndef DOSSIER_H
#define DOSSIER_H

#include <QtSql>
#include <QMap>
#include <QString>
#include "postbac.h"
#include "branche.h"
#include "filiere.h"
#include "inscription.h"
#include "cursusmanager.h"
#include "enscredits.h"
#include "semestre.h"

class Dossier
{
private:
    unsigned int _semestrePB; // semestre Post-Bac
    unsigned int _semestreB;  // semestre Branche
    QString _login;
    PostBac* _postBac;
    Branche* _branche;
    Filiere* _filiere;
    Filiere* _mineur;
    QMap<Semestre, Inscription*> _inscriptions;
    EnsCredits _creditsTotauxPostBac;// Nombre de crédits donnés par toutes ses UVs
    EnsCredits _creditsTotauxBranche;

    void load();
    void loadFromDB();
    void loadFromFile();
    void updateCreditsPostBac();
    void updateCreditsBranche();
public:
    Dossier(QString username);

    // Setters
    void setSemestrePB  (unsigned int a)    { _semestrePB   = a;        }
    void setSemestreB   (unsigned int a)    { _semestreB    = a;        }
    void setPostBac     (PostBac* postBac)  { _postBac      = postBac;  }
    void setBranche     (Branche* branche)  { _branche      = branche;  }
    void setFiliere     (Filiere* filiere)  { _filiere      = filiere;  }
    void setMineur      (Filiere* mineur)   { _mineur       = mineur;   } // Dois-je mettre un test pour vérifier que c'est un mineur ?
    void setCreditsPostBac(const EnsCredits& credits);

    void addInscription(Inscription* inscription) { _inscriptions.insert(inscription->getSemestre(), inscription); }

    // Getters
    unsigned int getSemestrePB()  { return _semestrePB;      }
    unsigned int getSemestreB()   { return _semestreB;       }
    PostBac&     getPostBac()     { return *_postBac;        }
    Branche&     getBranche()     { return *_branche;        }
    Filiere&     getFiliere()     { return *_filiere;        }
    Filiere&     getMineur()      { return *_mineur;         }
    Inscription& getInscription(const Semestre& semestre) { return *_inscriptions[semestre]; }
    EnsCredits   getTotalCreditsPostBac() { return _creditsTotauxPostBac; }
    EnsCredits   getTotalCreditsBranche() { return _creditsTotauxBranche; }

    // Other functions
    void updateCredits(); // met à jour la valeur de _creditsTotauxPostBac et de _creditsTotauxBranche à partir
                          //    des Inscriptions

};

#endif // DOSSIER_H
