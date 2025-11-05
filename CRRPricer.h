#pragma once

#include "Option.h"
#include "BinaryTree.h"
#include <cmath>
#include <stdexcept>

class CRRPricer {
private:
    Option* option;
    BinaryTree<double> tree;
    BinaryTree<double> H;

public:
    int depth;
    double asset_price;
    double up;
    double down;
    double interest_rate;

    CRRPricer(Option* o, int N, double S0, double U, double D, double R);

    void DisplayTree();
    void OptionDisplayTree();
    void compute();
    double operator()(bool closed_form = false);
};
