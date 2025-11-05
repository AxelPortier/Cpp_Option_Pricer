

#include <stdexcept>

CRRPricer::CRRPricer(const Option& opt)
: option_{ opt } {
	if (option_.isAsian()) {
		throw std::invalid_argument("CRRPricer does not support Asian options");
	}
}


