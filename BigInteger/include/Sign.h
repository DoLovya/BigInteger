#pragma once
#ifndef INCLUDE_BC_SIGN_H
#define INCLUDE_BC_SIGN_H

#include "Header.h"
#include "Enum.h"

BN_NAMESPACE_BEGIN


class Sign
{
public:
	Sign() noexcept;

	Sign(const eSign& sign) noexcept;
	Sign(const Sign& sign) noexcept;

	virtual ~Sign() noexcept;

	Sign& operator= (const Sign& val) noexcept;

	const eSign& data() const noexcept;
	char toChar() const noexcept;

private:
	void defauleConstruct();
	void construct(const eSign& sign);
	void copyConstruct(const Sign& sign);
	void destruct();

private:
	eSign sign_;
};


BN_NAMESPACE_END
#endif // !INCLUDE_BC_SIGN_H