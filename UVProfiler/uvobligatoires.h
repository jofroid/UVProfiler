#ifndef UVOBLIGATOIRES_H
#define UVOBLIGATOIRES_H

#include "CriteresValidationFilieres.h"
#include "UV.h"
#include <QMap>
#include <QVector>

class UVObligatoires : public CriteresValidationFilieres
{
protected:
	QMap<string, UV*> _uv;
public:
    UVObligatoires(QVector<UV*>& uv);
	UVObligatoires(QMap<QString, UV*>& uv);
	virtual bool validation();
};

#endif // UVOBLIGATOIRES_H
