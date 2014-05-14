#ifndef ENSCREDITS_H
#define ENSCREDITS_H

class EnsCredits
{
private:
    unsigned int _creditsCS;
    unsigned int _creditsTM;
    unsigned int _creditsTSH;
    unsigned int _creditsSP;
    unsigned int _creditsPCB;
    unsigned int _creditsPCF;
public:
    EnsCredits():_creditsCS(0), _creditsTM(0), _creditsTSH(0), _creditsSP(0), _creditsPCB(0), _creditsPCF(0){}
    void setCS(unsigned int i)  {   _creditsCS = i;    }
    void setTM(unsigned int i)  {   _creditsTM = i;    }
    void setTSH(unsigned int i) {   _creditsTSH = i;   }
    void setSP(unsigned int i)  {   _creditsSP = i;    }
    void setPCB(unsigned int i) {   _creditsPCB = i;   }
    void setPCF(unsigned int i) {   _creditsPCF = i;    }
};

#endif // ENSCREDITS_H
