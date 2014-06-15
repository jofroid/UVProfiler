#ifndef SELECTIONPARMI_H
#define SELECTIONPARMI_H

/**
  * @file selectionparmi.h
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
 * @brief The SelectionParmi class Classe representant la contrainted'une selection d'UVs a choisir parmi une liste. Herite de CiteresValidationFiliere
 */
class SelectionParmi : public CriteresValidationFiliere
{
private:
    /**
     * @brief _uvsNecessaires Map des differentes UVs disponibles
     */
    QMap<QString, UV*> _uvsNecessaires;
    /**
     * @brief _nbUvsNecessaires Nombre d'UVs necessaires pour la validation
     */
    unsigned int _nbUvsNecessaires;
public:
    /**
     * @brief SelectionParmi Constructeur de base
     * @param cursus Cursus associe
     * @param nbUvsNecessaires Nombre d'UVs necessaires pour la validation
     */
    SelectionParmi(Cursus* cursus, unsigned int nbUvsNecessaires) :\
        _nbUvsNecessaires(nbUvsNecessaires) {}
    /**
     * @brief validation Test de la validation du critere
     * @return
     */
    bool validation();

    /**
     * @brief addUV Ajoute une UV a la liste disponible
     * @param code Code de l'UV a ajouter
     */
    void addUV(QString code);
    /**
     * @brief addUV Ajoute une Uv ala liste disponible
     * @param uv Pointe sur l'UV a ajouter
     */
    void addUV(UV* uv);

    /**
     * @brief removeUV Supprime une UV de la liste
     * @param code Code de l'UV a supprimer
     */
    void removeUV(QString code);
    /**
     * @brief removeUV Supprime une UV de la liste
     * @param uv Pointe sur l'UV a supprimer
     */
    void removeUV(UV* uv);
};

#endif // SELECTIONPARMI_H
