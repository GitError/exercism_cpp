#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {
	// Complex conjugate: a + bi -> a - bi
	Complex Complex::conj() const {
		return Complex(real_part, -imaginary_part);
	}

	// Absolute value: |a + bi| = sqrt(a² + b²)
	double Complex::abs() const {
		return std::sqrt(real_part * real_part + imaginary_part * imaginary_part);
	}

	// Complex exponential: e^(a + bi) = e^a * (cos(b) + i*sin(b))
	Complex Complex::exp() const {
		double e_real = std::exp(real_part);
		return Complex(
			e_real * std::cos(imaginary_part),
			e_real * std::sin(imaginary_part)
		);
	}

	// Addition: (a + bi) + (c + di) = (a + c) + (b + d)i
	Complex Complex::operator+(const Complex& other) const {
		return Complex(
			real_part + other.real_part,
			imaginary_part + other.imaginary_part
		);
	}

	// Subtraction: (a + bi) - (c + di) = (a - c) + (b - d)i
	Complex Complex::operator-(const Complex& other) const {
		return Complex(
			real_part - other.real_part,
			imaginary_part - other.imaginary_part
		);
	}

	// Multiplication: (a + bi) * (c + di) = (ac - bd) + (bc + ad)i
	Complex Complex::operator*(const Complex& other) const {
		return Complex(
			real_part * other.real_part - imaginary_part * other.imaginary_part,
			imaginary_part * other.real_part + real_part * other.imaginary_part
		);
	}

	// Division: (a + bi) / (c + di) = (ac + bd)/(c² + d²) + (bc - ad)/(c² + d²)i
	Complex Complex::operator/(const Complex& other) const {
		double denominator = other.real_part * other.real_part +
			other.imaginary_part * other.imaginary_part;

		return Complex(
			(real_part * other.real_part + imaginary_part * other.imaginary_part) / denominator,
			(imaginary_part * other.real_part - real_part * other.imaginary_part) / denominator
		);
	}

	// Operations with scalar values
	Complex Complex::operator+(double scalar) const {
		return Complex(real_part + scalar, imaginary_part);
	}

	Complex Complex::operator-(double scalar) const {
		return Complex(real_part - scalar, imaginary_part);
	}

	Complex Complex::operator*(double scalar) const {
		return Complex(real_part * scalar, imaginary_part * scalar);
	}

	Complex Complex::operator/(double scalar) const {
		return Complex(real_part / scalar, imaginary_part / scalar);
	}

	// Friend functions for operations where real number is on the left
	Complex operator+(double scalar, const Complex& complex) {
		return Complex(scalar + complex.real_part, complex.imaginary_part);
	}

	Complex operator-(double scalar, const Complex& complex) {
		return Complex(scalar - complex.real_part, -complex.imaginary_part);
	}

	Complex operator*(double scalar, const Complex& complex) {
		return Complex(scalar * complex.real_part, scalar * complex.imaginary_part);
	}

	Complex operator/(double scalar, const Complex& complex) {
		double denominator = complex.real_part * complex.real_part +
			complex.imaginary_part * complex.imaginary_part;

		return Complex(
			scalar * complex.real_part / denominator,
			-scalar * complex.imaginary_part / denominator
		);
	}
}