#include "simple_linked_list.h"
#include <stdexcept>

namespace simple_linked_list {
	std::size_t List::size() const {
		return current_size;
	}

	void List::push(int entry) {
		Element* new_element = new Element(entry);
		new_element->next = head;
		head = new_element;
		++current_size;
	}

	int List::pop() {
		if (!head) throw std::out_of_range("List is empty");
		Element* temp = head;
		int data = head->data;
		head = head->next;
		delete temp;
		--current_size;
		return data;
	}

	void List::reverse() {
		Element* prev = nullptr;
		Element* current = head;
		while (current) {
			Element* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	List::~List() {
		while (head) {
			Element* temp = head;
			head = head->next;
			delete temp;
		}
	}
}