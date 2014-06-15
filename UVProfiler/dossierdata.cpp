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
}

DossierData::DossierData(): _login(""), _semestreB(0), _semestrePB(0), _postBac(""), _branche(""), _filiere(""), _mineur("")
    {}

DossierData::DossierData(const DossierData& copie): _login(copie._login), _semestreB(copie._semestreB), _semestrePB(copie._semestrePB),\
    _postBac(copie._postBac), _branche(copie._branche), _filiere(copie._filiere), _mineur(copie._mineur) {}

void DossierData::initDossierDataFileSystem() {
    qRegisterMetaTypeStreamOperators<DossierData>("DossierData");
    qMetaTypeId<DossierData>(); // Teste la validité de la classe DossierData
}

QDataStream& operator<< (QDataStream& out, const DossierData& Valeur)
{
    out << Valeur._login                << Valeur._branche
        << Valeur._filiere
        << Valeur._mineur               << Valeur._postBac
        << Valeur._semestreB            << Valeur._semestrePB;

    return out;
}
QDataStream& operator>> (QDataStream& in, DossierData& Valeur)
{
    in >> Valeur._login;        in >> Valeur._branche; in >> Valeur._filiere;
    in >> Valeur._mineur;       in >> Valeur._postBac; in >> Valeur._semestreB;
    in >> Valeur._semestrePB;

    return in;
}


