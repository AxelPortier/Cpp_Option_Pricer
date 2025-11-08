#pragma once

#include "Option.h"
#include <vector>
using namespace std;

class AsianOption : public Option {
private:
	vector<double> timeSteps_; //Timesteps of the AsianOption : (t1,t2,....,tm)
public:


    AsianOption(double expiry, const std::vector<double>& monitoringTimes); //Constructor that takes the expiry date and monitoring times
    const vector<double>& getTimeSteps() const; //Getter of timeSteps
    ~AsianOption(); //Destructor
    bool isAsianOption() const override;  //return true
private:
    double payoffPath(const vector<double>&) const override;  //Redefine payoffPath, first we compute the mean then we call payoff (which depends on the option being a call or put option)
};