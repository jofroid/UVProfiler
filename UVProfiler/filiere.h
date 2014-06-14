#ifndef FILIERE_H
#define FILIERE_H
/**
  * @file filiere.h
  */
#include <QVariant>
#include "cursus.h"
#include "branche.h"

/**
 * @brief The Filiere class Classe representant une filiere. Herite de Cursus
 */
class Filiere : public Cursus
{
protected:
    /**
     * @brief branche Branche associee a la filiere
     */
    Branche* branche;
public:
    /**
     * @brief Filiere Constructeur de base
     */
    Filiere();
    /**
     * @brief Filiere Constructeur initialisant tous les champs de l'objet filiere
     * @param nom Nom de la filiere
     * @param code Code de la filiere
     * @param description Description de la filiere
     * @param creditsNecessaires Nombre de credits PCF necessaire a la validation de la filiere
     */
    Filiere(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0):\
        Cursus::Cursus(nom, code, description, creditsNecessaires) {}
};

#endif // FILIERE_H
