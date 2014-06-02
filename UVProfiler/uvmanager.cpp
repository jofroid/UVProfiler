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

void UVManager::ajouterUV(const QString& code, const QString& nom, const Saison saison, const QString& categorie) {
    if (_uvs.find(code) != _uvs.end())
        throw UTProfilerException(QString("erreur, UVManager, UV ")+code+QString(" deja existante"));
    else{
        if(categorie == "CS"){
            CS* newuv = new CS(nom, code, saison);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "TM"){
            TM* newuv = new TM(nom, code, saison);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "TSH"){
            CS* newuv = new CS(nom, code, saison);
            addItem(newuv);
            _modification=true;
        }
        else if(categorie == "SP"){
            SP* newuv = new SP(nom, code, saison);
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
        result.exec("INSERT INTO UV (CODE, NOM, CATEGORIE, SAISON) VALUES ('"+it.value()->getCode()+"','"+it.value()->getNom()+"','"+it.value()->getCategorie()+"','"+it.value()->getSaison()+"')" );
    }
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

UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager; /* instance creee une seule fois lors de la premiere utilisation*/
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}

/* construction fichier... � enlever */
/*
bool isInFile(QString code, QString file){
    QFile fin(file);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);
    QTextStream flux(&fin);
     while (!flux.atEnd()){
        QString codeuv=flux.readLine();
        if (code==codeuv) return true;
    }
    fin.close();
    return false;
}

void UVManager::load(const QString& f){
    if (file!=f) this->~UVManager();
    file=f;

    /*QFile fin(file);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);
    QTextStream flux(&fin);
    //QTextCodec *codec = QTextCodec::codecForName("Windows-1252");
    //flux.setCodec(codec);
    while (!flux.atEnd()){
        QString code=flux.readLine();
        QString titre=flux.readLine();
        QString tmp=flux.readLine();
        unsigned int nbCredits=tmp.toUInt();
        QString tmpcat=flux.readLine();
        Categorie cat=StringToCategorie(tmpcat);
        ajouterUV(code,titre,nbCredits,cat);
    }
    fin.close(); // close file


    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw UTProfilerException("Erreur ouverture fichier UV");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named uvs, we'll go to the next.
            if(xml.name() == "uvs") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "uv") {
                QString code;
                QString titre;
                unsigned int nbCredits;
                Categorie cat;
                bool automne=false;
                bool printemps=false;

                QXmlStreamAttributes attributes = xml.attributes();
                // Let's check that uvs has attribute.
                if(attributes.hasAttribute("automne")) {
                    QString val =attributes.value("automne").toString();
                    automne=(val == "true" ? true : false);
                }
                if(attributes.hasAttribute("printemps")) {
                    QString val =attributes.value("printemps").toString();
                    printemps=(val == "true" ? true : false);
                }

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "uv")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "code") {
                            xml.readNext(); code=xml.text().toString();
                        }
                        // We've found titre.
                        if(xml.name() == "titre") {
                            xml.readNext(); titre=xml.text().toString();
                        }
                        // We've found credits.
                        if(xml.name() == "credits") {
                            xml.readNext(); nbCredits=xml.text().toString().toUInt();
                        }
                        // We've found categorie
                        if(xml.name() == "categorie") {
                            xml.readNext(); cat=StringToCategorie(xml.text().toString());
                        }
                    }
                    // ...and next...
                    xml.readNext();
                }

                // construction fichier : � enlever
                //if (isInFile(code,"../Ressources/automne.txt")) automne=true;
                //if (isInFile(code,"../Ressources/printemps.txt")) printemps=true;

                ajouterUV(code,titre,nbCredits,cat,automne,printemps);

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}



void UVManager::save(const QString& f){

    /*QMessageBox msgBox;
     msgBox.setText("Debut The document has been saved.");
     msgBox.exec();*/

    /*
    file=f;
    /*QFile fichier(file); // toutes les UVs existantes sont �cras�es
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier ")+file);

    QTextStream fout(&fichier);
    for(unsigned int i=0; i<nbUV; i++){
        fout<<uvs[i]->getCode()<<"\n";
        fout<<uvs[i]->getTitre()<<"\n";
        fout<<uvs[i]->getNbCredits()<<"\n";
        fout<<uvs[i]->getCategorie()<<"\n";
    }
    fichier.close();*/

/*   QDomDocument doc( "UV_XML" );
    QDomElement root = doc.createElement( "uvs" );
    doc.appendChild( root );
    for(unsigned int i=0; i<nbUV; i++){
        QDomElement uv = doc.createElement("uv");
        uv.setNodeValue(uvs[i]->getCode());
        QDomElement code = doc.createElement( "code" ); code.setNodeValue(uvs[i]->getCode()); uv.appendChild(code);
        QDomElement titre = doc.createElement( "titre" ); titre.setNodeValue(uvs[i]->getTitre()); uv.appendChild(titre);
        root.appendChild(uv);
    }

    QFile file( "Z:/test.xml" );
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));

     QTextStream ts( &file );
     ts << doc.toString();
     file.close();*/
    /*
    QFile newfile( file);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("uvs");
     for(unsigned int i=0; i<nbUV; i++){
         stream.writeStartElement("uv");
         stream.writeAttribute("automne", (uvs[i]->ouvertureAutomne())?"true":"false");
         stream.writeAttribute("printemps", (uvs[i]->ouverturePrintemps())?"true":"false");
         stream.writeTextElement("code",uvs[i]->getCode());
         stream.writeTextElement("titre",uvs[i]->getTitre());
         QString cr; cr.setNum(uvs[i]->getNbCredits());
         stream.writeTextElement("credits",cr);
         stream.writeTextElement("categorie",CategorieToString(uvs[i]->getCategorie()));
         stream.writeEndElement();
     }
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}
*/
