#include "BigUInt.h"

BN_NAMESPACE_BEGIN


BigUInt::BigUInt() noexcept
{
	DefauleConstruct();
}

BigUInt::BigUInt(const uint64_t& number) noexcept
{
	Construct(number);
}

BigUInt::BigUInt(const std::string& number) noexcept
{
	Construct(number);
}

BigUInt::BigUInt(const BigUInt& number) noexcept
{
	CopyConstruct(number);
}


BigUInt& BigUInt::operator= (const uint64_t& number) noexcept
{
	*this = BigUInt(number);
	return *this;
}
BigUInt& BigUInt::operator= (const std::string& number) noexcept
{
	*this = BigUInt(number);
	return *this;
}
BigUInt& BigUInt::operator= (const BigUInt& number) noexcept
{
	this->uInt_ = number.uInt_;
	return *this;
}

BigUInt::~BigUInt() noexcept
{

}

size_t BigUInt::Size() const noexcept
{
	return uInt_.size();
}

auto BigUInt::Data() const noexcept -> const Number&
{
	return uInt_;
}


void BigUInt::DefauleConstruct() noexcept
{
	Construct(0ULL);
}
void BigUInt::Construct(const uint64_t& number) noexcept
{
	uInt_ = uint64ToRevVector<int32_t>(number, 10);
}
void BigUInt::Construct(const std::string& str) noexcept
{
	if (str.empty()) return;
	if (!uInt_.empty()) uInt_.clear();
	//XASSERT(str.length() != 0, L"Number length is zero");

	auto bIter = str.begin();
	while (bIter != str.end() - 1 && *bIter == '0')
	{
		XASSERT(isdigit(*bIter), L"Number has the illegal character");
		bIter++;
	}

	for (auto iter = str.end() - 1; ; iter--)
	{
		XASSERT(isdigit(*iter), L"Number has the illegal character");
		uInt_.push_back(charToDigit(*iter));
		if (iter == bIter) break;
	}
}
void BigUInt::CopyConstruct(const BigUInt& number) noexcept
{
	uInt_ = number.uInt_;
}
bool BigUInt::IsZero() const noexcept
{
	return (Size() == 1 && uInt_.back() == 0);
}


void BigUInt::Add(const BigUInt& rhs)
{
	if (IsZero())
	{
		uInt_ = rhs.uInt_;
	}
	else
	{
		uInt_.resize(std::max(Size(), rhs.Size()) + 1);
		int32_t carryBit = 0;
		for (size_t i = 0; i < uInt_.size() - 1; i++)
		{
			carryBit = GetCarryBit<10>(uInt_[i], rhs[i]);
			uInt_[i] += rhs[i];
			if (uInt_[i] >= 10)
			{
				uInt_[i] -= 10;
			}
			uInt_[i + 1] += carryBit;
		}
		if (!carryBit)
		{
			uInt_.pop_back();
		}
	}
}
void BigUInt::Sub(const BigUInt& rhs)
{

}

std::istream& operator>>(std::istream& in, BigUInt& bigUInt)
{
	std::string tmpStr;
	in >> tmpStr;
	bigUInt.Construct(tmpStr);
	return in;
}

std::ostream& operator<< (std::ostream& out, const BigUInt& bigUInt)
{
	auto revIter = bigUInt.Data().rbegin();
	while (revIter != bigUInt.Data().rend())
	{
		out << *revIter++;
	}
	return out;
}

BigUInt operator+ (const BigUInt& lhs, const BigUInt& rhs)
{
	BigUInt res(0);
	res.Add(lhs);
	res.Add(rhs);
	return res;
}

bool operator< (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) < 0 ? true : false;
}
bool operator<= (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) <= 0 ? true : false;
}
bool operator> (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) > 0 ? true : false;
}
bool operator>= (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) >= 0 ? true : false;
}
bool operator== (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) == 0 ? true : false;
}

int32_t BigUInt::CmpBigUInt(const BigUInt& lhs, const BigUInt& rhs)
{
	if (lhs.Size() == rhs.Size())
	{
		int32_t size = lhs.Size();
		for (int32_t i = size - 1; i >= 0; i--)
		{
			if (lhs[i] == rhs[i]) continue;
			return lhs[i] > rhs[i] ? 1 : -1;
		}
		return 0;
	}
	else
	{
		return lhs.Size() > rhs.Size() ? 1 : -1;
	}
}

int32_t BigUInt::operator[] (int32_t index) const noexcept
{
	return (index >= Size() ? 0 : uInt_[index]);
}




BN_NAMESPACE_END