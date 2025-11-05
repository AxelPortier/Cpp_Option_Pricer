#ifndef ASIANOPTION_H
#define ASIANOPTION_H
#include "Option.h"
#include <vector>

class AsianOption : public Option {
private:
	std::vector<double> timeSteps;
public:
    AsianOption(double expiry, const std::vector<double> monitoringTimes);
private:
    const std::vector<double>& getTimeSteps() const;
    Override AsianOption::payoffPath(std::vector<double>) const {
        
    }

};

#endif