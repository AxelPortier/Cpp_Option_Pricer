#include "AsianCallOption.h"
#include <vector>
#include <algorithm>

// Constructor: takes time steps and strike.
// Uses last time step as expiry for the Asian option.
AsianCallOption::AsianCallOption(std::vector<double>& timeSteps, double strike)
    : AsianOption(timeSteps.back(),timeSteps), _strike(strike)
{}

// Destructor
AsianCallOption::~AsianCallOption() {}

// Returns Call as option type
OptionType AsianCallOption::getOptionType() const {return OptionType::Call;}

// Payoff of an Asian call: max(average - K, 0)
double AsianCallOption::payoff(double average) const {
    return std::max(average - _strike, 0.0);
}
