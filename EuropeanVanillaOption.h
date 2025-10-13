#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Option.h"
#include <stdexcept>

class EuropeanVanillaOption : public Option {
public:
    enum class optionType { call, put };

private:
    double _strike;

public:
    EuropeanVanillaOption(double expiry, double strike);
    double getStrike() const;
    virtual optionType GetOptionType() const = 0;
};

#endif
