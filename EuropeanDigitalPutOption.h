#pragma once
#include "EuropeanDigitalOption.h"


class EuropeanDigitalPutOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalPutOption(double, double);
    ~EuropeanDigitalPutOption();

    OptionType getOptionType() const override;
    double payoff(double) const override;
};