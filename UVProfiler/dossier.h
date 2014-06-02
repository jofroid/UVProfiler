#ifndef DOSSIER_H
#define DOSSIER_H

#include "postbac.h"
#include "branche.h"
#include "filiere.h"
#include "inscription.h"
#include "cursusmanager.h"
#include <QtSql>
#include <QMap>
#include <QString>

class Dossier
{
private:
    int _semestrePB; // semestre Post-Bac
    int _semestreB;  // semestre Branche
    QString _login;
    PostBac* _postBac;
    Branche* _branche;
    Filiere* _filiere;
    Filiere* _mineur;
    QMap<QString, Inscription*> _inscriptions;
public:
    Dossier(QString username);
};

#endif // DOSSIER_H
