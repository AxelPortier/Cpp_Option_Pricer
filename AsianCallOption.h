#pragma once

#include <vector>
#include "AsianOption.h"

class AsianCallOption : public AsianOption
{
private:
    double _strike; //Stike K of the option

public:
    AsianCallOption(std::vector<double>& timeSteps, double strike); //Constructor
    ~AsianCallOption(); //Destructor

    OptionType getOptionType() const override;
    double payoff(double) const override; //Override the payoff function of Option class with a function that compute the payoff of an Asian Call Option
};