#include "BcBigUInteger.h"
using namespace bc;

using bc::BigUInteger;

BigUInteger::BigUInteger() noexcept
{
	defauleConstruct();
}

BigUInteger::BigUInteger(const uint64_t& number) noexcept
{
	construct(number);
}

BigUInteger::BigUInteger(const String& number) noexcept
{
	construct(number);
}

BigUInteger::BigUInteger(const BigUInteger& number) noexcept
{
	copyConstruct(number);
}


BigUInteger& BigUInteger::operator= (const uint64_t& number) noexcept
{
	*this = BigUInteger(number);
	return *this;
}
BigUInteger& BigUInteger::operator= (const String& number) noexcept
{
	*this = BigUInteger(number);
	return *this;
}
BigUInteger& BigUInteger::operator= (const BigUInteger& number) noexcept
{
	this->number_ = number.number_;
	return *this;
}

BigUInteger::~BigUInteger() noexcept
{

}

size_t BigUInteger::digitNumber() const noexcept
{
	return number_.size();
}

auto BigUInteger::data() const noexcept -> const Vector&
{
	return number_;
}


void BigUInteger::defauleConstruct() noexcept
{
	construct(0ULL);
}
void BigUInteger::construct(const uint64_t& number) noexcept
{
	number_ = uint64ToRevVector<Vector>(number, 10);
}
void BigUInteger::construct(const String& number) noexcept
{
	/*assert(number.length());

	auto iPos = number.rbegin();
	for (; iPos != number.rend(); iPos++)
	{
		const int8_t& digit = () * iPos;
		if (isalnum(digit)) break;
		const int8_t& bNum = qcNum.unicode() - '0';
		number_.push_back(bNum);
	}
	if (iPos == number.rend())
	{
		sign_ = Sign::positive;
	}
	else if (iPos == number.rend() - 1)
	{
		if (number.length() == 1)
			assert(false);
		else if (*iPos == '+')
			sign_ = Sign::positive;
		else if (*iPos == '-')
			sign_ = Sign::negative;
		else
			Q_ASSERT_X(false, "BigUInteger::_init", "Not a number");
	}
	else Q_ASSERT_X(false, "BigUInteger::_init", "Not a number");*/
}
void BigUInteger::copyConstruct(const BigUInteger& number) noexcept
{
	number_ = number.number_;
}