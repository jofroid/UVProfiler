#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "UVProfiler.h"
#include "dossier.h"
#include <QString>
#include <QMap>
#include <QtSql>

class Etudiant
{
private:
    QString _login;
    QString _nom;
    QString _prenom;
    QMap<QString, Dossier*> _dossier;
    static Etudiant* _instance;

    Etudiant(QString username, QString nom, QString prenom);
public:
    ~Etudiant();
    static Etudiant& createAccount(QString username, QString nom, QString prenom);
    static Etudiant& login(QString username);
    static bool logout();
};

#endif // ETUDIANT_H
