#ifndef UVOBLIGATOIRES_H
#define UVOBLIGATOIRES_H

#include <QMap>
#include <QString>
#include "criteresvalidationfiliere.h"
#include "uv.h"

class UVObligatoires : public CriteresValidationFiliere
{
protected:
    QMap<QString, UV*> _uvObligatoires;
public:
    UVObligatoires();
    virtual bool validation();
};

#endif // UVOBLIGATOIRES_H
