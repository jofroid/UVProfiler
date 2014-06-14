#ifndef ENSCREDITS_H
#define ENSCREDITS_H

/**
  * @file enscredits.h
  */
#include "UVProfiler.h"
#include <QVariant>

/**
 * @brief The EnsCredits class Classe representant un ensemble de credits de differents types
 */
class EnsCredits
{
private:
    /**
     * @brief _creditsCS Nombre de credits CS
     */
    unsigned int _creditsCS;
    /**
     * @brief _creditsTM Nombre de credits TM
     */
    unsigned int _creditsTM;
    /**
     * @brief _creditsTSH Nombre de credits TSH
     */
    unsigned int _creditsTSH;
    /**
     * @brief _creditsSP Nombre de credits SP
     */
    unsigned int _creditsSP;

public:
    /**
     * @brief EnsCredits Constructeur de base
     * @param CS Nombre de credits CS
     * @param TM Nombre de credits TM
     * @param TSH Nombre de credits TSH
     * @param SP Nombre de credits SP
     */
    EnsCredits(unsigned int CS=0, unsigned int TM=0, unsigned int TSH=0, unsigned int SP=0)
        :_creditsCS(CS), _creditsTM(TM), _creditsTSH(TSH), _creditsSP(SP) {}
    /**
     * @brief EnsCredits Constructeur de recopie
     * @param copie EnsCredit a recopier
     */
    EnsCredits(const EnsCredits& copie);
    ~EnsCredits() {}

    /*Setters*/
    void setCS(unsigned int i)      {   _creditsCS = i;     }
    void setTM(unsigned int i)      {   _creditsTM = i;     }
    void setTSH(unsigned int i)     {   _creditsTSH = i;    }
    void setSP(unsigned int i)      {   _creditsSP = i;     }

    /*Getters*/
    unsigned int CS() const         {   return _creditsCS;  }
    unsigned int TM() const         {   return _creditsTM;  }
    unsigned int TSH() const        {   return _creditsTSH; }
    unsigned int SP() const         {   return _creditsSP;  }

    /**
     * @brief initEnsCreditsSystem Teste la validité de la classe EnsCredits
     */
    static void initEnsCreditsSystem();

    /**
     * @brief afficheEnsCredits Affiche un ensemble de credits
     */
    void afficheEnsCredits() const;
    /**
     * @brief operator + Surcharge de l'operateur +
     * @param source
     * @return Une reference de type EnsCredits resultat de l'operation
     */
    EnsCredits operator+(const EnsCredits& source) const;
    /**
     * @brief operator += Surcharge de l'operateur +=
     * @param right
     * @return Une reference de type EnsCredits resultat de l'operation
     */
    EnsCredits& operator+=(const EnsCredits& right);
    /**
     * @brief operator / Surcharge de l'operateur /
     * @param denominateur
     * @return Un objet de type EnsCredits resultat de l'operation
     */
    EnsCredits operator/(const unsigned int denominateur) const;
    /**
     * @brief operator /= Surcharge de l'operateur /=
     * @param denominateur
     * @return Une reference de type EnsCredits resultat de l'operation
     */
    EnsCredits& operator/=(const unsigned int denominateur);
    /**
     * @brief operator = Surcharge de l'operateur de recopie =
     * @param right
     */
    void operator=(const EnsCredits& right);
    /**
     * @brief operator == Surcharge de l'operateur ==
     * @param right
     * @return true si egalite, false sinon
     */
    bool operator==(const EnsCredits& right) const;

    friend std::ostream& operator<<(std::ostream&, const EnsCredits& );

    friend QDataStream& operator<< (QDataStream&, const EnsCredits&);
    friend QDataStream& operator>> (QDataStream&, EnsCredits&);
};

std::ostream& operator<<(std::ostream& out, const EnsCredits& Valeur);

Q_DECLARE_METATYPE(EnsCredits)
QDataStream& operator<< (QDataStream& out, const EnsCredits& Valeur);
QDataStream& operator>> (QDataStream& in, EnsCredits& Valeur);

#endif // ENSCREDITS_H
