#include "AsianOption.h"
#include <numeric>
#include <vector>
using namespace std;

AsianOption::AsianOption(double expiry,const vector<double>& monitoringTimes) : Option(expiry),timeSteps_(monitoringTimes) //Constructor that takes expiry (from Option class), and monitoringTimes = (t1,...,tm)
{ }
AsianOption::~AsianOption(){}//Destructor

const vector<double>& AsianOption::getTimeSteps() const {return timeSteps_;} //To get the timeSteps = (t1,...,tm)

double AsianOption::payoffPath(const vector<double>& path) const {
	if (path.empty()) {
		return 0.0; //Case where the path is empty : we return 0
	}

	double sum = 0;
	for (int i = 0; i<path.size();i++) {
		sum+= path[i];
	}
	return payoff((1/ static_cast<double>(path.size()))* sum); //We use the payoff function on the mean. Note that the payoff depends on the option being a put or a call
}

bool AsianOption::isAsianOption() const{return true;}