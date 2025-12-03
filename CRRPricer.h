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
    
    int _depth;            // Number of time steps (N)
    double _asset_price;   // Initial spot price (S0)
    double _up;            // Up factor (U)
    double _down;          // Down factor (D)
    double _interest_rate; // Risk-free rate per step (R)

public:
    // Constructor 1: Standard CRR with explicit U, D, R parameters
    CRRPricer(Option* o, int depth, double S0, double U, double D, double R);
    // Constructor 2: Initialization using Black-Scholes parameters (volatility, r)
    // Computes U, D, and R based on the limiting behavior
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
