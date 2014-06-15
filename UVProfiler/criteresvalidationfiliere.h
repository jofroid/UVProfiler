#ifndef CRITERESVALIDATIONFILIERE_H
#define CRITERESVALIDATIONFILIERE_H

#include <QVariant>

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
    virtual bool validation() {}

    static void initCriteresFileSystem();
    virtual void serialize(QDataStream& stream) const;
    virtual void unserialize(QDataStream& stream);
};

Q_DECLARE_METATYPE(CriteresValidationFiliere)
QDataStream& operator<< (QDataStream& out, const CriteresValidationFiliere& valeur);
QDataStream& operator>> (QDataStream& in, CriteresValidationFiliere& valeur);

#endif // CRITERESVALIDATIONFILIERE_H
