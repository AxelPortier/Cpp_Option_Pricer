#include "AmericanPutOption.h"

AmericanPutOption::AmericanPutOption(double expiry,double strike): AmericanOption(expiry,strike){}

AmericanPutOption::~AmericanPutOption(){}

OptionType AmericanPutOption::getOptionType() const {return OptionType::Put;}

double AmericanPutOption::payoff(double spot) const {
    if(spot > getStrike()){
        return 0;
    }
    else{
        return getStrike() - spot ;
    }
}