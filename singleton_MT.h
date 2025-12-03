#pragma once

#include <random>

class MT {
private:
    std::mt19937 _engine_; // The Mersenne Twister engine
    static std::mt19937 make_seeded_engine_(); // Helper to seed the engine

    MT(); // Constructor to prevent direct instantiation

    static MT& instance(); // Return the unique instance (internal accessor)

public:
    static double rand_unif(); // Return a uniform random number in [0,1]
    static double rand_norm(); // Return a standard normal random number N(0,1)

    MT(const MT&) = delete; // No copy
    MT& operator=(const MT&) = delete; // No copy

    ~MT(); // Destructor
};
