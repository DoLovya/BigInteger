#include "Header.h"
#include "Sign.h"
#include "BigUInt.h"

int main()
{
	BN::BigUInt num1, num2;
	while (std::cin >> num1 >> num2)
	{
		std::cout << (num1 < num2) << std::endl;
		std::cout << (num1 <= num2) << std::endl;
		std::cout << (num1 > num2) << std::endl;
		std::cout << (num1 >= num2) << std::endl;
		std::cout << (num1 == num2) << std::endl;
	}
	return 0;
}