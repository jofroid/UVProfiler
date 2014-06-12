#include "UVProfiler.h"


QString& operator<<(QString& out, Saison saison) {
    switch(saison)
    {
        case P:
            out+="P";
            break;
        case Aut:
            out+="A";
            break;
        case PA:
            out+="PA";
            break;
        case X:
            out+="X";
            break;
    }
    return out;
}
