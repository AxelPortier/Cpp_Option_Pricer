#pragma once

#include "Option.h"
#include "BinaryTree.h"
#include <cmath>
#include <stdexcept>

class CRRPricer {
private:
    Option* _option;
    BinaryTree<double> _tree; // we stock the payoffs for an option
    BinaryTree<bool> _exerciseTree; // we stock the true/false exercise conditions for american option
    BinaryTree<double> _H; // we stock the prices for an option
    
    int _depth;
    double _asset_price;
    double _up;
    double _down;
    double _interest_rate;

public:
    CRRPricer(Option* o, int depth, double S0, double U, double D, double R);
    CRRPricer(Option* o, int depth, double S0, double interest_rate, double volatility);
    ~CRRPricer();

    void DisplayTree() ;
    void OptionDisplayTree() ;
    void compute();
    double get(int, int) const;
    double operator()(bool closed_form = false);
    bool getExercise(int, int);
    void calculateParamsBS(int depth, double r, double volatility);
    void initTree(int);
};
