#include "BlackScholesMCPricer.h"
#include <vector>
#include <math.h>
#include "singleton_MT.h"
#include <stdexcept>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) //Constructor
    : _option(option), _S0(initial_price), _r(interest_rate), _sigma(volatility),
      _price_estimate(0.0), _sum_sq(0.0), _nb_paths(0) {}

int BlackScholesMCPricer::getNbPaths() const { //Getter for NbPaths
    return _nb_paths;
}

BlackScholesMCPricer::~BlackScholesMCPricer() {}//Destructor

void BlackScholesMCPricer::generate(int nb_paths) {
    if (nb_paths <=0) return; //We need at least one path to be generated

    double T=_option->getExpiry();
    for (int i=0; i<nb_paths; i++) {
        std::vector<double> path;
        std::vector<double> timeSteps = _option->getTimeSteps(); //We get the timesteps from the option

        double St = _S0;
        path.reserve(timeSteps.size()); //We pre-allocate memory for timeSteps.size() elements
        double dt = timeSteps[0];
        for (int k =0; k<timeSteps.size(); k++) { //Let's generate a path
            if (k!=0) dt = timeSteps[k]-timeSteps[k-1]; //If we're not at t0 we compute the delta : t_k - t_k-1
            double Z= MT::rand_norm(); //We generate a random value N(0,1)
            St *= exp((_r - 0.5 * _sigma * _sigma) * dt + _sigma * sqrt(dt) * Z); //We compute the S_(t_k) price
            path.push_back(St); //We add the price to our vector path
        }
    
        double payoff= _option->payoffPath(path);
        double H = exp(-_r * T)* payoff;

        _nb_paths+=1;
        double delta_price = H - _price_estimate;
        _price_estimate += delta_price/_nb_paths;
        _sum_sq += H*H;
    }
}

double BlackScholesMCPricer::operator()() const {
    if (_nb_paths == 0) throw std::invalid_argument("Price estimate undefined. Generate paths first.");
    return _price_estimate;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval() const {
    if (_nb_paths == 0) throw std::invalid_argument("No paths generated.");
    double mean_sq = _sum_sq / _nb_paths;
    double variance = mean_sq - _price_estimate * _price_estimate;
    double std_dev = std::sqrt(variance);
    double margin = 1.96 * std_dev / sqrt(_nb_paths);
    return { _price_estimate - margin, _price_estimate + margin };
}



