#include <iostream>
using namespace std;
#include "CallOption.h"
#include "Option.h"
#include "EuropeanVanillaOption.h"
#include "PutOption.h"
#include "BinaryTree.h"
#include "CRRPricer.h"

#include <cmath>




CRRPricer::CRRPricer(Option* o, int N, double S0, double U, double D, double R) : option(o), depth(N), asset_price(S0), up(U), down(D),  interest_rate (R) {
    if (!(down<interest_rate && interest_rate<up)) {throw invalid_argument("Arbitrage");} 
    
    tree.setDepth(depth);
    tree.setNode(0,0,asset_price);
    for(int n = 1; n < depth; n++) {
        for(int i = 0; i <= n; i++) {
            tree.setNode(n,i,asset_price*pow(1+up,i)*pow(1+down,n-i));
        }
    }
}

void CRRPricer::DisplayTree() {
    tree.display();
}

void CRRPricer::OptionDisplayTree() {
    H.display();
}

void CRRPricer::compute() { //Fills the H tree with the option prices
    H.setDepth(depth);
    if (depth==1) { //Case where depth = 1
        H.setNode(0,0,option->payoff(tree.getNode(0,0)));
    }
    else{
        double q = (interest_rate - down)/(up - down);
        for(int i = 0; i < depth; i++) {
                H.setNode(depth-1,i,option->payoff(tree.getNode(depth-1,i)));
        
        }
        for (int n = depth-2; n>=0;n--) {
            for (int i = 0; i<=n; i++) {
                H.setNode(n,i,(q*H.getNode(n+1,i+1)+ (1-q)*H.getNode(n+1,i))/(1+interest_rate));
            }
        }
    }
}
    
double CRRPricer::operator()(bool closed_form) {
    if (!closed_form) { //Closed_form is false so we use compute() and return H(0,0)
        compute();
        return H.getNode(0, 0);
    } else { //Closed_form is true so we use the formula
        double q = (interest_rate - down)/(up - down);
        double sum = 0;
        for (int i = 0; i<=depth-1;i++) {
            sum+= (tgamma(depth)/(tgamma(i+1)*tgamma(depth- i))) * (pow(q,i)*pow(1-q,depth-1-i)) * option->payoff(tree.getNode(depth-1,i));
        } //tgamma(n+1) = n!
        return (1/pow(1+interest_rate,depth-1))*sum;
    }
}