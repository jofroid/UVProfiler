#ifndef ENSCREDITS_H
#define ENSCREDITS_H

class EnsCredits
{
private:
    unsigned int _creditsCS;
    unsigned int _creditsTM;
    unsigned int _creditsTSH;
    unsigned int _creditsSP;

public:
    EnsCredits():_creditsCS(0), _creditsTM(0), _creditsTSH(0), _creditsSP(0){}
    EnsCredits(unsigned int CS=0, unsigned int TM=0, unsigned int TSH=0, unsigned int SP=0)
        :_creditsCS(CS), _creditsTM(TM), _creditsTSH(TSH), _creditsSP(SP){}
    void setCS(unsigned int i)      {   _creditsCS = i;     }
    void setTM(unsigned int i)      {   _creditsTM = i;     }
    void setTSH(unsigned int i)     {   _creditsTSH = i;    }
    void setSP(unsigned int i)      {   _creditsSP = i;     }
    unsigned int CS() const   {   return _creditsCS;  }
    unsigned int TM() const   {   return _creditsTM;  }
    unsigned int TSH() const  {   return _creditsTSH; }
    unsigned int SP() const   {   return _creditsSP;  }


    void afficheEnsCredits() const;
    EnsCredits operator+(const EnsCredits& source) const;
    EnsCredits& operator+=(const EnsCredits& right);
    EnsCredits operator/(const unsigned int denominateur) const;
    EnsCredits& operator/=(const unsigned int denominateur);
    void operator=(const EnsCredits& right);
    bool operator==(const EnsCredits& right) const;
};


#endif // ENSCREDITS_H
