#include "AmericanPutOption.h"

// Constructor: initialize American put with expiry and strike
AmericanPutOption::AmericanPutOption(double expiry,double strike)
    : AmericanOption(expiry,strike){}

// Destructor
AmericanPutOption::~AmericanPutOption(){}

// Returns that this is a Put option
OptionType AmericanPutOption::getOptionType() const {return OptionType::Put;}

// Payoff of an American put: max(K - spot, 0)
double AmericanPutOption::payoff(double spot) const {
    if(spot > getStrike()){
        return 0;
    }
    else{
        return getStrike() - spot ;
    }
}
