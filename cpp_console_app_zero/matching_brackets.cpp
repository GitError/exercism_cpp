#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {
	bool check(const std::string brackets) {
		std::stack<char> stack;
		for (char c : brackets) {
			switch (c) {
			case '(': case '[': case '{':
				stack.push(c);
				break;
			case ')':
				if (stack.empty() || stack.top() != '(') return false;
				stack.pop();
				break;
			case ']':
				if (stack.empty() || stack.top() != '[') return false;
				stack.pop();
				break;
			case '}':
				if (stack.empty() || stack.top() != '{') return false;
				stack.pop();
				break;
			}
		}
		return stack.empty();
	}
}