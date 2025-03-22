#pragma once

namespace complex_numbers {
	class Complex {
	private:
		double real_part;
		double imaginary_part;
	public:
		// Constructor
		Complex(double real = 0.0, double imag = 0.0)
			: real_part(real), imaginary_part(imag) {
		}

		// Accessor methods
		double real() const { return real_part; }
		double imag() const { return imaginary_part; }

		// Basic operations
		Complex conj() const;
		double abs() const;
		Complex exp() const;

		// Arithmetic operators
		Complex operator+(const Complex& other) const;
		Complex operator-(const Complex& other) const;
		Complex operator*(const Complex& other) const;
		Complex operator/(const Complex& other) const;

		// Operations with real numbers
		Complex operator+(double scalar) const;
		Complex operator-(double scalar) const;
		Complex operator*(double scalar) const;
		Complex operator/(double scalar) const;

		// Friend functions for operations where real number is on the left
		friend Complex operator+(double scalar, const Complex& complex);
		friend Complex operator-(double scalar, const Complex& complex);
		friend Complex operator*(double scalar, const Complex& complex);
		friend Complex operator/(double scalar, const Complex& complex);
	};
}