#include "Complex.h"

BN_NAMESPACE_BEGIN

Complex::Complex() : Complex(0.0, 0.0) {}
Complex::Complex(double real) : Complex(real, 0.0) {}
Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

void Complex::SetReal(const double& real) noexcept
{
	real_ = real;
}


double Complex::GetReal() const noexcept
{
	return real_;
}
double Complex::GetImag() const noexcept
{
	return imag_;
}



Complex operator+(Complex a, Complex b) noexcept
{
	return Complex(a.real_ + b.real_, a.imag_ + b.imag_);
}
Complex operator-(Complex a, Complex b) noexcept
{
	return Complex(a.real_ - b.real_, a.imag_ - b.imag_);
}
Complex operator*(Complex a, Complex b) noexcept
{
	return Complex(
		a.real_ * b.real_ - a.imag_ * b.imag_,
		a.real_ * b.imag_ + a.imag_ * b.real_
	);
}

BN_NAMESPACE_END