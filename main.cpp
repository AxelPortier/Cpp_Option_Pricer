#include <iostream>
#include "CallOption.h"
#include "PutOption.h"

#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"

#include "AsianOption.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"

#include "AmericanCallOption.h"
#include "AmericanPutOption.h"
#include "AmericanOption.h"

#include "BlackScholesPricer.h"
#include "BlackScholesMCPricer.h"
#include "CRRPricer.h"

#include "BinaryTree.h"


//g++ main.cpp singleton_MT.cpp AmericanCallOption.cpp AmericanPutOption.cpp BlackScholesMCPricer.cpp AmericanOption.cpp BinaryTree.cpp AsianOption.cpp CRRPricer.cpp AsianCallOption.cpp AsianPutOption.cpp BlackScholesPricer.cpp Option.cpp EuropeanVanillaOption.cpp CallOption.cpp PutOption.cpp EuropeanDigitalOption.cpp EuropeanDigitalPutOption.cpp EuropeanDigitalCallOption.cpp -o main
//./main

int main() {
    double S0 = 100, K = 101, T = 5, r = 0.01, sigma = 0.1;
    double R = 0.01, U = 0.05, D = -0.045, N = 5; 
    // or: double S0{S0}, K{101}, T{N}, r{R}, sigma{0.1};

    CallOption call(T, K);
    PutOption put(T, K);

    EuropeanDigitalCallOption call_digital(T, K);
    EuropeanDigitalPutOption put_digital(T, K);

    AmericanCallOption american_call(T,K);
    AmericanPutOption american_put(T,K);

    std::cout << "Using the Black-Scholes Pricer :" <<std::endl<<std::endl;

    std::cout << "BlackScholes Pricer Closed Formula :"<<std::endl;
    BlackScholesPricer pricer1(&call, S0, r, sigma);
    std::cout << "European Call option: price = " << pricer1() << std::endl;
    BlackScholesPricer pricer2(&put, S0, r, sigma);
    std::cout << "European Put option: price = " << pricer2()<< std::endl;
    BlackScholesPricer pricer3(&call_digital, S0, r, sigma);
    std::cout << "European Digital Call option: price = " << pricer3()<< std::endl;
    BlackScholesPricer pricer4(&put_digital, S0, r, sigma);
    std::cout << "European Digital Put option: price = " << pricer4()<< std::endl<<std::endl;

    std::cout<<"------------------------------------------------------------------------------"<<std::endl<<std::endl;

    std::cout << "Price using the CRR Method: " << std::endl<<std::endl; 

	CRRPricer call_crr(&call, N, S0, U, D, R);
	std::cout << "Price of the EuropeanVanillaCallOption: "<< call_crr() << std::endl<<std::endl;
	std::cout << "Price of the EuropeanVanillaCallOption (closed form): " << call_crr(true) << std::endl << std::endl;

	CRRPricer put_crr(&put, N, S0, U, D, R);
	std::cout << "Price of the EuropeanVanillaPutOption: " << put_crr() << std::endl<<std::endl;
	std::cout << "Price of the EuropeanVanillaPutOption (closed form): " << put_crr(true) << std::endl << std::endl;

	CRRPricer call_digital_crr(&call_digital, N, S0, U, D, R);
	std::cout << "Price of the EuropeanDigitalCallOption: " << call_digital_crr() << std::endl<<std::endl;
	std::cout << "Price of the EuropeanDigitalCallOption (closed form): " << call_digital_crr(true) << std::endl << std::endl;

	CRRPricer put_digital_crr(&put_digital, N, S0, U, D, R);
	std::cout << "Price of the EuropeanDigitalPutOption: " << put_digital_crr() << std::endl<<std::endl;
	std::cout << "Price of the EuropeanDigitalPutOption (closed form): " << put_digital_crr(true) << std::endl << std::endl;

	CRRPricer call_american_crr(&american_call, N, S0, U, D, R);
	std::cout << "Price of the AmericanCallOption: " << call_american_crr() << std::endl<<std::endl;

	CRRPricer put_american_crr(&american_put, N, S0, U, D, R);
	std::cout << "Price of the AmericanPutOption: " << put_american_crr() << std::endl<<std::endl;

    std::cout<<"------------------------------------------------------------------------------"<<std::endl<<std::endl;

    std::cout << "Price using the MonteCarlo Pricer :"<<std::endl<<std::endl;

    BlackScholesMCPricer pricer5(&call,S0,r,sigma);
    pricer5.generate(100000);
    std::cout << "European Call option: price = " << pricer5() << std::endl<<std::endl;

    BlackScholesMCPricer pricer6(&put,S0,r,sigma);
    pricer6.generate(100000);
    std::cout << "European Put option: price = " << pricer6()<< std::endl<<std::endl;

    BlackScholesMCPricer pricer7(&call_digital,S0, r, sigma);
    pricer7.generate(100000);
    std::cout << "European Digital Call option: price = " << pricer7()<< std::endl<<std::endl;

    BlackScholesMCPricer pricer8(&put_digital, S0, r, sigma);
    pricer8.generate(100000);
    std::cout << "European Digital Put option: price = " << pricer8()<< std::endl<<std::endl;

    std::vector<double> path;
    // Remplir le vecteur avec les valeurs de 1 à N0
    for (double i = 0; i <=N; i=i+0.1) {
        path.push_back(i);
    }
    //std::cout << path.size();
	AsianCallOption asian_call(path, 101);
	AsianPutOption asian_put(path, 101);

    BlackScholesMCPricer pricer9(&asian_call, S0, r, sigma);
    pricer9.generate(100000);
    std::cout << "Asian call option: price = " << pricer9()<< std::endl<<std::endl;

    BlackScholesMCPricer pricer10(&asian_put, S0, r, sigma);
    pricer10.generate(100000);
    std::cout << "Asian Put option: price = " << pricer10()<< std::endl<<std::endl;
    return 0;
}

