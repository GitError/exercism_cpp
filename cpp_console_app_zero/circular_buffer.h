#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <vector>
#include <stdexcept>

namespace circular_buffer {

	template <typename T>
	class circular_buffer {
	public:
		circular_buffer(int capacity);

		/**
		 * Reads the oldest element from the buffer
		 * Throws domain_error if buffer is empty
		 */
		T read();

		/**
		 * Writes an element to the buffer
		 * Throws domain_error if buffer is full
		 */
		void write(const T& item);

		/**
		 * Writes an element to the buffer, overwriting the oldest element
		 * if the buffer is full
		 */
		void overwrite(const T& item);

		/**
		 * Clears the buffer
		 */
		void clear();

	private:
		std::vector<T> buffer;
		size_t capacity;
		size_t size;
		size_t read_index;
		size_t write_index;

		bool is_full() const;
		bool is_empty() const;
	};

	template <typename T>
	circular_buffer<T>::circular_buffer(int capacity)
		: capacity(capacity), size(0), read_index(0), write_index(0) {
		buffer.resize(capacity);
	}

	template <typename T>
	T circular_buffer<T>::read() {
		if (is_empty()) {
			throw std::domain_error("Buffer is empty");
		}

		T value = buffer[read_index];
		read_index = (read_index + 1) % capacity;
		size--;

		return value;
	}

	template <typename T>
	void circular_buffer<T>::write(const T& item) {
		if (is_full()) {
			throw std::domain_error("Buffer is full");
		}

		buffer[write_index] = item;
		write_index = (write_index + 1) % capacity;
		size++;
	}

	template <typename T>
	void circular_buffer<T>::overwrite(const T& item) {
		if (is_full()) {
			// Overwrite the oldest item (pointed by read_index)
			buffer[read_index] = item;
			read_index = (read_index + 1) % capacity;
			// Size remains the same as we're overwriting
		}
		else {
			// If not full, behave like a normal write
			write(item);
		}
	}

	template <typename T>
	void circular_buffer<T>::clear() {
		size = 0;
		read_index = 0;
		write_index = 0;
	}

	template <typename T>
	bool circular_buffer<T>::is_full() const {
		return size == capacity;
	}

	template <typename T>
	bool circular_buffer<T>::is_empty() const {
		return size == 0;
	}
}

#endif