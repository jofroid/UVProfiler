#ifndef ETUDIANTDATA_H
#define ETUDIANTDATA_H

#include <QString>
#include <QVariant>

class EtudiantData // C'est ce qui sera stocké dans les fichiers, puis chargé par etudiant.
        // Il faut créé un constructeur de Etudiant qui prenne etudiantData.
{
protected:
    QString _login;
    QString _nom;
    QString _prenom;
public:
    EtudiantData(const QString& login = "", const QString& nom = "", const QString& prenom = ""):\
        _login(login), _nom(nom), _prenom(prenom) {}
    EtudiantData(const EtudiantData& copie);

    static void initEtudiantDataFileSystem();
    friend QDataStream& operator<< (QDataStream&, const EtudiantData&);
    friend QDataStream& operator>> (QDataStream&, EtudiantData&);
};

Q_DECLARE_METATYPE(EtudiantData)
QDataStream& operator<< (QDataStream& out, const EtudiantData& Valeur);
QDataStream& operator>> (QDataStream& in, EtudiantData& Valeur);


#endif // ETUDIANTDATA_H