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
	this->num_ = number.num_;
	return *this;
}

BigUInt::~BigUInt() noexcept
{

}

size_t BigUInt::Size() const noexcept
{
	return num_.size();
}

auto BigUInt::Data() const noexcept -> const Number&
{
	return num_;
}


void BigUInt::DefauleConstruct() noexcept
{
	Construct(0ULL);
}
void BigUInt::Construct(const uint64_t& number) noexcept
{
	num_ = uint64ToRevVector<int32_t>(number, 10);
}
void BigUInt::Construct(const std::string& str) noexcept
{
	if (str.empty()) return;
	if (!num_.empty()) num_.clear();
	//XASSERT(str.length() != 0, L"Number length is zero");

	auto bIter = str.begin();
	while (bIter != str.end() - 1 && *bIter == '0')
	{
		//XASSERT(isdigit(*bIter), L"Number has the illegal character");
		bIter++;
	}

	for (auto iter = str.end() - 1; ; iter--)
	{
		//XASSERT(isdigit(*iter), L"Number has the illegal character");
		num_.push_back(charToDigit(*iter));
		if (iter == bIter) break;
	}
}
void BigUInt::CopyConstruct(const BigUInt& number) noexcept
{
	num_ = number.num_;
}
bool BigUInt::IsZero() const noexcept
{
	return (Size() == 1 && num_.back() == 0);
}
void BigUInt::RemoveLeadZero() noexcept
{
	while (num_.size() > 1 && num_.back() == 0)
	{
		num_.pop_back();
	}
}



void BigUInt::Add(const BigUInt& rhs) noexcept
{
	if (IsZero())
	{
		num_ = rhs.num_;
	}
	else
	{
		num_.resize(std::max(Size(), rhs.Size()) + 1);
		int32_t carryBit = 0;
		for (size_t i = 0; i < num_.size() - 1; i++)
		{
			carryBit = GetCarryBit<10>(num_[i], rhs[i]);
			num_[i] += rhs[i];
			if (num_[i] >= 10)
			{
				num_[i] -= 10;
			}
			num_[i + 1] += carryBit;
		}
		if (!carryBit)
		{
			num_.pop_back();
		}
	}
}
void BigUInt::Sub(const BigUInt& rhs) noexcept
{
	for (size_t i = 0; i < Size(); i++)
	{
		int32_t sub = (*this)[i] - (i < rhs.Size() ? rhs[i] : 0);
		if (sub < 0)
		{
			num_[i + 1] -= 1;
			num_[i] = sub + 10;
		}
		else
		{
			num_[i] = sub;
		}
	}
}
void BigUInt::Mul(const BigUInt& rhs) noexcept
{
	Polynomial pLhs(num_);
	Polynomial pRhs(rhs.num_);
	Polynomial pMul = pLhs * pRhs;

	num_.resize(pMul.Size());
	for (size_t i = 0; i < pMul.Size(); i++)
	{
		num_[i] = static_cast<int32_t>(pMul[i].GetReal());
	}
	for (int64_t i = 0; i < static_cast<int64_t>(pMul.Size()) - 1; i++)
	{
		num_[i + 1] += (num_[i] / 10);
		num_[i] %= 10;
	}
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
	auto revIter = bigUInt.rbegin();
	while (revIter != bigUInt.rend())
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
BigUInt operator- (const BigUInt& lhs, const BigUInt& rhs)
{
	BigUInt sub(lhs);
	sub.Sub(rhs);
	sub.RemoveLeadZero();
	return sub;
}
BigUInt operator* (const BigUInt& lhs, const BigUInt& rhs)
{
	BigUInt mul(lhs);
	mul.Mul(rhs);
	mul.RemoveLeadZero();
	return mul;
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
bool operator!= (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) != 0 ? true : false;
}
bool operator== (const BigUInt& lhs, const BigUInt& rhs)
{
	return BigUInt::CmpBigUInt(lhs, rhs) == 0 ? true : false;
}

int32_t BigUInt::CmpBigUInt(const BigUInt& lhs, const BigUInt& rhs) noexcept
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
	return (index >= Size() ? 0 : num_[index]);
}

std::vector<int32_t>::const_reverse_iterator BigUInt::rbegin() const
{
	return num_.rbegin();
}
std::vector<int32_t>::const_reverse_iterator BigUInt::rend() const
{
	return num_.rend();
}


BN_NAMESPACE_END