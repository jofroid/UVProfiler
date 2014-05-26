#ifndef CRITERES_VALIDATION_FILIERES_H
#define CRITERES_VALIDATION_FILIERES_H

class CriteresValidationFilieres
{
protected:
public:
    CriteresValidationFilieres();
	virtual ~CriteresValidationFilieres() =0;
	virtual bool validation()=0;
};

#endif // CRITERES_VALIDATION_FILIERES_H
