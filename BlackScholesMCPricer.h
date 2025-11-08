#pragma once
#include"Option.h"
#include <vector>

class BlackScholesMCPricer {
private:
    Option* option_;          //Option to price
    double S0_;               //Initial price of underlying
    double r_;                //Risk-free interest rate
    double sigma_;            //Volatility
    double price_estimate_;   //Current estimated price
    double sum_sq_;           //Sum of squared payoffs for variance
    long nb_paths_;           //Number of paths already generated

public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility); //Constructor
    ~BlackScholesMCPricer(); //Destructor
    int getNbPaths() const; //Getter to get the number of paths already generated

    void generate(int nb_paths);
    double operator()() const;
    std::vector<double> confidenceInterval() const;

};