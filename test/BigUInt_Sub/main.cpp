#include "Header.h"
#include "Sign.h"
#include <ctime>
#include "BigUInt.h"

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	BN::BigUInt num1, num2;
	while (std::cin >> num1 >> num2)
	{
		std::cout << num1 - num2 << std::endl;
	}
	return 0;
}