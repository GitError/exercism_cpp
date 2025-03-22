#include "hamming.h"
#include <stdexcept>

namespace hamming {
	int compute(std::string dna1, std::string dna2)
	{
		if (dna1.size() != dna2.size())
			throw std::domain_error("DNA strands must be of equal length");
		int distance = 0;
		for (size_t i = 0; i < dna1.size(); ++i) {
			if (dna1[i] != dna2[i])
				++distance;
		}
		return distance;
	}
}