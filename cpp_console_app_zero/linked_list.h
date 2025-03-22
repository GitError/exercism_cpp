#pragma once

#include <stdexcept>

namespace linked_list {

	template <typename T>
	class List {
	private:
		struct Node {
			T data;
			Node* prev;
			Node* next;

			Node(const T& value, Node* previous = nullptr, Node* following = nullptr)
				: data(value), prev(previous), next(following) {
			}
		};

		Node* head_;
		Node* tail_;
		int size_;

	public:
		List() : head_(nullptr), tail_(nullptr), size_(0) {}

		~List() {
			while (head_) {
				Node* temp = head_;
				head_ = head_->next;
				delete temp;
			}
		}

		// Adds an element to the end of the list
		void push(const T& value) {
			Node* new_node = new Node(value, tail_, nullptr);

			if (tail_) {
				tail_->next = new_node;
			}
			else {
				head_ = new_node;  // If list was empty, this is also the head
			}

			tail_ = new_node;
			size_++;
		}

		// Removes and returns the last element of the list
		T pop() {
			if (!tail_) {
				throw std::out_of_range("Cannot pop from an empty list");
			}

			T value = tail_->data;
			Node* old_tail = tail_;

			if (head_ == tail_) {
				// Last element in the list
				head_ = nullptr;
				tail_ = nullptr;
			}
			else {
				tail_ = tail_->prev;
				tail_->next = nullptr;
			}

			delete old_tail;
			size_--;
			return value;
		}

		// Removes and returns the first element of the list
		T shift() {
			if (!head_) {
				throw std::out_of_range("Cannot shift from an empty list");
			}

			T value = head_->data;
			Node* old_head = head_;

			if (head_ == tail_) {
				// Last element in the list
				head_ = nullptr;
				tail_ = nullptr;
			}
			else {
				head_ = head_->next;
				head_->prev = nullptr;
			}

			delete old_head;
			size_--;
			return value;
		}

		// Adds an element to the start of the list
		void unshift(const T& value) {
			Node* new_node = new Node(value, nullptr, head_);

			if (head_) {
				head_->prev = new_node;
			}
			else {
				tail_ = new_node;  // If list was empty, this is also the tail
			}

			head_ = new_node;
			size_++;
		}

		// Returns the number of elements in the list
		int count() const {
			return size_;
		}

		// Removes the first occurrence of the specified value from the list
		// Returns true if an element was deleted, false otherwise
		bool erase(const T& value) {
			if (!head_) {
				return false;  // List is empty
			}

			// Check if it's the head
			if (head_->data == value) {
				Node* old_head = head_;
				if (head_ == tail_) {
					// It's the only element
					head_ = nullptr;
					tail_ = nullptr;
				}
				else {
					head_ = head_->next;
					head_->prev = nullptr;
				}
				delete old_head;
				size_--;
				return true;
			}

			// Check all other nodes
			Node* current = head_->next;
			while (current) {
				if (current->data == value) {
					// Found the value to erase
					if (current == tail_) {
						// It's the tail
						tail_ = tail_->prev;
						tail_->next = nullptr;
					}
					else {
						// It's in the middle
						current->prev->next = current->next;
						current->next->prev = current->prev;
					}
					delete current;
					size_--;
					return true;
				}
				current = current->next;
			}

			return false;  // Value not found
		}
	};
}