#include "dossierdata.h"

DossierData::DossierData(Dossier source): _login(source.getlogin()), _semestreB(source.getSemestreB()),\
    _semestrePB(source.getSemestrePB()), _postBac(""), _branche(""), _filiere(""), _mineur("")
{
    if(&source.getPostBac())
        _postBac = source.getPostBac().getCode();
    if(&source.getBranche())
        _branche = source.getBranche().getCode();
    if(&source.getFiliere())
        _filiere = source.getFiliere().getCode();
    if(&source.getMineur())
        _mineur = source.getMineur().getCode();
    source.updateCredits();
    _creditsTotauxBranche = source.getTotalCreditsBranche();
    _creditsTotauxPostBac = source.getTotalCreditsPostBac();
    _creditsTotauxFiliere = source.getTotalCreditsFiliere();
}

DossierData::DossierData(): _login(""), _semestreB(0), _semestrePB(0), _postBac(""), _branche(""), _filiere(""), _mineur("")
    {}

void DossierData::initDossierDataFileSystem() {
    qRegisterMetaTypeStreamOperators<DossierData>("DossierData");
    qMetaTypeId<DossierData>(); // Teste la validité de la classe DossierData
}

QDataStream& operator<< (QDataStream& out, const DossierData& Valeur)
{
    out << Valeur._login                << Valeur._branche
        << Valeur._creditsTotauxBranche << Valeur._creditsTotauxFiliere
        << Valeur._creditsTotauxPostBac << Valeur._filiere
        << Valeur._mineur               << Valeur._postBac
        << Valeur._semestreB            << Valeur._semestrePB;

    return out;
}
QDataStream& operator>> (QDataStream& in, DossierData& Valeur)
{
    in >> Valeur._login; in                 >> Valeur._branche; in              >> Valeur._creditsTotauxBranche;
    in >> Valeur._creditsTotauxFiliere; in  >> Valeur._creditsTotauxPostBac; in >> Valeur._filiere;
    in >> Valeur._mineur; in                >> Valeur._postBac; in              >> Valeur._semestreB;
    in >> Valeur._semestrePB;

    return in;
}


