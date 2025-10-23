#include <iostream>
using namespace std;
#include "CallOption.h"
#include "Option.h"
#include "EuropeanVanillaOption.h"
#include "PutOption.h"

class CRRPricer {
private:
	Option* option;
public:
	int depth;
	double asset_price;
	double up;
	double down;
	double interest_rate;

	CRRPricer(Option* o, int N, double S0, double U, double D, double R) : option(o), depth(N), asset_price(S0), up(U), down(D),  interest_rate (R) {
        if (!(down<interest_rate && interest_rate<up)) {throw invalid_argument("Arbitrage");} 
    }

};

int main() {
    PutOption op(5.4,10);
    CRRPricer P(&op,5, 5.4, 0.2,-0.01,0.05);
}