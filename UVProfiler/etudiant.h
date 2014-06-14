#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QMap>
#include <QtSql>
#include "UVProfiler.h"
#include "dossier.h"
#include "etudiantdata.h"


class Etudiant : public EtudiantData
{
private:
    QMap<QString, Dossier*> _dossier;
    static Etudiant* _instance;

    Etudiant(QString username, QString nom, QString prenom);
public:
    ~Etudiant();
    static Etudiant& createAccount(QString username, QString nom, QString prenom);
    static Etudiant& login(QString username);
    static Etudiant& getInstance();
    static bool logout();
};

#endif // ETUDIANT_H
