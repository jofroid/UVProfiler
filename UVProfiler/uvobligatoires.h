#ifndef UVOBLIGATOIRES_H
#define UVOBLIGATOIRES_H

/**
  * @file uvobligatoires.h
  */
#include <QMap>
#include <QString>
#include "criteresvalidationfiliere.h"
#include "cursus.h"
#include "uv.h"
#include "uvmanager.h"
#include "inscription.h"
#include "etudiant.h"

/**
 * @brief The UVObligatoires class Classe representant une liste d'UV a valider. Herite de CriteresValidationFiliere
 */
class UVObligatoires : public CriteresValidationFiliere
{
protected:
    /**
     * @brief _uvObligatoires Map des UVs obligatoires
     */
    QMap<QString, UV*> _uvObligatoires;
public:
    /**
     * @brief UVObligatoires Constructeur de base
     */
    UVObligatoires();
    /**
     * @brief validation Verifie si les criteres de validations sont reunis
     * @return true si toutes les UVs ont ete validee, false sinon
     */
    virtual bool validation();
};

#endif // UVOBLIGATOIRES_H
