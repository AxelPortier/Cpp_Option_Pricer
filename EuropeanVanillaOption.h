#pragma once

#include "Option.h"
#include <stdexcept>

class EuropeanVanillaOption : public Option {
public:

private:
    double _strike;

public:
    EuropeanVanillaOption(double expiry, double strike);
    double getStrike() const;
    virtual OptionType GetOptionType() const = 0;
};
