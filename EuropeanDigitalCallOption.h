#pragma once
#include "EuropeanDigitalOption.h"


class EuropeanDigitalCallOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalCallOption(double, double); // constructor
    ~EuropeanDigitalCallOption();

    OptionType getOptionType() const override;
    double payoff(double spot) const override; // useful to override payoff function
};