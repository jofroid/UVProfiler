#include "uvobligatoires.h"

UVObligatoires::UVObligatoires(QVector<UV*>& uv)
{
	for(int i(0); i<uv.size(); i++)
		_uv.insert(uv[i]->getCode(), &uv[i]);
}

UVObligatoires::UVObligatoires(QMap<QString, UV*>& uv) : _uv(uv) {}

bool validation() override
{
	
}