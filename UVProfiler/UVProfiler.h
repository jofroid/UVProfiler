#ifndef UVPROFILER
#define UVPROFILER

#include <iostream>
#include <QString>
#include <QVariant>
/*
#include "branche.h"
#include "criteresvalidationfiliere.h"
#include "cs.h"
#include "cursus.h"
#include "cursusmanager.h"
#include "dossier.h"
#include "enscredits.h"
#include "etudiant.h"
#include "etudiantmanager.h"
#include "filiere.h"
#include "inscription.h"
#include "mineur.h"
#include "mineurbase.h"
#include "postbac.h"
#include "selectionparmi.h"
#include "semestre.h"
#include "semestreetranger.h"
#include "semestreutc.h"
#include "sp.h"
#include "tm.h"
#include "tsh.h"
#include "uv.h"
#include "uvmanager.h"
#include "uvobligatoires.h" */

#define NULLPTR 0

enum Saison { P, Aut, PA, X };
QString& operator<<(QString& out, Saison saison);

enum Notes { A, B, C, D, E, FX, F, enCours};

QDataStream& operator<<(QDataStream& stream, Notes const& valeur);
QDataStream& operator>>(QDataStream& stream, Notes& valeur);


#endif // UVPROFILER
