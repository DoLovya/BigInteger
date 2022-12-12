#ifndef INCLUDE_COMPLEX_H
#define INCLUDE_COMPLEX_H

#include "Header.h"

BN_NAMESPACE_BEGIN

class Complex
{
public:
	Complex();
	Complex(double real);
	Complex(double real, double imag);

	void SetReal(const double& real) noexcept;

	double GetReal() const noexcept;
	double GetImag() const noexcept;

	friend Complex operator+(Complex a, Complex b) noexcept;
	friend Complex operator-(Complex a, Complex b) noexcept;
	friend Complex operator*(Complex a, Complex b) noexcept;

private:
	double real_;  // Êµ²¿
	double imag_;  // Ðé²¿
};

BN_NAMESPACE_END

#endif // !INCLUDE_COMPLEX_H