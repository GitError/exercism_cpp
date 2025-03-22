#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {
	std::map<char, int> count(std::string sequence)
	{
		std::map<char, int> nucleotide_count{ {'A',0}, {'C', 0}, {'G', 0}, {'T',0} };
		for (char c : sequence) {
			if (c != 'A' && c != 'C' && c != 'G' && c != 'T')
				throw std::invalid_argument("Invalid nucleotide");
			++nucleotide_count[c];
		}
		return nucleotide_count;
	}
}