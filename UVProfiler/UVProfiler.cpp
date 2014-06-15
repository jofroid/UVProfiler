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

QDataStream& operator<<(QDataStream& stream, Notes const& valeur) {
    stream<<(int)valeur;
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Notes& valeur) {
    int a(0);
    stream >> a;
    valeur =(Notes)a;
    return stream;
}
