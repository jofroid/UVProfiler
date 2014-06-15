#ifndef DOSSIER_H
#define DOSSIER_H

/**
  * @file dossier.h
  */
#include <QtSql>
#include <QMap>
#include <QString>
#include "dossierdata.h"
#include "postbac.h"
#include "branche.h"
#include "filiere.h"
#include "inscription.h"
#include "cursusmanager.h"
#include "enscredits.h"
#include "semestre.h"

class DossierData;

class CursusManager;
/**
 * @brief The Dossier class Classe representant le dossier d'un etudiant
 */
class Dossier
{
private:
    /**
     * @brief _semestrePB Numero du semestre PostBac courant ou apres avoir ete termine
     */
    unsigned int _semestrePB;
    /**
     * @brief _semestreB Numero du semestre PostBac courant
     */
    unsigned int _semestreB;
    /**
     * @brief _login Login de l'etudiant sont le dossier appartient
     */
    QString _login;
    /**
     * @brief _postBac Pointe sur le cursus postbac en cours
     */
    PostBac* _postBac;
    /**
     * @brief _branche Pointe sur la branche en cours
     */
    Branche* _branche;
    /**
     * @brief _filiere Pointe sur la filiere en cours
     */
    Filiere* _filiere;
    /**
     * @brief _mineur Pointe sur le mineur en cours
     */
    Filiere* _mineur;
    /**
     * @brief _inscriptions Map des inscriptions du dossier
     */
    QMap<Semestre, Inscription*> _inscriptions;
    /**
     * @brief _creditsTotauxPostBac Total des credits obtenus en cursus postbac
     */
    EnsCredits _creditsTotauxPostBac;
    /**
     * @brief _creditsTotauxBranche Total des credits obtenus en branche
     */
    EnsCredits _creditsTotauxBranche;
    /**
     * @brief _creditsTotauxBrancheFiliere Total des credits obtenus en filière
     */
    EnsCredits _creditsTotauxFiliere;
    /**
     * @brief load Charge un dossier soit depuis un fichier, soit depuis la BDD
     */
    void load();
    /**
     * @brief loadFromDB Charge un dossier depuis la DB
     */
    void loadFromDB();
    /**
     * @brief loadFromFile Charge un dossier depuis un fichier
     */
    void loadFromFile();
    /**
     * @brief loadFromExample Charge des valeurs prédéfinies
     */
    void loadFromExample();
    /**
     * @brief updateCreditsPostBac Met a jour le nombre de credits postbac obtenu
     */
    void updateCreditsPostBac();
    /**
     * @brief updateCreditsBranche Met a jour le nombre de credits branche obtenu
     */
    void updateCreditsBranche();
    /**
     * @brief updateCreditsFiliere Met a jour le nombre de credits de filière obtenu
     */
    void updateCreditsFiliere();
public:
    /**
     * @brief Dossier Constructeur de base
     * @param username login de l'etudiant
     */
    Dossier(QString username);
    Dossier(DossierData& data);

    // Setters
    void setSemestrePB  (unsigned int a)    { _semestrePB   = a;        }
    void setSemestreB   (unsigned int a)    { _semestreB    = a;        }
    void setPostBac     (PostBac* postBac)  { _postBac      = postBac;  }
    void setBranche     (Branche* branche)  { _branche      = branche;  }
    void setFiliere     (Filiere* filiere)  { _filiere      = filiere;  }
    void setMineur      (Filiere* mineur)   { _mineur       = mineur;   }
    void setCreditsPostBac(const EnsCredits& credits);

    // Getters
    QString      getlogin()       { return _login;           }
    unsigned int getSemestrePB()  { return _semestrePB;      }
    unsigned int getSemestreB()   { return _semestreB;       }
    PostBac&     getPostBac()     { return *_postBac;        }
    Branche&     getBranche()     { return *_branche;        }
    Filiere&     getFiliere()     { return *_filiere;        }
    Filiere&     getMineur()      { return *_mineur;         }
    Inscription& getInscription(const Semestre& semestre) { return *_inscriptions[semestre]; }
    QMap<Semestre, Inscription*> getInscriptions() { return _inscriptions; }
    EnsCredits   getTotalCreditsPostBac() { return _creditsTotauxPostBac; }
    EnsCredits   getTotalCreditsBranche() { return _creditsTotauxBranche; }
    EnsCredits   getTotalCreditsFiliere() { return _creditsTotauxFiliere; }

    // Other functions
    /**
     * @brief addInscription Ajoute une inscription au dossier
     * @param inscription inscription a ajouter
     */
    void addInscription(Inscription* inscription) { _inscriptions.insert(inscription->getSemestre(), inscription); }
    /**
     * @brief updateCredits Met a jour les credits obtenus
     */
    void updateCredits(); // met à jour la valeur de _creditsTotauxPostBac et de _creditsTotauxBranche à partir
                          //    des Inscriptions

};

#endif // DOSSIER_H
