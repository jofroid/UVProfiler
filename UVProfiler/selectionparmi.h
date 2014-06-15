#ifndef SELECTIONPARMI_H
#define SELECTIONPARMI_H

#include <QMap>
#include <QString>
#include "criteresvalidationfiliere.h"
#include "cursus.h"
#include "uv.h"
#include "uvmanager.h"
#include "inscription.h"
#include "etudiant.h"

class SelectionParmi : public CriteresValidationFiliere
{
private:
    QMap<QString, UV*> _uvsNecessaires;
    unsigned int _nbUvsNecessaires;
public:
    SelectionParmi(Cursus* cursus, unsigned int nbUvsNecessaires) :\
        _nbUvsNecessaires(nbUvsNecessaires) {}
    bool validation();

    void addUV(QString code);
    void addUV(UV* uv);

    void removeUV(QString code);
    void removeUV(UV* uv);
};

#endif // SELECTIONPARMI_H
