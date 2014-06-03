#include "uv.h"

QString UV::getSaison()const{
    QString result;
    switch(_saison){
    case 0:
        result = "P";
        break;
    case 1:
        result = "A";
        break;
    case 2:
        result = "PA";
        break;
    case 3:
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

