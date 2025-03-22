#pragma once

#include <string>

namespace phone_number {
	class phone_number {
	private:
		std::string cleaned_number;

	public:
		phone_number(const std::string& input);
		std::string number() const;
	};
}