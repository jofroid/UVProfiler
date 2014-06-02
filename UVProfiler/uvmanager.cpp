#include "uvmanager.h"
#include <iostream>
#include <sstream>
#include <QFile>
#include <QTextCodec>
//#include <QtXml>
#include <QMessageBox>


UVManager::UVManager():_file(""), _ouverture(DB), _modification(false){}

UVManager::~UVManager(){
    if (_file != "")
        save();
    //for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
    //delete[] uvs;
}

void UVManager::addItem(UV* uv){
    _uvs.insert(uv->getCode(), uv);
}

UV& UVManager::getUV(const QString& code){
    if(_uvs.find(code) != _uvs.end())
        return *_uvs.value(code);
    throw UTProfilerException(QString("erreur, l'UV ")+code+QString(" n'existe pas"));
}

void UVManager::ajouterUV(const QString& code, const QString& nom, const Saison saison, const QString& categorie, unsigned int credits) {
    if (_uvs.find(code) != _uvs.end())
        throw UTProfilerException(QString("erreur, UVManager, UV ")+code+QString(" deja existante"));
    else{
        if(categorie == "CS"){
            CS* newuv = new CS(nom, code, saison, credits);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "TM"){
            TM* newuv = new TM(nom, code, saison, credits);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "TSH"){
            CS* newuv = new CS(nom, code, saison, credits);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "SP"){
            SP* newuv = new SP(nom, code, saison, credits);
            addItem(newuv);
            _modification=true;
        }
        else
            throw UTProfilerException(QString("erreur, UVManager, categorie ")+categorie+QString(" n'existe pas"));
    }
}

const UV& UVManager::getUV(const QString& code)const{
    return const_cast<UVManager*>(this)->getUV(code);
        // on peut aussi dupliquer le code de la methode non-const
}

//Presque finie cette fonction du swag!
void UVManager::saveToDB()const{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    QString query;
    result.exec("DROP TABLE UV");
    result.exec("CREATE TABLE IF NOT EXISTS UV (" \
                    "CODE           CHAR(10) PRIMARY KEY NOT NULL," \
                    "NOM            TEXT                 NOT NULL," \
                    "CATEGORIE      CHAR(5)              NOT NULL," \
                    "SAISON         CHAR(2)              NOT NULL," \
                    "CS             INT                          ," \
                    "TM             INT                          ," \
                    "TSH            INT                          ," \
                    "SP             INT                          );");

    QMap<QString, UV*>::const_iterator it;
    for( it = _uvs.begin(); it != _uvs.end(); it++){
        query = "INSERT INTO UV (CODE, NOM, CATEGORIE, SAISON, CS, TM, TSH, SP) VALUES ("\
                    "'"+it.value()->getCode()+"'," \
                    "'"+it.value()->getNom()+"'," \
                    "'"+it.value()->getCategorie()+"'," \
                    "'"+it.value()->getSaison()+"'," \
                    "'"+QString::number(it.value()->getCredit().CS())+"'," \
                    "'"+QString::number(it.value()->getCredit().TM())+"'," \
                    "'"+QString::number(it.value()->getCredit().TSH())+"'," \
                    "'"+QString::number(it.value()->getCredit().SP())+"')";
        if( !result.exec(query) )
          qDebug() << result.lastError();
    }
    db.commit();
    db.close();
}

void UVManager::loadFromDB(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    QString query;

    QMap<QString, UV*>::const_iterator it;
    for( it = _uvs.begin(); it != _uvs.end(); it++){
        query = "SELECT * FROM UV;";
        if( !result.exec(query) )
            qDebug() << result.lastError();
        else
            qDebug() << "Chargement en cours...";


    }
    db.commit();
    db.close();
}


void UVManager::afficherListe(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.prepare( "SELECT * FROM UV" );
      if( !result.exec() )
        qDebug() << result.lastError();
      else
      {
        qDebug( "Selected!" );
        QSqlRecord rec = result.record();
        int cols = rec.count();
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; result.next(); r++ )
          for( int c=0; c<cols; c++ )
            qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( result.value(c).toString() );
      }

    db.commit();
    db.close();
}

void UVManager::saveToFile()const{}
void UVManager::loadFromFile(){}


UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager; /* instance creee une seule fois lors de la premiere utilisation*/
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}

