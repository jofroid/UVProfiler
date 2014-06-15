#ifndef ETUDIANTDATA_H
#define ETUDIANTDATA_H

/**
  * @file etudiantdata.h
  */
#include <QString>
#include <QVariant>

/**
 * @brief The EtudiantData class Classe representant les donnee personnelle d'un etudiant
 */
class EtudiantData
        // Il faut créer un constructeur de Etudiant qui prenne etudiantData.
{
protected:
    /**
     * @brief _login Login de l'etudiant
     */
    QString _login;
    /**
     * @brief _nom Nom de l'étudiant
     */
    QString _nom;
    /**
     * @brief _prenom Prenom de l'étudiant
     */
    QString _prenom;
public:
    /**
     * @brief EtudiantData Constructeur de base
     */
    EtudiantData() : _login(""), _nom(""), _prenom("") {}
    /**
     * @brief EtudiantData Constructeur intialisant tous les attributs de l'objet
     * @param login Login de l'etudiant
     * @param nom Nom de l'etudiant
     * @param prenom Prenom de l'etudiant
     */
    EtudiantData(const QString& login, const QString& nom, const QString& prenom):\
        _login(login), _nom(nom), _prenom(prenom) {}

    /**
     * @brief EtudiantData Constructeur de recopie
     * @param copie Reference sur un objet EtudianData a copier
     */
    EtudiantData(const EtudiantData& copie);

    /*Getters*/
    QString getLogin()  { return _login;    }
    QString getNom()    { return _nom;      }
    QString getPrenom() { return _prenom;   }


    static void initEtudiantDataFileSystem();
    friend QDataStream& operator<< (QDataStream&, const EtudiantData&);
    friend QDataStream& operator>> (QDataStream&, EtudiantData&);
};

Q_DECLARE_METATYPE(EtudiantData)
QDataStream& operator<< (QDataStream& out, const EtudiantData& Valeur);
QDataStream& operator>> (QDataStream& in, EtudiantData& Valeur);


#endif // ETUDIANTDATA_H
