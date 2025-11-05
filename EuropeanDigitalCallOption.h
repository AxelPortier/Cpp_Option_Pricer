#pragma once

#include "EuropeanDigitalOption.h"


class EuropeanDigitalCallOption : public EuropeanDigitalOption
{
    public:
        EuropeanDigitalCallOption(double expiry, double strike); // constructor
        double getPayoff(double spot) const override; // useful to override payoff function
        OptionType GetOptionType() override;
        ~EuropeanDigitalCallOption();
};