#ifndef OPTION_H 
#define OPTION_H

class Option {
private :
    double _expiry;

public :
    Option(double exp); //constructor
    double getExpiry() const; //getter
    virtual double payoff(double) const = 0; //pure virtual function
};
#endif