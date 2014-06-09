#ifndef POSTBAC_H
#define POSTBAC_H

#include "cursus.h"
#include <QVariant>
#include <QString>


class PostBac: public Cursus
{
public:
    PostBac() : Cursus::Cursus() {}
    PostBac(const QString& nom, const QString& code, const QString& description, const EnsCredits creditsNecessaires=0):\
        Cursus::Cursus(nom, code, description, creditsNecessaires) {}
    PostBac(const PostBac& copie) :\
        Cursus::Cursus(copie._nom, copie._code, copie._description, copie._creditsNecessaires) {}
    void initPostBacSystem();

    friend QDataStream& operator<< (QDataStream&, const PostBac&);
    friend QDataStream& operator>> (QDataStream&, PostBac&);
};

Q_DECLARE_METATYPE(PostBac)
QDataStream& operator<< (QDataStream& out, const PostBac& Valeur);
QDataStream& operator>> (QDataStream& in, PostBac& Valeur);

#endif // POSTBAC_H
