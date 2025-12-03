#pragma once
#include "Option.h"
#include <vector>

<<<<<<< HEAD
// Base class for Asian options, derived from Option
class AsianOption : public Option {
private:
    std::vector<double> _timeSteps; // Time steps (t1, t2, ..., tm)
    double _strike;                 // Strike of the Asian option

public:
    AsianOption(double expiry, const std::vector<double>& monitoringTimes); // Constructor
    ~AsianOption();                                                         // Destructor
=======
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
>>>>>>> 9c335390c2c970687066acb19fe5931eaef5c82c

    std::vector<double> getTimeSteps() const override;                      // Getter for time steps
    double payoffPath(const std::vector<double>&) const override;           // Payoff from a full price path
    bool isAsianOption() const override;                                    // Returns true

    double getStrike() const override;                                      // Getter for strike
    virtual OptionType getOptionType() const = 0;                           // Call or Put
    virtual double payoff(double) const = 0;                                // Payoff from average price
};
