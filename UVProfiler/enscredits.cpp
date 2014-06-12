#include "enscredits.h"
#include <iostream>

EnsCredits::EnsCredits(const EnsCredits& copie) {
    _creditsCS  = copie._creditsCS;
    _creditsTM  = copie._creditsTM;
    _creditsTSH = copie._creditsTSH;
    _creditsSP  = copie._creditsSP;
}

void EnsCredits::initEnsCreditsSystem() {
    qRegisterMetaTypeStreamOperators<EnsCredits>("EnsCredits");
    qMetaTypeId<EnsCredits>(); // Teste la validité de la classe EnsCredits
}

void EnsCredits::afficheEnsCredits() const{
    std::cout<<"CS: "<<_creditsCS<<std::endl;
    std::cout<<"TM: "<<_creditsTM<<std::endl;
    std::cout<<"TSH: "<<_creditsTSH<<std::endl;
    std::cout<<"SP: "<<_creditsSP<<std::endl;
}

EnsCredits EnsCredits::operator+(const EnsCredits& source) const{
    unsigned int CS, TM, TSH, SP;
    CS = _creditsCS + source.CS();
    TM = _creditsTM + source.TM();
    TSH = _creditsTSH + source.TSH();
    SP = _creditsSP + source.SP();

    return EnsCredits(CS, TM, TSH, SP);
}

EnsCredits& EnsCredits::operator+=(const EnsCredits& right){
    _creditsCS += right.CS();
    _creditsTM += right.TM();
    _creditsTSH += right.TSH();
    _creditsSP += right.SP();

    return *this;
}

EnsCredits EnsCredits::operator/(const unsigned int denominateur) const{
    unsigned int CS, TM, TSH, SP;
    CS  = _creditsCS  / denominateur;
    TM  = _creditsTM  / denominateur;
    TSH = _creditsTSH / denominateur;
    SP  = _creditsSP  / denominateur;

    return EnsCredits(CS, TM, TSH, SP);
}

EnsCredits& EnsCredits::operator/=(const unsigned int denominateur){
    _creditsCS  /= denominateur;
    _creditsTM  /= denominateur;
    _creditsTSH /= denominateur;
    _creditsSP  /= denominateur;

    return *this;
}

void EnsCredits::operator=(const EnsCredits& right){
    _creditsCS  = right.CS();
    _creditsTM  = right.TM();
    _creditsTSH = right.TSH();
    _creditsSP  = right.SP();
}

bool EnsCredits::operator==(const EnsCredits& right) const{
    return _creditsCS  == right.CS()
        && _creditsTM  == right.TM()
        && _creditsTSH == right.TSH()
        && _creditsSP  == right.SP();
}

std::ostream& operator<<(std::ostream& out, const EnsCredits& Valeur) {
    out << "Credits CS: " << Valeur._creditsCS
       <<"\nCredits TM: " << Valeur._creditsTM
       <<"\nCredits TSH:" << Valeur._creditsTSH
       <<"\nCredits SP: " << Valeur._creditsSP;
}

QDataStream& operator<< (QDataStream& out, const EnsCredits& Valeur) // Utilisée pour stocker dans un fichier
{
    out << Valeur._creditsCS
        << Valeur._creditsTM
        << Valeur._creditsTSH
        << Valeur._creditsSP;

    return out;
}
QDataStream& operator>> (QDataStream& in, EnsCredits& Valeur)
{
    in >> Valeur._creditsCS;
    in >> Valeur._creditsTM;
    in >> Valeur._creditsTSH;
    in >> Valeur._creditsSP;

    return in;
}
