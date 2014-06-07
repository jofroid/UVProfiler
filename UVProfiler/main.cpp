#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QtSql>
#include "uvmanager.h"
#include "cursusmanager.h"
#include "uv.h"
#include "windows.h"


#define q2c(string) string.toStdString()

int main(int argc,char **argv)
{
try{
    if(false) {
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
    }

    else {

    }

    }
    catch (UTProfilerException utpe) {std::cout<<utpe.getInfo().toStdString()<<std::endl;}
  return 0;
}

