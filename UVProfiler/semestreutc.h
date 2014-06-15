#ifndef SEMESTREUTC_H
#define SEMESTREUTC_H

/**
  * @file semestreetranger.h
  */
#include <QMap>
#include <QString>
#include "UVProfiler.h"
#include "inscription.h"
#include "uv.h"

/**
 * @brief The SemestreUTC class Classe representant un semestre a l'UTC. Herite de Inscription
 */
class SemestreUTC : public Inscription
{
protected:
    /**
     * @brief _choixUVs Map des UVs choisies
     */
    QMap<QString, UV*> _choixUVs;
    /**
     * @brief _notes Map des notes obtenues pour chaque UV
     */
    QMap<QString, Notes> _notes;
public:
    /**
     * @brief SemestreUTC Constructeur de recopie
     * @param copie Reference d'un objet SemestreUTC a recopier
     */
    SemestreUTC(const SemestreUTC& copie) : Inscription(tsemestreUTC, copie._semestre, copie._cursusEnCours) {}
    /**
     * @brief SemestreUTC Constructeur de base
     * @param semestre Semestre associe
     * @param cursus Cursus associe
     */
    SemestreUTC(const Semestre& semestre = Semestre(Aut,0), Cursus* cursus = NULLPTR) : Inscription(tsemestreUTC, semestre, cursus)
        {}

    /**
     * @brief removeUV Enleve une UV grace a son code
     * @param code Code de l'UV a enlever
     */
    void removeUV(QString code) { _choixUVs.remove(code);              _notes.remove(code);                    }
    /**
     * @brief removeUV Enleve l'UV pointee en parametre
     * @param uv Pointe sur l'UV a enlever
     */
    void removeUV(UV* uv)       { _choixUVs.remove(uv->getCode() );    _notes.remove(uv->getCode() );          }
    /**
     * @brief addUV Ajoute une UV pointee en parametre
     * @param uv Pointe sur l'UV a ajouter
     */
    void addUV(UV* uv)          { _choixUVs.insert(uv->getCode(), uv); _notes.insert(uv->getCode(), enCours);  }
    /**
     * @brief addUV Ajoute une UV grace a son code
     * @param code Code de l'UV a ajouter
     */
    void addUV(const QString& code) {
        UV& uv = UVManager::getInstance().getUV( code);
        _choixUVs.insert(uv.getCode(), &uv);
        _notes.insert(uv.getCode(), enCours);
    }

    /*Getters*/
    QMap<QString, UV*> getUV()  { return _choixUVs;                                                          }
    virtual QMap<QString, Notes> getNotes() { return _notes; }
    EnsCredits getCredits();


    /*Setters*/
    void setNote(const QString& code, const Notes& note);
    void setNote(UV* uv,              const Notes& note);

    virtual void serialize(QDataStream& stream);
    virtual void unserialize(QDataStream& stream);
};

Q_DECLARE_METATYPE(SemestreUTC)

#endif // SEMESTREUTC_H
