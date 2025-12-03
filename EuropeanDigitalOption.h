#pragma once
#include "Option.h"

// Class representing a European Digital Call Option (also known as a Binary Call).
class EuropeanDigitalOption : public Option {
    private:
        double _strike;
        
    public:
        // Constructor taking expiry and strike price
        EuropeanDigitalOption(double expiry, double strike);
        ~EuropeanDigitalOption();

        double getStrike() const override;
        bool isDigital() const override;

        // Virtual pure method
        virtual OptionType getOptionType() const = 0; // Returns the type of the option (Call)
        virtual double payoff(double spot) const = 0;  // Returns 1.0 if spot >= strike, 0.0 otherwise. Override the payoff function

};
