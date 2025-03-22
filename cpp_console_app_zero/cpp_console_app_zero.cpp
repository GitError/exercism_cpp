#include "cpp_console_app_zero.h"
#include "simple_linked_list.h"

int main()
{
	std::cout << "Testing Linked Lists" << std::endl;
	simple_linked_list::List empty{};
	std::cout << "Initial ll size " << empty.size() << std::endl;
	empty.push(1);
	empty.push(2);
	empty.push(3);
	std::cout << "Updated ll size " << empty.size() << std::endl;
	return 0;
}