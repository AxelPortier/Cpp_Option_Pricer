#include <iostream>
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"

//g++ main.cpp BlackScholesPricer.cpp Option.cpp EuropeanVanillaOption.cpp CallOption.cpp PutOption.cpp EuropeanDigitalOption.cpp EuropeanDigitalPutOption.cpp EuropeanDigitalCallOption.cpp -o main
//./main

int main() {
    double S0 = 100, K = 101, T = 5, r = 0.01, sigma = 0.1;
    // or: double S0{100}, K{101}, T{5}, r{0.01}, sigma{0.1};

    CallOption opt1(T, K);
    PutOption opt2(T, K);

    std::cout << "European options 1\n\n";

    BlackScholesPricer pricer1(&opt1, S0, r, sigma);
    std::cout << "Call option: price = " << pricer1()
              << ", delta = " << pricer1.delta() << "\n";

    BlackScholesPricer pricer2(&opt2, S0, r, sigma);
    std::cout << "Put option: price = " << pricer2()
              << ", delta = " << pricer2.delta() << "\n";

    int N = 5;
    double U = 0.05;
    double D = -0.045;
    double R = 0.01;

    std::cout << "\nU = " << U << ", D = " << D << ", R = " << R << "\n";

    return 0;
}

