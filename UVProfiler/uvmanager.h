#ifndef UVMANAGER_H
#define UVMANAGER_H

#include <QString>
#include <QMap>


/*
class UTProfilerException{
public:
    UTProfilerException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
}; */

enum typeOuverture { fichier, DB };

class UVManager {
private:
	UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);
    UVManager();
    ~UVManager();
	
    QMap<QString, UV*> _uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    QString file;
	enum typeOuverture _ouverture;
	void addItem(UV* uv);
	void loadFromFile();
	void loadFromDB();
	void saveToFile();
	void saveToDB();
	
    friend struct Handler;
    struct Handler{
        UVManager* instance;
        Handler():instance(0){}
        ~Handler(){ if (instance) delete instance; instance=0; }
    };
    static Handler handler;
public:
    void load(const QString& f)
	{
		if(_ouverture == fichier)
			loadFromFile();
		else if(_ouverture == DB )
			loadFromDB();
	}
    void save(const QString& f)
	{
		if(_ouverture == fichier)
			saveToFile();
		else if(_ouverture == DB)
			saveToDB();
	}
	
    static UVManager& getInstance();
    static void libererInstance();
    void ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);
};
*/
#endif // UVMANAGER_H
