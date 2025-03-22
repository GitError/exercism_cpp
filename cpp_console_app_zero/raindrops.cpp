#include "raindrops.h"

namespace raindrops {
	std::string convert(int drops) {
		std::string answer;
		if (drops % 3 == 0) answer += "Pling";
		if (drops % 5 == 0) answer += "Plang";
		if (drops % 7 == 0) answer += "Plong";
		if (answer.empty()) answer = std::to_string(drops);
		return answer;
	}
}