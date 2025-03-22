#pragma once
#include <mutex>
#include <stdexcept>

namespace Bankaccount {
	class Bankaccount {
	public:
		Bankaccount() : is_open(false), balance_amount(0) {}

		void open() {
			std::lock_guard<std::mutex> lock(mtx);
			if (is_open) {
				throw std::runtime_error("Account is already open");
			}
			is_open = true;
			balance_amount = 0;
		}

		void close() {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Account is already closed");
			}
			is_open = false;
		}

		void deposit(int amount) {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot deposit to a closed account");
			}
			if (amount < 0) {
				throw std::runtime_error("Cannot deposit a negative amount");
			}
			balance_amount += amount;
		}

		void withdraw(int amount) {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot withdraw from a closed account");
			}
			if (amount < 0) {
				throw std::runtime_error("Cannot withdraw a negative amount");
			}
			if (amount > balance_amount) {
				throw std::runtime_error("Insufficient funds");
			}
			balance_amount -= amount;
		}

		int balance() const {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot check balance of a closed account");
			}
			return balance_amount;
		}

	private:
		mutable std::mutex mtx;
		bool is_open;
		int balance_amount;
	};
}
