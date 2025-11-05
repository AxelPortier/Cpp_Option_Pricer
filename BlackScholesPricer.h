#pragma once

#include "EuropeanVanillaOption.h"
#include <cmath>

class BlackScholesPricer {
private:
    Option* _option;  // Pointer to the option
    double _asset_price;             // Underlying asset price
    double _interest_rate;           // Risk-free interest rate
    double _volatility;              // Volatility

public:
    BlackScholesPricer(Option* option, double asset_price, 
                       double interest_rate, double volatility);
    double operator()() const;
    double delta() const;
    double norm_cdf(double x) const;
    double calculate_d1() const;
    double calculate_d2() const;
};
