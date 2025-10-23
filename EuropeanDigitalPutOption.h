#ifndef EUROPEANDIGITALPUTOPTION_H
#define EUROPEANDIGITALPUTOPTION_H

#include "EuropeanDigitalOption.h"


class EuropeanDigitalPutOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalPutOption(double expiry, double strike);
    double getPayoff(double spot) const override;
};

#endif