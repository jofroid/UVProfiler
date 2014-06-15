#include "selectionparmi.h"


void SelectionParmi::addUV(QString code) {
    _uvsNcessaires.insert( code, UVManager::getInstance().getUV(code) );
}

void SelectionParmi::addUV(UV* uv) {
    _uvsNcessaires.insert( uv->getCode(), uv);
}


void SelectionParmi::removeUV(QString code) {
    _nbUvsNecessaires.remove(code);
}

void SelectionParmi::removeUV(UV* uv) {
    _nbUvsNecessaires.remove(uv->getCode());
}


