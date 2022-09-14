//#pragma once
//
//#ifndef INCLUDE_BC_BIG_UINTEGER_H
//#define INCLUDE_BC_BIG_UINTEGER_H
//
//// My Header
//#include "BcHeader.h"
//#include "BcAlgorithms.h"
//
//BC_NAMESPACE_BEGIN
//class BigUInteger
//{
//public:
//	using Number = QVector<int8_t>;
//
//public:
//	BigUInteger() noexcept;
//	BigUInteger(uint64_t number) noexcept;
//	BigUInteger(QString number) noexcept;
//	BigUInteger(const char* number) noexcept;
//	BigUInteger(const BigUInteger& mNumber) noexcept;
//
//	~BigUInteger() noexcept;
//
//	size_t        digitalNum() const noexcept;
//	Number        getNumber() const noexcept;
//	const Sign&   GetSign() const noexcept;
//	const number& getNumber() const noexcept;
//
//	BigUInteger& operator= (const QString& qsNumber) noexcept;
//	friend QDebug operator<< (QDebug debug, const BigUInteger &mInt) noexcept;
//
//private:
//	void defauleConstruct() noexcept;
//	void construct(uint64_t number) noexcept;
//	void construct(const QString& number) noexcept;
//	void copyConstruct(const BigUInteger& number) noexcept;
//
//
//private:
//	// ÊýÖµ
//	Number number_;
//};
//
//
//BC_NAMESPACE_END
//#endif // !INCLUDE_BC_BIG_UINTEGER_H