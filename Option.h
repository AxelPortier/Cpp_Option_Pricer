#pragma once
#include <vector>

enum class OptionType {Call, Put}; //New specific type of option 

class Option { // abstract class containing virtual pure method 
private :
    double _expiry;

public :
    Option(double exp); //constructor
    virtual ~Option(); // virtual destructor for virtual pure class

    double getExpiry() const; //getter
    virtual double payoff(double) const = 0; //pure virtual function because every option has different payoff so it has to be override
    virtual OptionType getOptionType() const = 0;
    virtual double getStrike() const = 0;

    virtual double payoffPath(const std::vector<double>& ) const; //non pure virtual function for path-dependent options
    virtual std::vector<double> getTimeSteps();
    
    //Enable code to check what is the option
    virtual bool isDigital();
    virtual bool isAsianOption();
    virtual bool isAmericanOption();
};