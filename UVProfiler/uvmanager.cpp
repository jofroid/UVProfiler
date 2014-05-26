#include "uvmanager.h"

/*
UVManager::UVManager()
{
}
*/

UVManager& UVManager::getInstance() {
	if(!handler.instance)
		handler.instance = new UVManager;
	return *handler.istance;
}

void UVManager::libererInstance() {
	if(handler.instance) {
		delete handler.instance;
		handler.instance=0;
	}
}

