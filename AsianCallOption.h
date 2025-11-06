#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H
#include <vector>
#include "AsianOption.h"

class AsianCallOption : public AsianOption
{
private:
    double _strike;

    public:
    AsianCallOption(std::vector<double>& timeSteps, double strike);
    double payoff(double) const override;
};

#endif