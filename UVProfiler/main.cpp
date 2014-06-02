#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QtSql>
#include "uvmanager.h"
#include "cursusmanager.h"
#include "uv.h"


#define q2c(string) string.toStdString()

int main(int argc,char **argv)
{

    UVManager& manager = UVManager::getInstance();
    manager.setOuvertureDB();
    manager.ajouterUV("BL01", "La Bio", PA, "CS", 6);
    manager.ajouterUV("TN01", "CAO", PA, "TM", 6);
    UV& uvTest = manager.getUV("BL01");
    std::cout<<uvTest.getNom().toStdString()<<std::endl;
    manager.save();
    manager.afficherListe();
    manager.load();
    //CursusManager& coucou = CursusManager::getInstance();


  /*
  QApplication app(argc,argv);

  //Création de la DB
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("./UVPROFILER.db");
  if(db.open())
    std::cout<<"UVPROFILER.db opened!"<<std::endl;

  QSqlQuery result;

  result= db.exec("CREATE TABLE IF NOT EXISTS UV (" \
                  "CODE           CHAR(10) PRIMARY KEY NOT NULL," \
                  "NOM            TEXT                 NOT NULL," \
                  "DESCRIPTION    TEXT                         ," \
                  "CATEGORIE      CHAR(5)              NOT NULL," \
                  "SAISON         CHAR(2)              NOT NULL," \
                  "CS             INT                          ," \
                  "TM             INT                          ," \
                  "TSH            INT                          ," \
                  "SP             INT                          );"); \

  QFile f("UV.csv");
  if(f.open (QIODevice::ReadOnly)){
      QTextStream ts (&f);

      //Travel through the csv file "UV.csv"
      while(!ts.atEnd()){
          QString req = "INSERT INTO UV VALUES('";
          // split every lines on comma
          QStringList line = ts.readLine().split(',');
          //for every values on a line, append it to the INSERT request
          for(int i=0; i<line.length();++i){
              req.append(line.at(i));
              req.append("','");
          }
          req.chop(2); // remove the trailing comma
          req.append(");"); // close the "VALUES([...]" with a ");"
          std::cout<<"Requete envoyee : "<<req.toStdString()<<std::endl;
          result.exec(req);
          qDebug()<<result.lastError().text();
      }
      f.close ();
  }
  else
    qDebug("Problème ouverture ficher !");

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
  */
  return 0;
}

