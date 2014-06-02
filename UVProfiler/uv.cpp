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

