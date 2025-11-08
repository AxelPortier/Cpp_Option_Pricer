#include "singleton_MT.h"
#include <random>

//Constructor
MT::MT() : engine_(make_seeded_engine_()) {}

MT& MT::instance() { //Create a single MT instance so we always use the same engine
    static MT inst;
    return inst;
}

MT::~MT(){} //Destructor

 	std::mt19937 MT::make_seeded_engine_() { //Return a seed to generate random values
    std::random_device rd;
    return std::mt19937(rd());
}

double MT::rand_unif() { //Return a uniform random number in [0,1]
	auto& gen = instance().engine_;
	static thread_local std::uniform_real_distribution<double> dist(0.0, 1.0); //We create an uniform distribution with static(so we don't need to create a new ditribution each time) & thread_local(so each thread has its own distribution dist)
    return dist(gen);
}

double MT::rand_norm() { //Return a standard normal random number N(0,1)
	auto &gen = instance().engine_;
	static thread_local std::normal_distribution<double> dist(0.0, 1.0);
    return dist(gen);
}


