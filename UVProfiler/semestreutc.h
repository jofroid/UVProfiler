#ifndef SEMESTREUTC_H
#define SEMESTREUTC_H

#include <QMap>
#include <QString>
#include "UVProfiler.h"
#include "inscription.h"
#include "uv.h"


class SemestreUTC
{
protected:
    QMap<QString, UV*> _choixUVs;
    QMap<QString, Notes> _notes;
public:
    SemestreUTC();

    QMap<QString, UV*> getUV()  { return _choixUVs;                                                          }
    void addUV(UV* uv)          { _choixUVs.insert(uv->getNom(), uv); _notes.insert(uv->getNom(), enCours);  }
    void removeUV(QString nom)  { _choixUVs.remove(nom);              _notes.remove(nom);                    }
    void removeUV(UV* uv)       { _choixUVs.remove(uv->getNom() );    _notes.remove(uv->getNom() );          }

    void setNote(const QString& nom, const Notes& note);
    void setNote(UV* uv,             const Notes& note);

};

#endif // SEMESTREUTC_H
