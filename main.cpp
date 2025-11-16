#include <iostream>
#include "CallOption.h"
#include "PutOption.h"

#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"

#include "AsianOption.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"


#include "BlackScholesPricer.h"
#include "BlackScholesMCPricer.h"
#include "CRRPricer.h"

#include "BinaryTree.h"


//g++ main.cpp BinaryTree.cpp AsianOption.cpp CRRPricer.cpp AsianCallOption.cpp AsianPutOption.cpp BlackScholesPricer.cpp Option.cpp EuropeanVanillaOption.cpp CallOption.cpp PutOption.cpp EuropeanDigitalOption.cpp EuropeanDigitalPutOption.cpp EuropeanDigitalCallOption.cpp -o main
//./main

int main() {
    double S0 = 100, K = 101, T = 5, r = 0.01, sigma = 0.1;
    double R = 0.01, U = 0.05, D = -0.045, N = 5; 
    // or: double S0{100}, K{101}, T{5}, r{0.01}, sigma{0.1};

    CallOption call(T, K);
    PutOption put(T, K);

    EuropeanDigitalCallOption call_digital(T, K);
    EuropeanDigitalPutOption put_digital(T, K);

    std::cout << "BlackScholes Pricer Closed Formula :"<<std::endl;
    BlackScholesPricer pricer1(&call, S0, r, sigma);
    std::cout << "European Call option: price = " << pricer1() << std::endl;
    BlackScholesPricer pricer2(&put, S0, r, sigma);
    std::cout << "European Put option: price = " << pricer2()<< std::endl;
    BlackScholesPricer pricer3(&call_digital, S0, r, sigma);
    std::cout << "European Digital Call option: price = " << pricer3()<< std::endl;
    BlackScholesPricer pricer4(&put_digital, S0, r, sigma);
    std::cout << "European Digital Put option: price = " << pricer4()<< std::endl;


    // std::cout << "MC :"<<std::endl;
    // BlackScholesMCPricer pricer5(Option* opt1, double S0, double r, double sigma);
    // std::cout << "European Call option: price = " << pricer5() << std::endl;
    // BlackScholesMCPricer pricer6(Option* opt1, double S0, double r, double sigma);
    // pricer5.generate(10);
    // std::cout << "European Put option: price = " << pricer6()<< std::endl;
    // BlackScholesMCPricer pricer7(Option* opt1, double S0, double r, double sigma);
    // std::cout << "European Digital Call option: price = " << pricer7()<< std::endl;
    // BlackScholesMCPricer pricer8(Option* opt1, double S0, double r, double sigma);
    // std::cout << "European Digital Put option: price = " << pricer8()<< std::endl;


    std::cout << "Price using the CRR Method: " << std::endl; 
	std::cout << "Tree of the EuropeanVanillaCallOption: " << std::endl << std::endl; 
	CRRPricer call_crr(&call, 5, 100, 0.05, -0.045, 0.01);
	std::cout << "Price of the EuropeanVanillaCallOption: "<< call_crr() << std::endl;
	std::cout << "Price of the EuropeanVanillaCallOption (closed form): " << call_crr(true) << std::endl << std::endl;

	std::cout << "Tree of the EuropeanVanillaPutOption: " << std::endl << std::endl;
	CRRPricer put_crr(&put, 5, 100, 0.05, -0.045, 0.01);
	std::cout << "Price of the EuropeanVanillaPutOption: " << put_crr() << std::endl;
	std::cout << "Price of the EuropeanVanillaPutOption (closed form): " << put_crr(true) << std::endl << std::endl;

	std::cout << "Tree of the EuropeanDigitalCallOption: " << std::endl << std::endl;
	CRRPricer call_digital_crr(&call_digital, 5, 100, 0.05, -0.045, 0.01);
	std::cout << "Price of the EuropeanDigitalCallOption: " << call_digital_crr() << std::endl;
	std::cout << "Price of the EuropeanDigitalCallOption (closed form): " << call_digital_crr(true) << std::endl << std::endl;

	std::cout << "Tree of the EuropeanDigitalPutOption: " << std::endl << std::endl;
	CRRPricer put_digital_crr(&put_digital, 5, 100, 0.05, -0.045, 0.01);
	std::cout << "Price of the EuropeanDigitalPutOption: " << put_digital_crr() << std::endl;
	std::cout << "Price of the EuropeanDigitalPutOption (closed form): " << put_digital_crr(true) << std::endl << std::endl;

    std::vector<double> path;
    // Remplir le vecteur avec les valeurs de 1 à 50
    for (double i = 0; i <=5; i=i+0.1) {
        path.push_back(i);
    }
    //std::cout << path.size();
	AsianCallOption asian_call(path, 101);
	AsianPutOption asian_put(path, 101);

    return 0;
}

