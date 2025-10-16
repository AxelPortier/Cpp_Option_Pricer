#include "BlackScholesPricer.h"
#include <cmath>

BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, 
                                       double asset_price, 
                                       double interest_rate, 
                                       double volatility)
    : _option(option), _asset_price(asset_price), 
      _interest_rate(interest_rate), _volatility(volatility)
{}

double BlackScholesPricer::norm_cdf(double x) const {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

double BlackScholesPricer::calculate_d1() const {
    double S = _asset_price;
    double K = _option->getStrike();
    double T = _option->getExpiry();
    double r = _interest_rate;
    double sigma = _volatility;
    
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

double BlackScholesPricer::calculate_d2() const {
    return calculate_d1() - _volatility * std::sqrt(_option->getExpiry());
}

double BlackScholesPricer::operator()() const {
    double S = _asset_price;
    double K = _option->getStrike();
    double T = _option->getExpiry();
    double r = _interest_rate;
    
    double d1 = calculate_d1();
    double d2 = calculate_d2();
    
    if (_option->GetOptionType() == EuropeanVanillaOption::optionType::Call) {
        return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
    }
    else {
        return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
    }
}

double BlackScholesPricer::delta() const {
    double d1 = calculate_d1();
    
    if (_option->GetOptionType() == EuropeanVanillaOption::optionType::Call) {
        return norm_cdf(d1);
    }
    else {
        return norm_cdf(d1) - 1.0;
    }
}