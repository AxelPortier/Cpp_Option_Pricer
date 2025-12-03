#include "AsianCallOption.h"
#include <vector>
#include <algorithm>

AsianCallOption::AsianCallOption(std::vector<double>& timeSteps, double strike) : AsianOption(timeSteps.back(),timeSteps),_strike(strike) //Constructor that takes timeSteps and the strike of the option. timeSteps.back() is the last time of timeSteps so it matches expiry
{ }
AsianCallOption::~AsianCallOption() {}//Destructor

OptionType AsianCallOption::getOptionType() const{return OptionType::Call;}//Override the getOptionType function of the Option Class by a function that returns Call
double AsianCallOption::payoff(double average) const {return std::max(average - _strike, 0.0);}  //For an asian Call the payoff is max(0,average - K)
