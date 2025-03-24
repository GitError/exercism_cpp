#include "rna_transcription.h"
#include <stdexcept>

namespace rna_transcription {
	char to_rna(char dna) {
		switch (dna) {
		case 'G': return 'C';
		case 'C': return 'G';
		case 'T': return 'A';
		case 'A': return 'U';
		default: throw std::invalid_argument("Invalid nucleotide");
		}
	}

	std::string to_rna(const std::string dna) {
		std::string rna;
		for (char c : dna) {
			rna += to_rna(c);
		}
		return rna;
	}
}