#include "AsianPutOption.h"
#include <vector>
#include <algorithm>

AsianPutOption::AsianPutOption(std::vector<double>& timeSteps, double strike)   
    :AsianOption(timeSteps.back(),timeSteps),_strike(strike) //Constructor that takes timeSteps and the strike of the option. timeSteps.back() is the last time of timeSteps so it matches expiry
{ }
AsianPutOption::~AsianPutOption(){}//Destructor

OptionType AsianPutOption::getOptionType() const{return OptionType::Put;} //Override the getOptionType function of the Option Class by a function that returns Put
double AsianPutOption::payoff(double average) const {return std::max(_strike - average, 0.0);}  //For an asian Put the payoff is max(0,K - average)
