#pragma once
#ifndef INCLUDE_BC_DIGIT_H
#define INCLUDE_BC_DIGIT_H

#include "BcHeader.h"
#include "BcAlgorithm.h"
#include "BcAbstractDigit.h"


BC_NAMESPACE_BEGIN
template<int8_t _base = 10>
class Digit
{
public:
	Digit() noexcept;

	Digit(const int8_t& digit) noexcept;

	Digit(const Digit& digit) noexcept;

	Digit& operator= (const int8_t& digit) noexcept;
	Digit& operator= (const Digit& digit) noexcept;

	char toChar() const noexcept;
	std::string debug() const noexcept;

private:
	void defaultConstruct() noexcept;
	void construct(const int8_t& digit) noexcept;
	void copyConstruct(const Digit& digit) noexcept;
	void assigningOperator(const Digit& digit) noexcept;

private:
	int8_t digit_;
};


template<int8_t _base>
inline Digit<_base>::Digit() noexcept
{
	defaultConstruct();
}

template<int8_t _base>
inline Digit<_base>::Digit(const int8_t& digit) noexcept
{
	construct(digit);
}

template<int8_t _base>
inline Digit<_base>::Digit(const Digit & digit) noexcept
{
}

template<int8_t _base>
inline Digit<_base> & Digit<_base>::operator=(const int8_t & digit) noexcept
{
	assigningOperator(Digit(digit));
	return *this;
}

template<int8_t _base>
inline Digit<_base>& Digit<_base>::operator=(const Digit& digit) noexcept
{
	assigningOperator(digit);
	return *this;
}

template<int8_t _base>
inline char Digit<_base>::toChar() const noexcept
{
	return static_cast<char>(this->digit_ + static_cast<int>(eAscii::zero));
}

template<int8_t _base>
inline std::string Digit<_base>::debug() const noexcept
{
	std::stringstream stream;
	stream << toChar();
	std::string debugMsg = stream.str();
	return debugMsg;
}

template<int8_t _base>
inline void Digit<_base>::defaultConstruct() noexcept
{
	construct(static_cast<int8_t>(0));
}


template<int8_t _base>
inline void Digit<_base>::construct(const int8_t& digit) noexcept
{
	this->digit_ = digit;
}

template<int8_t _base>
inline void Digit<_base>::copyConstruct(const Digit & digit) noexcept
{
	construct(digit.digit_);
}

template<int8_t _base>
inline void Digit<_base>::assigningOperator(const Digit & digit) noexcept
{
	copyConstruct(digit);
}


BC_NAMESPACE_END

#endif // !INCLUDE_BC_DIGIT_H