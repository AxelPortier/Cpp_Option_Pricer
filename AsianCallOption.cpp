#include "AsianCallOption.h"
#include <vector>
#include <algorithm>

AsianCallOption::AsianCallOption(std::vector<double>& timeSteps, double strike)   
    :AsianOption(timeSteps),_strike(strike) 
{

}

double AsianCallOption::payoff(double average) const {
    return std::max(average - _strike, 0.0);
}
