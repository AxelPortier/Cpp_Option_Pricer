#pragma once
#include "Option.h"
#include <vector>

class AsianOption : public Option {   //Asian Option class derived from Option
private:
<<<<<<< HEAD
	std::vector<double> timeSteps;    //The Monitoring time points
public:
    AsianOption(double expiry, const std::vector<double> monitoringTimes);   //The constructor 
private:
    const std::vector<double>& getTimeSteps() const;        //Time-steps's access on Read-Only
    
    Override AsianOption::payoffPath(std::vector<double>) const {       //Computes payoff from a price path
        
    }
=======
	std::vector<double> _timeSteps; //Timesteps of the AsianOption : (t1,t2,....,tm)
    double _strike;

public:
    AsianOption(double expiry, const std::vector<double>& monitoringTimes); //Constructor that takes the expiry date and monitoring times
    ~AsianOption(); //Destructor
>>>>>>> 4ef4b1d6cc6c5134aba7bbebed412c4f19d698a3

    std::vector<double> getTimeSteps() const override; //Getter of timeSteps
    double payoffPath(const std::vector<double>& ) const override;  //Redefine payoffPath, first we compute the mean then we call payoff (which depends on the option being a call or put option);
    bool isAsianOption() const override;  //return true

    double getStrike() const override;
    virtual OptionType getOptionType() const = 0;
    virtual double payoff(double) const = 0;
};