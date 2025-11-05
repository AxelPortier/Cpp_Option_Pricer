#pragma once


#include "Option.h"
#include <stdexcept>

class EuropeanDigitalOption : public Option {
    private:
        double _strike;
        
    public:
        EuropeanDigitalOption(double expiry, double strike);
        double getStrike() const;
        virtual OptionType GetOptionType()override = 0;
        ~EuropeanDigitalOption();
        virtual double getPayoff(double spot) const = 0;
        bool isDigital() override;
};
