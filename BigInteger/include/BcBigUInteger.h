#pragma once
#ifndef INCLUDE_BC_BIG_UINTEGER_H
#define INCLUDE_BC_BIG_UINTEGER_H

// My Header
#include "BcHeader.h"
#include "BcAlgorithm.h"

BC_NAMESPACE_BEGIN
class BigUInteger
{
public:
	using Vector = std::vector<int8_t>;
	using String = std::string;
	using Input  = std::istream;

public:
	BigUInteger() noexcept;

	BigUInteger(const uint64_t& number) noexcept;
	BigUInteger(const String& number) noexcept;
	BigUInteger(const BigUInteger& number) noexcept;

	BigUInteger& operator= (const uint64_t& number) noexcept;
	BigUInteger& operator= (const String& number) noexcept;
	BigUInteger& operator= (const BigUInteger& number) noexcept;

	~BigUInteger() noexcept;



	size_t        digitNumber() const noexcept;
	const Vector& data() const noexcept;

	//
	//friend QDebug operator<< (QDebug debug, const BigUInteger &mInt) noexcept;

private:
	void defauleConstruct() noexcept;
	void construct(const uint64_t& number) noexcept;
	void construct(const String& number) noexcept;
	void copyConstruct(const BigUInteger& number) noexcept;


private:
	// ÊýÖµ
	Vector number_;
};


BC_NAMESPACE_END
#endif // !INCLUDE_BC_BIG_UINTEGER_H