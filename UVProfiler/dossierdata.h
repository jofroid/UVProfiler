#ifndef DOSSIERDATA_H
#define DOSSIERDATA_H

#include <QString>
#include "dossier.h"
#include "enscredits.h"

class Dossier;

class DossierData
{
protected:
    /**
     * @brief _login Login de l'etudiant sont le dossier appartient
     */
    QString _login;
    unsigned int _semestrePB;
    unsigned int _semestreB;
    QString _postBac;
    QString _branche;
    QString _filiere;
    QString _mineur;
public:
    DossierData(Dossier source);
    DossierData();
    DossierData(const DossierData& copie);

    QString      getlogin()       { return _login;           }
    unsigned int getSemestrePB()  { return _semestrePB;      }
    unsigned int getSemestreB()   { return _semestreB;       }
    QString      getPostBac()     { return _postBac;         }
    QString      getBranche()     { return _branche;         }
    QString      getFiliere()     { return _filiere;         }
    QString      getMineur()      { return _mineur;          }

    static void initDossierDataFileSystem();
    friend QDataStream& operator<< (QDataStream&, const DossierData&);
    friend QDataStream& operator>> (QDataStream&, DossierData&);
};

Q_DECLARE_METATYPE(DossierData)
QDataStream& operator<< (QDataStream& out, const DossierData& Valeur);
QDataStream& operator>> (QDataStream& in, DossierData& Valeur);

#endif // DOSSIERDATA_H
