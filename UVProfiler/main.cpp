#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QtSql>
#include "uvmanager.h"
#include "cursusmanager.h"
#include "uv.h"
#include "windows.h"

#define q2c(string) string.toStdString()

void initFileSystem();
void a();

int main(int argc,char **argv)
{
    try{
        initFileSystem();

        /*
            UVManager& manager = UVManager::getInstance();
            manager.setOuvertureDB();
            //manager.ajouterUV("BL01", "La Bio", PA, "CS", 6);
            //manager.ajouterUV("CM11", "La Chimie", PA, "CS", 6);
            //manager.ajouterUV("TN01", "CAO", PA, "TM", 6);
            //manager.ajouterUV("SI11", "Parole en public", PA, "TSH", 4);
            //manager.getUV("SI11").setColonneTSH(DemarchesEtPratiques);
            //manager.getUV("SI11").setLigneTSH(Communiquer);
            //UV& uvTest = manager.getUV("BL01");
            //std::cout<<uvTest.getNom().toStdString()<<std::endl;
            //manager.save();
            //manager.afficherTable("UV");
            //manager.afficherTable("TSH");

            manager.load();
            Sleep(1000);
            UV& uvTest = manager.getUV("CM11");
            //std::cout<<uvTest.getNom().toStdString()<<std::endl;
            //uvTest = manager.getUV("BL01");
            //std::cout<<uvTest.getNom().toStdString()<<std::endl;
            uvTest = manager.getUV("SI11");
            std::cout<<uvTest.getColonneTSH().toStdString()<<std::endl;
            std::cout<<uvTest.getNom().toStdString()<<std::endl;
            //std::cout<<uvTest.getLigneTSH().toStdString()<<std::endl;
            //manager.getUV("SI11").setColonneTSH("DemarchesEtPratiques");

            //uvTest = manager.getUV("TN01");
            //std::cout<<uvTest.getNom().toStdString()<<std::endl;
*/
            //a();
            std::cout<<"Done\n";

    }
    catch (UTProfilerException utpe) {
        std::cout<<utpe.getInfo().toStdString()<<std::endl;
    }
  return 0;
}

void initFileSystem() {
    EnsCredits::initEnsCreditsSystem();
    Branche::initBrancheSystem();
}




void a() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./UVPROFILER.db");
    QSqlQuery result;
    if(db.open())
          std::cout<<"UVPROFILER.db opened!"<<std::endl;
    result.exec("DROP TABLE cursus;");
    result.exec("DROP TABLE branche;");
    result.exec("CREATE TABLE IF NOT EXISTS cursus (" \
                    "code           CHAR(10) PRIMARY KEY NOT NULL," \
                    "nom            TEXT                 NOT NULL," \
                    "description    CHAR(5)              NOT NULL," \
                    "SAISON         CHAR(2)              NOT NULL," \
                    "CS             INT                          ," \
                    "TM             INT                          ," \
                    "TSH            INT                          ," \
                    "SP             INT                          );");
    result.exec("CREATE TABLE IF NOT EXISTS branche (" \
                    "code                CHAR(10) PRIMARY KEY NOT NULL REFERENCES cursus(code)," \
                    "creditPCBNecessaire INT                  NOT NULL);");
    result.exec("INSERT INTO cursus(code, nom, description, saison, CS, TM, TSH, SP)\
                VALUES('GI', 'Génie Info', 'les pros', 'P14', 0, 0, 0, 0);");

            db.commit();
            db.close();
    std::cout<<"modif' faites\n";

    CursusManager& cManager = CursusManager::getInstance();
    cManager.print();
}




