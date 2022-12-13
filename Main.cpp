#include "Header.h"
#include "Sign.h"
#include "BigUInt.h"
#include "BIgPolynomial.h"

int main()
{
	BN::BigUInt num1, num2;
	std::cin >> num1 >> num2;

	std::cout << num1 * num2 << std::endl;

	BN::Polynomial p1 = { 2 };
	BN::Polynomial p2 = { 9 };

	std::cout << p1 * p2 << std::endl;
	return 0;
}


/*
15158111821213134314239212926111613129
15159303447561417273129
*/