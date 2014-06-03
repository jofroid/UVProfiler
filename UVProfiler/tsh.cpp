#include "tsh.h"

TSH::TSH(const QString n, const QString c, const Saison s, const unsigned int credits, const LigneTSH ligneTSH, const ColonneTSH colonneTSH) : UV::UV(n, c, s), _ligneTSH(ligneTSH), _colonneTSH(colonneTSH)
{
    getCredit().setTSH(credits);
}

const QString TSH::getLigneTSH(){
    switch(_ligneTSH){
    case 0: return "Concevoir"; break;
    case 1: return "Communiquer"; break;
    case 2: return "OrganiserManager"; break;
    }
}
const QString TSH::getColonneTSH(){
    switch(_colonneTSH){
    case 0: return "DemarchesEtPratique"; break;
    case 1: return "Connaissances"; break;
    }
}

void TSH::setLigneTSH(const QString& ligneTSH){
    if(ligneTSH == "Concevoir")
        _ligneTSH = Concevoir;
    else if(ligneTSH == "Communiquer")
        _ligneTSH = Communiquer;
    else if(ligneTSH == "OrganiserManager")
        _ligneTSH = OrganiserManager;
    else
        UTProfilerException (QString("erreur TSH : la ligne ")+ligneTSH+QString(" n'existe pas"));
}

void TSH::setColonneTSH(const QString& colonneTSH){
    if(colonneTSH == "DemarchesEtPratiques")
        _colonneTSH = DemarchesEtPratiques;
    else if(colonneTSH == "Connaissances")
        _colonneTSH = Connaissances;
    else
        UTProfilerException (QString("erreur TSH : la colonne ")+colonneTSH+QString(" n'existe pas"));
}

