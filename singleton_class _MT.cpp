

#include <iostream>
#include <random>
#include <mutex>
#include <array>

class MT {
public:
	static double rand_unif() {
		auto& gen = instance().engine_;
		static thread_local std::uniform_real_distribution<double> dist(0.0, 1.0);
		return dist(gen);
	}

	static double rand_norm() {
		auto& gen = instance().engine_;
		static thread_local std::normal_distribution<double> dist(0.0, 1.0);
		return dist(gen);
	}

	MT(const MT&) = delete;
	MT& operator=(const MT&) = delete;

private:
	MT() : engine_(make_seeded_engine_()) {}
	~MT() = default;

	static MT& instance() {
		static MT inst;
		return inst;
	}

	static std::mt19937 make_seeded_engine_() {
		std::random_device rd;
		std::_Empty_array_element<std::uint32_t, std::mt19937::state_size> seed_data{};
		for (auto& x : seed_data) x = rd();
		std::seed_seq seq(seed_data.begin(), seed_data.end());
		return std::mt19937(seq);
	}

std:mt19937 engine_;

};

