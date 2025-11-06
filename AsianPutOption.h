#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H
#include <vector>
#include "AsianOption.h"

class AsianPutOption : public AsianOption
{
private:
    double _strike; //Stike K of the option

    public:
    AsianPutOption(std::vector<double>& timeSteps, double strike); //Constructor
    ~AsianPutOption(); //Destructor
    OptionType getOptionType() const override;

    double payoff(double) const override; //Override the payoff function of Option class with a function that compute the payoff of an Asian Put Option
};

#endif