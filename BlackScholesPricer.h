#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

#include "EuropeanVanillaOption.h"
#include <cmath>

class BlackScholesPricer {
private:
    EuropeanVanillaOption* _option;  // Pointer to the option
    double _asset_price;             // Underlying asset price
    double _interest_rate;           // Risk-free interest rate
    double _volatility;              // Volatility

public:
    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, 
                       double interest_rate, double volatility); // Constructor
 
    double operator()() const; // Pricing operator to calculate the option price
    double delta() const; // Calculate the Delta of the option

private:
    double norm_cdf(double x) const; // Standard normal cumulative distribution function

    // REVOIR D1 et D2 si utile ou non, l'IA m'a dit de les mettre dans la formule car c'est plus clair.   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Helper functions to calculate d1 and d2
    double calculate_d1() const; // facteur normalisé mesurant l’écart entre le log du ratio prix sous-jacent/strike et la moitié de la variance, pondéré par la volatilité et le temps à expiration.
    double calculate_d2() const; // d1 ajusté en retranchant la volatilité multipliée par la racine carrée du temps, reflétant la probabilité risk-neutral que l’option soit dans la monnaie à maturité.
};

#endif
