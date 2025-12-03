#include "AmericanCallOption.h"

// Constructor for an American call option.
// It forwards expiry and strike to the base AmericanOption constructor.
AmericanCallOption::AmericanCallOption(double expiry,double strike)
    : AmericanOption(expiry,strike){}

// Destructor
AmericanCallOption::~AmericanCallOption(){}

// Return the type of the option: here it is a Call.
OptionType AmericanCallOption::getOptionType() const {
    return OptionType::Call;
}

// Payoff function for an American call option
double AmericanCallOption::payoff(double spot) const {
    if(spot < getStrike()){
        return 0;                  
    }
    else{                           
        return spot - getStrike(); 
    }
}
