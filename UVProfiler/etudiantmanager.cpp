#include "etudiantmanager.h"

EtudiantManager* EtudiantManager::_instance=0;

EtudiantManager::EtudiantManager() {
    loadFromFile();
}
EtudiantManager::~EtudiantManager() {
    saveToFile();
}

void EtudiantManager::loadFromFile() {
    QSettings fichier("UVProfiler.ini", QSettings::IniFormat);
    fichier.beginGroup("etudiant");
    const QStringList childKeys = fichier.childKeys();
    foreach (const QString& childKey, childKeys) {
        EtudiantData copie( fichier.value(childKey, QVariant::fromValue(EtudiantData() )).value<EtudiantData>() );
        _etudiants.insert(copie.getLogin(), &copie);
    }
    fichier.endGroup();
}

void EtudiantManager::saveToFile() {
    QSettings fichier("UVProfiler.ini", QSettings::IniFormat);
    fichier.beginGroup("etudiant");
    QMap<QString, EtudiantData*>::const_iterator it;
    for(it=_etudiants.constBegin(); it!=_etudiants.constEnd(); ++it) {
        fichier.setValue(it.value()->getLogin(), QVariant::fromValue(*it.value() ));
    }
    fichier.endGroup();
    fichier.sync();
}

EtudiantData& EtudiantManager::getEtudiant(QString login) {
    if(_etudiants.contains(login))
        return *_etudiants[login];
    EtudiantData* fail= new EtudiantData("", "", "");
    return *fail;
}



