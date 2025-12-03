#include "AsianOption.h"
#include <numeric>
#include <vector>

// Constructor: takes expiry and monitoring times (t1,...,tm)
AsianOption::AsianOption(double expiry,const std::vector<double>& monitoringTimes)
    : Option(expiry), _timeSteps(monitoringTimes)
{}

// Destructor
AsianOption::~AsianOption(){}

// Return the monitoring times (t1,...,tm)
std::vector<double> AsianOption::getTimeSteps() const {return _timeSteps;}

// Compute payoff from a full path of prices
double AsianOption::payoffPath(const std::vector<double>& path) const {
    if (path.empty()) {
        return 0.0; // If path is empty, payoff is zero
    }

    double sum = 0;
    for (int i = 0; i < path.size(); i++) {
        sum += path[i]; // Sum all prices along the path
    }
    // Apply payoff on the arithmetic average of the path
    return payoff((1 / static_cast<double>(path.size())) * sum);
}

// Getter for strike of Asian option
double AsianOption::getStrike() const {return _strike;}

// Mark this option as Asian
bool AsianOption::isAsianOption() const{return true;}
