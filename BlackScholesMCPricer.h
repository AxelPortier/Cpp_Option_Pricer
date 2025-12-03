#pragma once
#include"Option.h"
#include <vector>

class BlackScholesMCPricer {
private:
    Option* _option;          //Option to price
    double _S0;               //Initial price of underlying
    double _r;                //Risk-free interest rate
    double _sigma;            //Volatility
    double _price_estimate;   //Current estimated price
    double _sum_sq;           //Sum of squared payoffs for variance
    long _nb_paths;           //Number of paths already generated

public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility); //Constructor
    ~BlackScholesMCPricer(); //Destructor
    
    int getNbPaths() const; //Getter to get the number of paths already generated
    void generate(int nb_paths);
    double operator()() const;
    std::vector<double> confidenceInterval() const;

};