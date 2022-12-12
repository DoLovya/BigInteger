#include "Header.h"
#include "Sign.h"
#include "BigUInt.h"
#include "BIgPolynomial.h"

int main()
{
	std::cout << BN::DoubleIsZero(1) << std::endl;

	BN::Polynomial p1 = { 1.0, 1.0 };
	BN::Polynomial p2 = { 1.0, 1.0 };

	std::cout << p1 * p2 << std::endl;

	return 0;
}