#ifndef BRANCHE_H
#define BRANCHE_H

/*!
 * @file branche.h
 */
#include <QString>
#include <QVariant>
#include "cursus.h"

/**
 * @brief The ColonneTSH enum Categories de la colonne du tableau du profil TSH
 */
enum ColonneTSH { DemarchesEtPratiques, Connaissances     };
/**
 * @brief The LigneTSH enum Categories de la ligne du tableau du profil TSH
 */
enum LigneTSH   { Concevoir, Communiquer, OrganiserManager};

/**
 * @brief The Branche class Classe representant une branche. Herite de la classe Cursus
 */
class Branche: public Cursus
{
private:
    /**
     * @brief _creditsPCB Nombre de credits PCB necessaires pour la validation de la branche
     */
    unsigned int _creditsPCB;
    
public:
    /**
     * @brief Branche Constructeur de base
     */
    Branche(): Cursus( "", "", "") {}

    /**
     * @brief Branche Constructeur initialisant tous les attributs de l'objet
     * @param nom Nom de la branche
     * @param code Code de la branche
     * @param description Description de la branche
     * @param creditsNecessaires Nombre de crédits PCB necessaires
     */
    Branche(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=EnsCredits() ): \
        Cursus(nom, code, description, creditsNecessaires){}

    /**
     * @brief Branche Copie un objet Branche
     * @param copie  Reference sur le Branche à copier
     */
    Branche(const Branche& copie);

    /**
     * @brief ~Branche Destructeur
     */
    ~Branche() {}

    /**
     * @brief initBrancheSystem
     */
    static void initBrancheSystem();
    friend QDataStream& operator<< (QDataStream&, const Branche&);
    friend QDataStream& operator>> (QDataStream&, Branche&);
};

Q_DECLARE_METATYPE(Branche)
QDataStream& operator<< (QDataStream& out, const Branche& Valeur);
QDataStream& operator>> (QDataStream& in, Branche& Valeur);


#endif // BRANCHE_H
