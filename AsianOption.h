#pragma once
#include "Option.h"
#include <vector>

class AsianOption : public Option {
private:
	std::vector<double> _timeSteps; //Timesteps of the AsianOption : (t1,t2,....,tm)
public:
    AsianOption(double expiry, const std::vector<double>& monitoringTimes); //Constructor that takes the expiry date and monitoring times
    ~AsianOption(); //Destructor

    std::vector<double> getTimeSteps() const override; //Getter of timeSteps
    double payoffPath(const std::vector<double>& ) const override;  //Redefine payoffPath, first we compute the mean then we call payoff (which depends on the option being a call or put option);
    bool isAsianOption() const override;  //return true

    virtual OptionType getOptionType() const = 0;
    virtual double payoff(double) const = 0;
};