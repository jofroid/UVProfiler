#include "uvmanager.h"
#include <iostream>
#include <sstream>
#include <QFile>
#include <QTextCodec>
//#include <QtXml>
#include <QMessageBox>
#include <ctime>
#include <windows.h>


UVManager::UVManager():_file(""), _ouverture(DB), _modification(false){}

UVManager::~UVManager(){
    if (_file != "")
        save();
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
    //if(_uvs.find(code) == _uvs.end())
        //throw UTProfilerException(QString("erreur, UVManager, UV ")+code+QString(" deja existante"));
    //else{
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
            TSH* newuv = new TSH(nom, code, saison, credits);
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
    //}
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
    //result.exec("DROP TABLE UV;");
    result.exec("DROP TABLE TSH;");
    result.exec("CREATE TABLE IF NOT EXISTS UV (" \
                    "CODE           CHAR(10) PRIMARY KEY NOT NULL," \
                    "NOM            TEXT                 NOT NULL," \
                    "CATEGORIE      CHAR(5)              NOT NULL," \
                    "SAISON         CHAR(2)              NOT NULL," \
                    "CS             INT                          ," \
                    "TM             INT                          ," \
                    "TSH            INT                          ," \
                    "SP             INT                          );");
    query = "CREATE TABLE IF NOT EXISTS TSH (" \
                    "CODEUV       CHAR(10)  PRIMARY KEY NOT NULL," \
                    "LIGNE      TEXT        NOT NULL,"\
                    "COLONNE    TEXT        NOT NULL," \
                    "FOREIGN KEY(CODEUV) REFERENCES UV(CODE) );";
    if(result.exec(query))
        std::cout<<"TSH cree"<<std::endl;

    QMap<QString, UV*>::const_iterator it;
    for( it = _uvs.constBegin(); it != _uvs.constEnd(); it++){
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
        if(it.value()->getCategorie() == "TSH"){
            query = "INSERT INTO TSH VALUES(" \
                        "'"+it.value()->getCode()+"'," \
                        "'"+it.value()->getLigneTSH()+"',"
                        "'"+it.value()->getColonneTSH()+"')";
        }
        if( !result.exec(query) )
          qDebug() << result.lastError();
    }
    db.commit();
    db.close();
}

void UVManager::loadFromDB(){ /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result, result2;
    QString query, query2;

    query = "SELECT * FROM UV WHERE CATEGORIE = 'TSH';";
    if( !result.exec(query) )
        qDebug() << result.lastError();
    else{
        qDebug( "Selection des TSH" );

        QSqlRecord rec = result.record();
        QSqlRecord rec2;
        int cols = rec.count();
        int cols2;
        UVManager& manager = UVManager::getInstance(); // tu peux utiliser *this à la place non ?

        for( int r=0; result.next(); r++) {
            for( int c=0; c<cols; c++ )
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( result.value(c).toString() );
            manager.ajouterUV(result.value(0).toString(), result.value(1).toString(), UV::getSaison(result.value(2).toString()), "TSH", result.value(4).toInt());
            query2 = "SELECT * FROM TSH WHERE CODEUV = '"+result.value(0).toString()+"';";
            if( !result2.exec(query2))
                qDebug() << result2.lastError();
            else
                qDebug( "Selection des Lignes/Colonnes TSH" );
            rec2 = result2.record();
            cols2 = rec2.count();
            for( int ra=0; result2.next(); ra++ ){
                for( int ca=0; ca<cols2; ca++ )
                    qDebug() << QString( "Row %1, %2: %3" ).arg( ra ).arg( rec2.fieldName(ca) ).arg( result2.value(ca).toString() );

                std::cout<<"1: "<<result2.value(2).toString().toStdString()<<std::endl;
                manager.getUV(result2.value(0).toString()).setColonneTSH(result2.value(2).toString());
                //tsh.setColonneTSH(result2.value(2).toString());
                //std::cout<<"2: "<<tsh.getColonneTSH().toStdString()<<std::endl;
                //manager.getUV(result2.value(0).toString()).setColonneTSH(result2.value(2).toString());
            }
        }
    }

    query = "SELECT * FROM UV WHERE CATEGORIE = 'CS';";
    if( !result.exec(query) )
        qDebug() << result.lastError();
    else{
        qDebug( "Selection des CS" );

        QSqlRecord rec = result.record();
        int cols = rec.count();
        UVManager& manager = UVManager::getInstance();

        for( int r=0; result.next(); r++ ){
              for( int c=0; c<cols; c++ ){
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( result.value(c).toString() );
                manager.ajouterUV(result.value(0).toString(), result.value(1).toString(), UV::getSaison(result.value(2).toString()), "CS", result.value(4).toInt());
              }
        }
    }

    query = "SELECT * FROM UV WHERE CATEGORIE = 'TM';";
    if( !result.exec(query) )
        qDebug() << result.lastError();
    else{
        qDebug( "Selection des TM" );

        QSqlRecord rec = result.record();
        int cols = rec.count();
        UVManager& manager = UVManager::getInstance();

        for( int r=0; result.next(); r++ ){
              for( int c=0; c<cols; c++ ){
                    qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( result.value(c).toString() );
                    manager.ajouterUV(result.value(0).toString(), result.value(1).toString(), UV::getSaison(result.value(2).toString()), "TM", result.value(4).toInt());
              }
        }
    }

    query = "SELECT * FROM UV WHERE CATEGORIE = 'SP';";
    if( !result.exec(query) )
        qDebug() << result.lastError();
    else{
        qDebug( "Selection des SP" );

        QSqlRecord rec = result.record();
        int cols = rec.count();
        UVManager& manager = UVManager::getInstance();

        for( int r=0; result.next(); r++ ){
              for( int c=0; c<cols; c++ ){
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( result.value(c).toString() );
                manager.ajouterUV(result.value(0).toString(), result.value(1).toString(), UV::getSaison(result.value(2).toString()), "SP", result.value(4).toInt());
              }
        }
    }
    db.commit();
    db.close(); //*/
}

void UVManager::afficherTable(const QString& table){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./UVPROFILER.db");
    if(db.open())
      std::cout<<"UVPROFILER.db opened!"<<std::endl;

    QSqlQuery result;
    result.prepare( "SELECT * FROM "+table+"" );
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
    // aainstance creee une seule fois lors de la premiere utilisation
    if (!handler.instance) handler.instance = new UVManager;
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) {
        delete handler.instance;
        handler.instance=0;
    }
}

