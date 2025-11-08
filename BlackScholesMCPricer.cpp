#include "BlackScholesMCPricer.h"
#include <vector>
#include <math.h>
#include "singleton_MT.h"
using namespace std;


BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) //Constructor
    : option_(option), S0_(initial_price), r_(interest_rate), sigma_(volatility),
      price_estimate_(0.0), sum_sq_(0.0), nb_paths_(0) {}

int BlackScholesMCPricer::getNbPaths() const { //Getter for NbPaths
    return nb_paths_;
}

BlackScholesMCPricer::~BlackScholesMCPricer() {}//Destructor

void BlackScholesMCPricer::generate(int nb_paths) {
    if (nb_paths <=0) return; //We need at least one path to be generated

    double T=option_->getExpiry();
    for (int i=0; i<nb_paths; i++) {
        vector<double> path;
        vector<double> timeSteps = option_->getTimeSteps(); //We get the timesteps from the option

        double St = S0_;
        path.reserve(timeSteps.size()); //We pre-allocate memory for timeSteps.size() elements
        double dt;
        for (int k =0; k<timeSteps.size(); k++) { //Let's generate a path
            if (k!=0) dt = timeSteps[k]-timeSteps[k-1]; //If we're not at t0 we compute the delta : t_k - t_k-1
            double Z= MT::rand_norm(); //We generate a random value N(0,1)
            St *= exp((r_ - 0.5 * sigma_ * sigma_) * dt + sigma_ * sqrt(dt) * Z); //We compute the S_(t_k) price
            path.push_back(St); //We add the price to our vector path

        }
    
        double payoff= option_->payoffPath(path);
        double H = exp(-r_ * T)* payoff;

        nb_paths_+=1;
        double delta_price = H - price_estimate_;
        price_estimate_ += delta_price/nb_paths_;
        sum_sq_ += pow(delta_price,2);
    }
}

double BlackScholesMCPricer::operator()() const {
    if (nb_paths_ == 0) __throw_invalid_argument("Price estimate undefined. Generate paths first.");
    return price_estimate_;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval() const {
    if (nb_paths_ == 0) __throw_invalid_argument("No paths generated.");
    double std_dev = sqrt(sum_sq_ / nb_paths_);
    double margin = 1.96 * std_dev / sqrt(nb_paths_);
    return { price_estimate_ - margin, price_estimate_ + margin };
}



 



