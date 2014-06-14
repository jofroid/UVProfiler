#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QtSql>
#include "uvmanager.h"
#include "cursusmanager.h"
#include "uv.h"
#include "cs.h"
#include "semestre.h"
#include "semestreutc.h"
#include "dossier.h"
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
            a();
            std::cout<<"Coucou!\nIt's done\n";

    }
    catch (UTProfilerException utpe) {
        std::cout<<utpe.getInfo().toStdString()<<std::endl;
    }
  return 0;
}

void initFileSystem() {
    EnsCredits::initEnsCreditsSystem();
    Branche::initBrancheSystem();
    Semestre::initSemestreSystem();
}




void a() {
    PostBac postbac("TC", "TC", "tronc commun", EnsCredits(1,1,1,2));
    Dossier dossier("amirgalet");
    dossier.setPostBac( &postbac);
    SemestreUTC* sem = new SemestreUTC(Semestre(Aut, 14), &postbac);
    CS nf17("BD", "NF17", PA, 3 );
    CS lo21("OO", "LO21", PA, 4 );
    sem->addUV( &nf17);
    sem->addUV( &lo21);
    sem->setNote("NF17", A);
    sem->setNote("LO21", E);
    dossier.addInscription( sem);
    dossier.updateCredits();
    std::cout<<"\n\nTotal:\n";
    dossier.getTotalCreditsPostBac().afficheEnsCredits();

    Branche branche("GI", "GI", "génie info", EnsCredits(2,2,2,3));
    dossier.setBranche(&branche);
    SemestreUTC* sem2 = new SemestreUTC(Semestre(P, 14), &branche);

}




