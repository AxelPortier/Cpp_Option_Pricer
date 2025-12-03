#ifndef ASIANOPTION_H
#define ASIANOPTION_H
#include "Option.h"
#include <vector>

class AsianOption : public Option {   //Asian Option class derived from Option
private:
	std::vector<double> timeSteps;    //The Monitoring time points
public:
    AsianOption(double expiry, const std::vector<double> monitoringTimes);   //The constructor 
private:
    const std::vector<double>& getTimeSteps() const;        //Time-steps's access on Read-Only
    
    Override AsianOption::payoffPath(std::vector<double>) const {       //Computes payoff from a price path
        
    }

};

#endif