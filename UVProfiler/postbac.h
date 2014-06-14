#ifndef POSTBAC_H
#define POSTBAC_H

/**
  * @file postbac.h
  */
#include "cursus.h"
#include <QVariant>
#include <QString>

/**
 * @brief The PostBac class Classe representant un cursus de type postbac. Herite de Cursus
 */
class PostBac: public Cursus
{
public:
    /**
     * @brief PostBac Constructeur de base
     */
    PostBac() : Cursus::Cursus() {}
    /**
     * @brief PostBac Constructeur initialisant tous les attributs de l'objet
     * @param nom Nom de postbac
     * @param code Code de postbac
     * @param description Description de postbac
     * @param creditsNecessaires Nombre de credits necessaires a la validation de postbac
     */
    PostBac(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0):\
        Cursus::Cursus(nom, code, description, creditsNecessaires) {}
    /**
     * @brief PostBac Constructeur de recopie
     * @param copie Reference de l'objet PostBac a copier
     */
    PostBac(const PostBac& copie) :\
        Cursus::Cursus(copie._nom, copie._code, copie._description, copie._creditsNecessaires) {}
    void initPostBacSystem();

    friend QDataStream& operator<< (QDataStream&, const PostBac&);
    friend QDataStream& operator>> (QDataStream&, PostBac&);
};

Q_DECLARE_METATYPE(PostBac)
QDataStream& operator<< (QDataStream& out, const PostBac& Valeur);
QDataStream& operator>> (QDataStream& in, PostBac& Valeur);

#endif // POSTBAC_H
