#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "enscredits.h"

int main(int argc, char *argv[])
{
    EnsCredits ens1(6, 0, 3, 4, 2, 1);
    EnsCredits ens2(4, 10, 7, 6, 8, 9);
    //ens1 /= 2;
    //EnsCredits ens3 = (ens2 + ens1)/2;
    ens1 = ens2;
    if(ens1 == ens2)
        std::cout<<"Kiff"<<std::endl;
    ens1.afficheEnsCredits();
    std::cout<<"Swag de poule !"<<std::endl;
    return 0;
}
