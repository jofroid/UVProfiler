#include "enscredits.h"
#include <iostream>

void EnsCredits::afficheEnsCredits() const{
    std::cout<<"CS: "<<_creditsCS<<std::endl;
    std::cout<<"TM: "<<_creditsTM<<std::endl;
    std::cout<<"TSH: "<<_creditsTSH<<std::endl;
    std::cout<<"SP: "<<_creditsSP<<std::endl;
    std::cout<<"PCB: "<<_creditsPCB<<std::endl;
    std::cout<<"PCF: "<<_creditsPCF<<std::endl;
}

EnsCredits EnsCredits::operator+(const EnsCredits& source) const{
    unsigned int CS, TM, TSH, SP, PCB, PCF;
    CS = _creditsCS + source.CS();
    TM = _creditsTM + source.TM();
    TSH = _creditsTSH + source.TSH();
    SP = _creditsSP + source.SP();
    PCB = _creditsPCB + source.PCB();
    PCF = _creditsPCF + source.PCF();

    return EnsCredits(CS, TM, TSH, SP, PCB, PCF);
}

EnsCredits& EnsCredits::operator+=(const EnsCredits& right){
    _creditsCS += right.CS();
    _creditsTM += right.TM();
    _creditsTSH += right.TSH();
    _creditsSP += right.SP();
    _creditsPCB += right.PCB();
    _creditsPCF += right.PCF();

    return *this;
}

EnsCredits EnsCredits::operator/(const unsigned int denominateur) const{
    unsigned int CS, TM, TSH, SP, PCB, PCF;
    CS = _creditsCS / denominateur;
    TM = _creditsTM / denominateur;
    TSH = _creditsTSH / denominateur;
    SP = _creditsSP / denominateur;
    PCB = _creditsPCB / denominateur;
    PCF = _creditsPCF / denominateur;

    return EnsCredits(CS, TM, TSH, SP, PCB, PCF);
}

EnsCredits& EnsCredits::operator/=(const unsigned int denominateur){
    _creditsCS /= denominateur;
    _creditsTM /= denominateur;
    _creditsTSH /= denominateur;
    _creditsSP /= denominateur;
    _creditsPCB /= denominateur;
    _creditsPCF /= denominateur;

    return *this;
}

void EnsCredits::operator=(const EnsCredits& right){
    _creditsCS = right.CS();
    _creditsTM = right.TM();
    _creditsTSH = right.TSH();
    _creditsSP = right.SP();
    _creditsPCB = right.PCB();
    _creditsPCF = right.PCF();
}

bool EnsCredits::operator==(const EnsCredits& right) const{
    return _creditsCS == right.CS()
    && _creditsTM == right.TM()
    && _creditsTSH == right.TSH()
    && _creditsSP == right.SP()
    && _creditsPCB == right.PCB()
    && _creditsPCF == right.PCF();
}


