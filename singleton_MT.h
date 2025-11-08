#pragma once

#include <random>

class MT {
private:
    std::mt19937 _engine_;
    static std::mt19937 make_seeded_engine_();

    MT(); //Constructor

    static MT& instance(); // Return the unique instance

public:
    static double rand_unif(); //Return a uniform random number in [0,1]
    static double rand_norm(); //Return a standard normal random number N(0,1)

    MT(const MT&) = delete; //No copy
    MT& operator=(const MT&) = delete; //No copy

    ~MT(); //Destructor
};
