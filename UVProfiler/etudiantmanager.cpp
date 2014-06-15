#include "etudiantmanager.h"

EtudiantManager* EtudiantManager::_instance=0;

EtudiantManager::EtudiantManager() {
    if(!QFile::exists("UVProfiler.ini"))
        loadExample();
    else
        loadFromFile();
}
EtudiantManager::~EtudiantManager() {
    saveToFile();
}

void EtudiantManager::loadExample() {
    _etudiants.insert("jdupon", new EtudiantData("jdupon", "Dupont", "Jean"));
    _etudiants.insert("bjamai", new EtudiantData("bjamai", "Jamais", "Bernard"));
    _etudiants.insert("tmachi", new EtudiantData("tmachi", "Machin", "truc"));
}

void EtudiantManager::loadFromFile() {
    QSettings fichier("UVProfiler.ini", QSettings::IniFormat);
    fichier.beginGroup("etudiant");
    const QStringList childKeys = fichier.childKeys();
    foreach (const QString& childKey, childKeys) {
        EtudiantData* copie = new EtudiantData( fichier.value(childKey, QVariant::fromValue(EtudiantData() )).value<EtudiantData>() );
        _etudiants.insert(copie->getLogin(), copie);
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

void EtudiantManager::printEtudiant() {
    QMap<QString, EtudiantData*>::const_iterator it;
    for(it=_etudiants.constBegin(); it!=_etudiants.constEnd(); it++) {
        std::cout<<it.value()->getLogin().toStdString()<<std::endl;
    }
}




