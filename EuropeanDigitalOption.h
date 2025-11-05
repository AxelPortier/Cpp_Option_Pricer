#pragma once


#include "Option.h"
#include <stdexcept>

class EuropeanDigitalOption : public Option {
    protected:
        double _strike;
        EuropeanDigitalOption(double expiry, double strike);
    public:
        double getStrike() const;
        virtual ~EuropeanDigitalOption() = default;
        virtual double getPayoff(double spot) const = 0;
};
