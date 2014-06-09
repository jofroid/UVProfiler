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
    QMap<QString, Inscription*> _inscriptions;

    void load();
    void loadFromDB();
    void loadFromFile();
public:
    Dossier(QString username);

    // Setters
    void setSemestrePB  (unsigned int a)    { _semestrePB   = a;        }
    void setSemestreB   (unsigned int a)    { _semestreB    = a;        }
    void setPostBac     (PostBac* postBac)  { _postBac      = postBac;  }
    void setBranche     (Branche* branche)  { _branche      = branche;  }
    void setFiliere     (Filiere* filiere)  { _filiere      = filiere;  }
    void setMineur      (Filiere* mineur)   { _mineur       = mineur;   }
                // Dois-je mettre un test pour vérifier que c'est un mineur ?

    // Getters
    unsigned int getSemestrePB() { return _semestrePB; }
    unsigned int getSemestreB()  { return _semestreB; }
    PostBac&     getPostBac()    { return *_postBac; }
    Branche&     getBranche()    { return *_branche; }
    Filiere&     getFiliere()    { return *_filiere; }
    Filiere&     getMineur()     { return *_mineur; }
    Inscription& getInscription(const QString& semestre) { return *_inscriptions[semestre]; }

    // Other functions

};

#endif // DOSSIER_H
