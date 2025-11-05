#pragma once
#include "Option.h"

class EuropeanDigitalOption : public Option {
    private:
        double _strike;
        
    public:
        // Method that will be implemented in the .cpp
        EuropeanDigitalOption(double expiry, double strike);
        ~EuropeanDigitalOption();

        double getStrike() const override;
        bool isDigital() override;

        // Virtual pure methode that won't be implemented in the .cpp
        virtual OptionType getOptionType() const = 0;
        virtual double getPayoff(double spot) const = 0;

};
