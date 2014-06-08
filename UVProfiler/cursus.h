#ifndef CURSUS_H
#define CURSUS_H

#include "enscredits.h"
#include <iostream>
#include <QString>


class Cursus
{
protected:
    QString _nom;
    QString _code;
    QString _description;
    EnsCredits _creditsNecessaires;
public:
    Cursus(const QString& nom, const QString& code, const QString& description, const EnsCredits creditNecessaires=EnsCredits() ): _nom(nom), _code(code), _description(description), _creditsNecessaires(creditNecessaires) {}
    virtual ~Cursus()=0; //comme je n'ai pas de méthode virtuelle pour le moment, le destructeur fera l'affaire
    void setNom(const QString& nom)                     {_nom = nom;}
    void setCode(const QString& code)                   {_code = code;}
    void setDescription(const QString& description)     {_description = description;}
    void setEnsCredits(const EnsCredits& creditsNedessaires){_creditsNecessaires = creditsNedessaires;}
	
	QString getNom() { return _nom; }
};



#endif // CURSUS_H
