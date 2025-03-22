#include "protein_translation.h"
#include <unordered_map>

namespace protein_translation {
	const std::unordered_map<std::string, std::string> codon_to_protein = {
		{"AUG", "Methionine"},
		{"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
		{"UUA", "Leucine"}, {"UUG", "Leucine"},
		{"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
		{"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
		{"UGU", "Cysteine"}, {"UGC", "Cysteine"},
		{"UGG", "Tryptophan"},
		{"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
	};

	std::vector<std::string> proteins(const std::string rna) {
		std::vector<std::string> result;
		for (size_t i = 0; i < rna.size(); i += 3) {
			std::string codon = rna.substr(i, 3);
			auto it = codon_to_protein.find(codon);
			if (it == codon_to_protein.end() || it->second == "STOP") {
				break;
			}
			result.push_back(it->second);
		}
		return result;
	}
}