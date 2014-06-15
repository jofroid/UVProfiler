#ifndef CRITERESVALIDATIONFILIERE_H
#define CRITERESVALIDATIONFILIERE_H

/**
 * @file criteresvalidationfiliere.h
 */

/**
 * @brief The CriteresValidationFiliere class Classe representant un validateur de criteres
 */
class CriteresValidationFiliere
{
public:
    /**
     * @brief CriteresValidationFiliere Constructeur de base
     */
    CriteresValidationFiliere();

    /**
     * @brief validation Verifie une liste de criteres à valider
     * @return true si tous les criteres sont valides, false sinon
     */
    virtual bool validation()=0;
};

#endif // CRITERESVALIDATIONFILIERE_H
