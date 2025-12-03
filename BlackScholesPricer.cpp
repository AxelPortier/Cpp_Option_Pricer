#include "BlackScholesPricer.h"
#include <cmath>
#define _PI 3.14159265358979

BlackScholesPricer::BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility)
    : _option(option), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility) {}

    BlackScholesPricer::~BlackScholesPricer() = default;            //Constructor


double BlackScholesPricer::operator()() const {
    double strike = _option->getStrike();
    double expiry = _option->getExpiry();
    double d1 = calculate_d1();
    double d2 = calculate_d2();

    if (_option->getOptionType() == OptionType::Call) { // Call
        return _option->isDigital() ? std::exp(-_interest_rate * expiry) * norm_cdf(d2) : _asset_price * norm_cdf(d1)- strike * std::exp(-_interest_rate * expiry) * norm_cdf(d2);
    } else { // Put
        return _option->isDigital() ? std::exp(-_interest_rate * expiry) * norm_cdf(-d2) : strike * std::exp(-_interest_rate * expiry) * norm_cdf(-d2) - _asset_price * norm_cdf(-d1);
    }
}

double BlackScholesPricer::delta() const {
    double expiry = _option->getExpiry();

    double d1 = calculate_d1();
    double d2 = calculate_d2();

    if (_option->getOptionType() == OptionType::Call) { // Call
        return _option->isDigital() ? std::exp(-_interest_rate * _option->getExpiry()) * norm_pdf(d2) / (_asset_price * _volatility * std::sqrt(expiry)) : norm_cdf(d1);    //Vanilla call delta
    } else { // Put
        return _option->isDigital() ? -std::exp(-_interest_rate * _option->getExpiry()) * norm_pdf(d2) / (_asset_price * _volatility * std::sqrt(expiry)) : norm_cdf(d1)- 1.0; //Vanille put delta
    }
}

double BlackScholesPricer::norm_cdf(double x) const {return 0.5 * std::erfc(-x / std::sqrt(2.0));}  //We compute the standard normam CDF
double BlackScholesPricer::norm_pdf(double x) const {return 1.0 / std::sqrt(2.0 * _PI) * std::exp(-0.5 * x * x);}   //We compute the standard normal PDF

double BlackScholesPricer::calculate_d1() const {
    double strike = _option->getStrike();
    double expiry = _option->getExpiry();

    return (std::log(_asset_price / strike) + (_interest_rate + 0.5 * _volatility * _volatility) * expiry) / (_volatility * std::sqrt(expiry));
}   //BlackScholes d1 formula

double BlackScholesPricer::calculate_d2() const {return calculate_d1() - _volatility * std::sqrt(_option->getExpiry());}
//BlackScholes d2 formula