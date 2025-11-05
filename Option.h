#pragma once

class Option {
private :
    double _expiry;

public :
    Option(double exp); //constructor
    double getExpiry() const; //getter
    virtual double payoff(double) const = 0; //pure virtual function
    virtual double payoffPath(const std::vector<double>& path) const; //non pure virtual function for path-dependent options
};
