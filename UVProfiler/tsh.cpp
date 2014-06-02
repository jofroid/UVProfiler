#include "tsh.h"

TSH::TSH(const QString n, const QString c, const Saison s, const unsigned int credits, const LigneTSH ligneTSH, const ColonneTSH colonneTSH) : UV::UV(n, c, s), _ligneTSH(ligneTSH), _colonneTSH(colonneTSH)
{
    getCredit().setTSH(credits);
}
