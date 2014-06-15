#include "postbac.h"


void PostBac::serialize(QDataStream& stream) const {
    Cursus::serialize(stream);
}

void PostBac::unserialize(QDataStream& stream) {
    Cursus::unserialize(stream);
}
