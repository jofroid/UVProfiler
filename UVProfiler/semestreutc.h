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
    void removeUV(QString code)  { _choixUVs.remove(code);              _notes.remove(code);                    }
    void removeUV(UV* uv)       { _choixUVs.remove(uv->getCode() );    _notes.remove(uv->getCode() );          }
    void addUV(UV* uv)          { _choixUVs.insert(uv->getCode(), uv); _notes.insert(uv->getCode(), enCours);  }
    void addUV(const QString& code) {
        UV& uv = UVManager::getInstance().getUV( code);
        _choixUVs.insert(uv.getCode(), &uv);
        _notes.insert(uv.getCode(), enCours);
    }

    void setNote(const QString& code, const Notes& note);
    void setNote(UV* uv,             const Notes& note);

    EnsCredits getCredits();
};

#endif // SEMESTREUTC_H
