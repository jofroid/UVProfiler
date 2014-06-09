#include "uv.h"

QString UV::getSaison()const{
    QString result;
    switch(_saison){
    case P:
        result = "P";
        break;
    case A:
        result = "A";
        break;
    case PA:
        result = "PA";
        break;
    case X:
        result = "X";
        break;
    }
    return result;
}

Saison UV::getSaison(const QString& saison){
    if(saison == "P")
        return P;
    else if (saison == "A")
        return A;
    else if (saison == "PA")
        return PA;
    else
        return X;
}

