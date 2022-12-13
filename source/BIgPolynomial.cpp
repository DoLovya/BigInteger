#include "BIgPolynomial.h"

BN_NAMESPACE_BEGIN


Polynomial::Polynomial()
{

}
Polynomial::~Polynomial()
{

}

Polynomial::Polynomial(const std::vector<int32_t>& poly)
{
	poly_.clear();
	for (const auto& val : poly)
	{
		poly_.push_back(static_cast<double>(val));
	}
}
Polynomial::Polynomial(const std::vector<double>& poly)
{
	poly_.clear();

	for (size_t i = 0; i < poly.size(); i++)
	{
		poly_.push_back(poly[i]);
	}
}
Polynomial::Polynomial(const std::initializer_list<double>& poly)
{
	poly_.clear();

	for (const auto& real : poly)
	{
		poly_.push_back(real);
	}
}


size_t Polynomial::Size() const noexcept
{
	return poly_.size();
}
void   Polynomial::ReSize(const size_t& newSize) noexcept
{
	poly_.resize(newSize);
}

std::istream& operator>> (std::istream& in, Polynomial& poly)
{
	return in;
}
std::ostream& operator<< (std::ostream& out, const Polynomial& poly)
{
	for (int32_t i = (int32_t)poly.Size() - 1; i >= 0; i--)
	{
		int32_t num = static_cast<int32_t>(poly[i].GetReal() + 0.5);
		if (num)
		{
			printf("%dx^%d ", num, i);
		}
	}
	return out;
}

const double PI = acos(-1);


static void FFT(std::vector<Complex>& a, int32_t opt, int32_t lim,
	const std::vector<int32_t>& rev)
{
	for (size_t i = 0; i < lim; i++)
		if (i < rev[i]) std::swap(a[i], a[rev[i]]);

	for (size_t dep = 1; dep <= log2(lim); dep++) {
		size_t n = 1LL << dep;
		Complex wn = Complex(cos(2.0 * PI / n), opt * sin(2.0 * PI / n));
		for (size_t k = 0; k < lim; k += n) {
			Complex w = Complex(1, 0);
			for (size_t j = 0; j < n / 2; j++) {
				Complex t = w * a[k + j + n / 2];
				Complex u = a[k + j];
				a[k + j] = u + t;
				a[k + j + n / 2] = u - t;
				w = w * wn;
			}
		}
	}
}


Polynomial operator* (const Polynomial& lhs, const Polynomial& rhs) noexcept
{
	Polynomial mul;
	Polynomial tLhs = lhs, tRhs = rhs;

	size_t lim = 1, len = 0;
	while (lim <= tLhs.Size() + tRhs.Size()) lim <<= 1, len++;

	std::vector<int32_t> rev(lim);
	for (int i = 1; i < lim; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
	}

	mul.ReSize(lim + 1);
	tLhs.ReSize(lim + 1), tRhs.ReSize(lim + 1);
	FFT(tLhs.poly_, 1, lim, rev), FFT(tRhs.poly_, 1, lim, rev);
	for (int i = 0; i <= lim; i++)
	{
		mul[i] = tLhs[i] * tRhs[i];
	}
	FFT(mul.poly_, -1, lim, rev);
	for (int i = 0; i <= lim; i++) {
		mul[i].SetReal(mul[i].GetReal() / static_cast<double>(lim) + 0.5);
	}
	return mul;
}

Complex& Polynomial::operator[] (size_t pos) noexcept
{
	return poly_[pos];
}
Complex  Polynomial::operator[] (size_t pos) const noexcept
{
	return poly_[pos];
}


BN_NAMESPACE_END