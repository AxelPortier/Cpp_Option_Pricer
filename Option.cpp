#include <iostream>
#include "Option.h"

Option::Option(double expiry){
    if(expiry <= 0){
        throw std::invalid_argument("Expiry must be positive");
    }  
    else{
        _expiry = expiry;
    }
}
Option::~Option(){};

double Option::getExpiry() const {return _expiry;} // Return maturity

//Return the payoff
// For standard European options, the payoff depends only on the final value (S_tm)
double Option::payoffPath(const std::vector<double>& path) const{
    if (path.empty()){
        return 0.0;
    }
    else{
        return payoff(path.back());
    }
}

std::vector<double> Option::getTimeSteps() const{
	std::vector<double> timesteps{ 0, _expiry }; // Default time steps: 0 and T (Expiry)
	return timesteps;
}

// Default flags return false unless overridden by specific derived classes
bool Option::isDigital() const{return false;}
bool Option::isAsianOption() const{return false;} 
bool Option::isAmericanOption() const{return false;}