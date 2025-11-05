#pragma once

#include "EuropeanDigitalOption.h"


class EuropeanDigitalPutOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalPutOption(double expiry, double strike);
    double getPayoff(double spot) const override;
    OptionType GetOptionType() override;
    ~EuropeanDigitalPutOption();
};