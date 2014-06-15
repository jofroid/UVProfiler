#ifndef CURSUS_H
#define CURSUS_H

/**
 * @file cursus.h
 */
#include "enscredits.h"
#include <QVariant>
#include <iostream>
#include <QString>

/**
 * @brief The Cursus class Classe abstraite representant les cursus
 */
class Cursus
{
protected:
    /**
     * @brief _nom Nom du cursus
     */
    QString _nom;
    /**
     * @brief _code Code du cursus
     */
    QString _code;
    /**
     * @brief _description Description du cursus
     */
    QString _description;
    /**
     * @brief _creditsNecessaires Ensemble de credits necessaire a la validation du cursus
     */
    EnsCredits _creditsNecessaires;
public:
    /**
     * @brief Cursus Constructeur de base, necessaire pour la récupération à partir de fichier
     */
    Cursus() : _nom(""), _code(""), _description(""), _creditsNecessaires(EnsCredits() ) {}

    /**
     * @brief Cursus Constructeur permettant d'initialiser tous les attributs de la classe
     * @param nom Nom du cursus
     * @param code Code du cursus
     * @param description Description du cursus
     * @param creditNecessaires Ensemble de credits necessaires a la validation du cursus
     */
    Cursus(const QString& nom, const QString& code, const QString& description, const EnsCredits creditNecessaires=EnsCredits() ):\
        _nom(nom), _code(code), _description(description), _creditsNecessaires(creditNecessaires) {}

    /**
     * @brief ~Cursus Destructeur
     */
    ~Cursus();

    /*Getters*/
    void setNom(const QString& nom)                     { _nom = nom;}
    void setCode(const QString& code)                   { _code = code;}
    void setDescription(const QString& description)     { _description = description;}
    void setEnsCredits(const EnsCredits& creditsNedessaires){_creditsNecessaires = creditsNedessaires;}
	
    /*Setters*/
    QString getNom()                    { return _nom;                  }
    QString getCode()                   { return _code;                 }
    QString getDescription()            { return _description;          }
    EnsCredits getCreditsNecessaires()  { return _creditsNecessaires;   }

    static void initCursusFileSystem();
    virtual void serialize(QDataStream& stream) const;
    virtual void unserialize(QDataStream& stream);
};

Q_DECLARE_METATYPE(Cursus)
QDataStream& operator<< (QDataStream& out, const Cursus& valeur);
QDataStream& operator>> (QDataStream& in, Cursus& valeur);



#endif // CURSUS_H
