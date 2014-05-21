#ifndef CURSUS_H
#define CURSUS_H
#include <iostream>
#include "enscredits.h"


class Cursus
{
private:
    std::string _nom;
    std::string _code;
    std::string _description;
    EnsCredits _creditsNecessaires;
public:
    Cursus(const std::string& n, const std::string& c, const std::string& d, const EnsCredits cn=0 ): _nom(n), _code(c), _description(d), _creditsNecessaires(cn){}
    virtual ~Cursus()=0; //comme je n'ai pas de méthode virtuelle pour le moment, le destructeur fera l'affaire
    void setNom(const std::string& n)           {_nom = n;}
    void setCode(const std::string& c)          {_code = c;}
    void setDescription(const std::string& d)   {_description = d;}
    void setEnsCredits(const EnsCredits& cn)    {_creditsNecessaires = cn;}
};



#endif // CURSUS_H
