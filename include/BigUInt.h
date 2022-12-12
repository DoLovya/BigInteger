#pragma once
#ifndef INCLUDE_BC_BIG_UINTEGER_H
#define INCLUDE_BC_BIG_UINTEGER_H

// My Header
#include "Header.h"

#include "Enum.h"
#include "Sign.h"
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

	/* 运算符重载 */
	BigUInt& operator= (const uint64_t& number) noexcept;
	BigUInt& operator= (const std::string& number) noexcept;
	BigUInt& operator= (const BigUInt& number) noexcept;

	friend std::istream& operator>>(std::istream& in, BigUInt& bigUInt);
	friend std::ostream& operator<< (std::ostream& out, const BigUInt& bigUInt);

	friend BigUInt operator+ (const BigUInt& lhs, const BigUInt& rhs);
	friend BigUInt operator- (const BigUInt& lhs, const BigUInt& rhs);

	friend bool operator< (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator<= (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator> (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator>= (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator!= (const BigUInt& lhs, const BigUInt& rhs);
	friend bool operator== (const BigUInt& lhs, const BigUInt& rhs);

	size_t Size() const noexcept;
	const Number& Data() const noexcept;


private:
	void DefauleConstruct() noexcept;
	void Construct(const uint64_t& number) noexcept;
	void Construct(const std::string& str) noexcept;
	void CopyConstruct(const BigUInt& number) noexcept;

	bool IsZero() const noexcept;
	void RemoveLeadZero() noexcept;

	void Add(const BigUInt& rhs) noexcept;
	void Sub(const BigUInt& rhs) noexcept;  // 必须保证 this > rhs

	// 重载[]
	int32_t operator[] (int32_t index) const noexcept;

	std::vector<int32_t>::const_reverse_iterator rbegin() const;
	std::vector<int32_t>::const_reverse_iterator rend() const;


	static int32_t CmpBigUInt(const BigUInt& lhs, const BigUInt& rhs) noexcept;

private:
	Number num_;  // 整数
};




BN_NAMESPACE_END
#endif // !INCLUDE_BC_BIG_UINTEGER_H