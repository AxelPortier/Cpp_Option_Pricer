#pragma once

#include <vector>
#include "AsianOption.h"

// Asian call option, derived from AsianOption
class AsianCallOption : public AsianOption
{
private:
    double _strike; // Strike K of the option

public:
    AsianCallOption(std::vector<double>& timeSteps, double strike); // Constructor
    ~AsianCallOption();                                            // Destructor

    OptionType getOptionType() const override;                     // Returns Call
    double payoff(double) const override;                          // Payoff of Asian call
};
