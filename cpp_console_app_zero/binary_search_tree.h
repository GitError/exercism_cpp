#pragma once

namespace binary_search_tree {
	template <typename T>
	class binary_tree {
	public:
		binary_tree(T value) : data_(value) {}

		void insert(T value) {
			if (value <= data_) {
				if (left_) {
					left_->insert(value);
				}
				else {
					left_ = std::make_unique<binary_tree>(value);
				}
			}
			else {
				if (right_) {
					right_->insert(value);
				}
				else {
					right_ = std::make_unique<binary_tree>(value);
				}
			}
		}

		const T& data() const {
			return data_;
		}

		const std::unique_ptr<binary_tree>& left() const {
			return left_;
		}

		const std::unique_ptr<binary_tree>& right() const {
			return right_;
		}

		// Iterator class for in-order traversal
		class iterator {
		public:
			using iterator_category = std::input_iterator_tag;
			using value_type = T;
			using difference_type = std::ptrdiff_t;
			using pointer = T*;
			using reference = T&;

			iterator() = default;
			iterator(binary_tree* node) {
				traverse_left(node);
			}

			iterator& operator++() {
				if (!stack_.empty()) {
					auto node = stack_.top();
					stack_.pop();
					traverse_left(node->right_.get());
				}
				return *this;
			}

			bool operator!=(const iterator& other) const {
				return !(*this == other);
			}

			bool operator==(const iterator& other) const {
				if (stack_.empty() && other.stack_.empty()) {
					return true;
				}
				if (stack_.empty() || other.stack_.empty()) {
					return false;
				}
				return stack_.top() == other.stack_.top();
			}

			const T& operator*() const {
				return stack_.top()->data_;
			}

		private:
			std::stack<binary_tree*> stack_;

			void traverse_left(binary_tree* node) {
				while (node) {
					stack_.push(node);
					node = node->left_.get();
				}
			}
		};

		iterator begin() {
			return iterator(this);
		}

		iterator end() {
			return iterator();
		}

	private:
		T data_;
		std::unique_ptr<binary_tree> left_;
		std::unique_ptr<binary_tree> right_;
	};
}