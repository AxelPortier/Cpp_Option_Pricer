#include <iostream>
using namespace std;
#include "CallOption.h"
#include "Option.h"
#include "EuropeanVanillaOption.h"
#include "PutOption.h"
#include "BinaryTree.h"
#include "CRRPricer.h"

#include <cmath>

CRRPricer::CRRPricer(Option* o, int N, double S0, double U, double D, double R) : _option(o), _depth(N), _asset_price(S0), _up(U), _down(D),  _interest_rate (R) {
    if (!(_down<_interest_rate && _interest_rate<_up)) {throw invalid_argument("Arbitrage");} 
    _tree.setDepth(_depth);
    _tree.setNode(0,0,_asset_price);
    for(int n = 1; n <= _depth; n++) {
        for(int i = 0; i <= n; i++) {
            _tree.setNode(n,i,_asset_price*pow(1+_up,i)*pow(1+_down,n-i));
        }
    }
}
CRRPricer::~CRRPricer() { }

void CRRPricer::DisplayTree() {
    _tree.display();
}

void CRRPricer::OptionDisplayTree() {
    _H.display();
}

void CRRPricer::compute() { //Fills the H tree with the option prices
    _H.setDepth(_depth);
    if (_depth==1) { //Case where depth = 1
        _H.setNode(0,0,_option->payoff(_tree.getNode(0,0)));
    }
    else{
        double q = (_interest_rate - _down)/(_up - _down);
        for(int i = 0; i < _depth; i++) {
                _H.setNode(_depth-1,i,_option->payoff(_tree.getNode(_depth-1,i)));
        
        }
        for (int n = _depth-2; n>=0;n--) {
            for (int i = 0; i<=n; i++) {
                _H.setNode(n,i,(q*_H.getNode(n+1,i+1)+ (1-q)*_H.getNode(n+1,i))/(1+_interest_rate));
            }
        }
    }
}
    
double CRRPricer::operator()(bool closed_form) {
    if (!closed_form) { //Closed_form is false so we use compute() and return H(0,0)
        compute();
        return _H.getNode(0, 0);
    } else { //Closed_form is true so we use the formula
        double q = (_interest_rate - _down)/(_up - _down);
        double sum = 0;
        for (int i = 0; i<=_depth-1;i++) {
            sum+= (tgamma(_depth)/(tgamma(i+1)*tgamma(_depth- i))) * (pow(q,i)*pow(1-q,_depth-1-i)) * _option->payoff(_tree.getNode(_depth-1,i));
        } //tgamma(n+1) = n!
        return (1/pow(1+_interest_rate,_depth-1))*sum;
    }
}