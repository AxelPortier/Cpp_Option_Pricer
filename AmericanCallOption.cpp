#include "AmericanCallOption.h"

AmericanCallOption::AmericanCallOption(double expiry,double strike): AmericanOption(expiry,strike){}

AmericanCallOption::~AmericanCallOption(){}

OptionType AmericanCallOption::getOptionType() const {return OptionType::Call;}

double AmericanCallOption::payoff(double spot) const {
    if(spot < getStrike()){
        return 0;
    }
    else{
        return spot - getStrike();
    }
}