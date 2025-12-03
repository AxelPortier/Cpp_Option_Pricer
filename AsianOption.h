#pragma once
#include "Option.h"
#include <vector>

// Base class for Asian options, derived from Option
class AsianOption : public Option {
private:
    std::vector<double> _timeSteps; // Time steps (t1, t2, ..., tm)
    double _strike;                 // Strike of the Asian option

public:
    AsianOption(double expiry, const std::vector<double>& monitoringTimes); // Constructor
    ~AsianOption();                                                         // Destructor

    std::vector<double> getTimeSteps() const override;                      // Getter for time steps
    double payoffPath(const std::vector<double>&) const override;           // Payoff from a full price path
    bool isAsianOption() const override;                                    // Returns true

    double getStrike() const override;                                      // Getter for strike
    virtual OptionType getOptionType() const = 0;                           // Call or Put
    virtual double payoff(double) const = 0;                                // Payoff from average price
};
