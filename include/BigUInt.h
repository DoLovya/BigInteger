#pragma once
#ifndef INCLUDE_BC_BIG_UINTEGER_H
#define INCLUDE_BC_BIG_UINTEGER_H

// My Header
#include "Header.h"
#include "Enum.h"
#include "Algorithm.h"

BN_NAMESPACE_BEGIN



class BigUInt
{
public:
	using Number = std::vector<int32_t>;

public:
	BigUInt() noexcept;
	~BigUInt() noexcept;


	BigUInt(const uint64_t& number) noexcept;
	BigUInt(const std::string& number) noexcept;
	BigUInt(const BigUInt& number) noexcept;

	BigUInt& operator= (const uint64_t& number) noexcept;
	BigUInt& operator= (const std::string& number) noexcept;
	BigUInt& operator= (const BigUInt& number) noexcept;

	// 重载>>
	friend std::istream& operator>>(std::istream& in, BigUInt& bigUInt);
	// 重载<<
	friend std::ostream& operator<< (std::ostream& out, const BigUInt& bigUInt);
	// 重载+
	friend BigUInt operator+ (const BigUInt& lhs, const BigUInt& rhs);

	// 重载<
	friend bool operator< (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator<= (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator> (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator>= (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator== (const BigUInt& lhs, const BigUInt& rhs);


	size_t Size() const noexcept;
	const Number& Data() const noexcept;


private:
	void DefauleConstruct() noexcept;
	void Construct(const uint64_t& number) noexcept;
	void Construct(const std::string& str) noexcept;
	void CopyConstruct(const BigUInt& number) noexcept;
	bool IsZero() const noexcept;

	void Add(const BigUInt& rhs);
	void Sub(const BigUInt& rhs);

	// 重载[]
	int32_t operator[] (int32_t index) const noexcept;
	static int32_t CmpBigUInt(const BigUInt& lhs, const BigUInt& rhs);

private:
	Number uInt_;  // 无符号整数
};




BN_NAMESPACE_END
#endif // !INCLUDE_BC_BIG_UINTEGER_H