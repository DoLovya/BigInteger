#pragma once

#ifndef INCLUDE_BC_BIG_INTEGER_H
#define INCLUDE_BC_BIG_INTEGER_H

// My Header
#include "BcSign.h"
#include "BcHeader.h"
#include "BcAlgorithms.h"

BC_NAMESPACE_BEGIN
class BigInteger
{
public:
	using number = QVector<int8_t>;
	struct data
	{
		eSign sign;
		QVector<int8_t> number;
	};

public:
	BigInteger() noexcept;
	BigInteger(int64_t qNumber) noexcept;
	BigInteger(QString qsNumber) noexcept;
	BigInteger(const char* sNumber) noexcept;
	BigInteger(const BigInteger& mNumber) noexcept;

	~BigInteger() noexcept;

	size_t        digitalNum() const noexcept;
	data          getData() const noexcept;
	const Sign&   getSign() const noexcept;
	const number& getNumber() const noexcept;

	BigInteger& operator= (const QString& qsNumber) noexcept;
	friend QDebug operator<< (QDebug debug, const BigInteger &mInt) noexcept;

private:
	void _initInt(int64_t qNumber) noexcept;
	void _initStr(const QString& qsNumber) noexcept;
	void _initMyself(const BigInteger& mNumber) noexcept;


private:
	//// ·ûºÅ
	//Sign
	//	// ÊýÖµ
	//	number m_qvNum;
};


BC_NAMESPACE_END
#endif // !INCLUDE_BC_BIG_INTEGER_H
