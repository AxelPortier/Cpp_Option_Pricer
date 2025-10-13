#include "BlackScholesPricer.h"
#include <cmath>

// Pareil regarder le fichier .h pour les commentaires, ci dessous à revoir (IA) j'ai eu le temps de faire le .h mais pas celui ci
// donc j'ai généré la réponse de la classe à partir de mon .h, je vais la retravailler ou si qqn veut le faire il peut !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




// Constructeur
BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, 
                                       double asset_price, 
                                       double interest_rate, 
                                       double volatility)
    : _option(option), _asset_price(asset_price), 
      _interest_rate(interest_rate), _volatility(volatility)
{}

// Opérateur() - calcule le prix selon Black-Scholes
double BlackScholesPricer::operator()() const {
    double S = _asset_price;
    double K = _option->getStrike();
    double T = _option->getExpiry();
    double r = _interest_rate;
    
    double d1 = calculate_d1();
    double d2 = calculate_d2();
    
    // Formule Black-Scholes pour Call
    if (_option->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
    }
    // Formule Black-Scholes pour Put
    else {
        return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
    }
}

// Calcul du Delta
double BlackScholesPricer::delta() const {
    double d1 = calculate_d1();
    
    // Delta pour Call
    if (_option->GetOptionType() == EuropeanVanillaOption::optionType::call) {
        return norm_cdf(d1);
    }
    // Delta pour Put
    else {
        return norm_cdf(d1) - 1.0;
    }
}

// Fonction CDF normale standard (approximation)
double BlackScholesPricer::norm_cdf(double x) const {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

// Calcul de d1
double BlackScholesPricer::calculate_d1() const {
    double S = _asset_price;
    double K = _option->getStrike();
    double T = _option->getExpiry();
    double r = _interest_rate;
    double sigma = _volatility;
    
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

// Calcul de d2
double BlackScholesPricer::calculate_d2() const {
    return calculate_d1() - _volatility * std::sqrt(_option->getExpiry());
}
