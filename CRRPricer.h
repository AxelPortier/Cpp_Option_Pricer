#pragma once

#include "Option.h"
#include "BinaryTree.h"
#include <cmath>
#include <stdexcept>

class CRRPricer {
private:
    Option* _option;
    BinaryTree<double> _tree;
    BinaryTree<double> _H;

    int _depth;
    double _asset_price;
    double _up;
    double _down;
    double _interest_rate;

public:
    CRRPricer(Option* o, int N, double S0, double U, double D, double R);
    CRRPricer();

    void DisplayTree() ;
    void OptionDisplayTree() ;
    void compute();
    double get(int, int) const;
    double operator()(bool closed_form = false);
};
