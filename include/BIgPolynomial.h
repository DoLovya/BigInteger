#ifndef INCLUDE_BIG_POLYNOMIAL_H
#define INCLUDE_BIG_POLYNOMIAL_H

#include "Header.h"

#include "Complex.h"
#include "Algorithm.h"

BN_NAMESPACE_BEGIN

class Polynomial
{
public:
	Polynomial();
	virtual ~Polynomial();

	Polynomial(const std::vector<double>& poly);
	Polynomial(const std::initializer_list<double>& poly);


	size_t Size() const noexcept;
	void   ReSize(const size_t& newSize) noexcept;

	friend std::istream& operator>> (std::istream& in, Polynomial& poly);
	friend std::ostream& operator<< (std::ostream& out, const Polynomial& poly);

	friend Polynomial operator* (const Polynomial& lhs, const Polynomial& rhs) noexcept;

	Complex& operator[] (size_t pos) noexcept;
	Complex  operator[] (size_t pos) const noexcept;

private:
	//void InitRev(const size_t& len) noexcept;

private:
	std::vector<Complex> poly_;
};

BN_NAMESPACE_END
#endif // !INCLUDE_BIG_POLYNOMIAL_H