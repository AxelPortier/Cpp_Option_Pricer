# C++ for Finance – Option Pricing Library

Project carried out by Axel Portier, Lucas Stalter, Francis Tinval, Guillaume Turlan, and Gaspard Salluron--Besnard as part of the C++ Project course during our 2nd year of engineering studies at ESILV

### Goal: 
Implement a small C++ framework for pricing financial options: vanilla (call/put), digital, and Asian, with three pricers: closed‑form Black–Scholes, Monte Carlo under Black–Scholes, and the binomial Cox–Ross–Rubinstein (CRR), including American options and a CRR scheme that approximates Black–Scholes for large N.

### Features

  - Closed‑form Black–Scholes pricer for vanilla and digital options.

  - Monte Carlo pricer with online mean/variance and 95% confidence interval.

  - CRR binomial pricer (European closed form + backward induction; American exercise policy).

  - BS‑parametrized CRR that converges to Black–Scholes as N increases.


### Architecture

Core abstractions: Option (abstract), EuropeanVanillaOption, EuropeanDigitalOption, AsianOption.

Pricers: BlackScholesPricer, BlackScholesMCPricer, CRRPricer.

Utilities: BinaryTree<T>, MT random generator singleton.


### Quick start

Standard: C++17, STL only, no external deps.

Build (example):

    - CMake: configure and build a static library target.

    - Visual Studio: add include/ and src/ files to a Static Library project.

##### Link your own main() in a separate target for local tests (remove before submit).


### Usage examples

  - Price a European Call with Black–Scholes (show minimal code snippet).

  - Run Monte Carlo for an Asian Call and print the 95% CI.

  - Price an American Put with CRR and retrieve the exercise map.


