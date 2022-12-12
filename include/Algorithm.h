#pragma once
#ifndef BN_INCLUDE_ALGORITHM_H
#define BN_INCLUDE_ALGORITHM_H

#include "Header.h"

BN_NAMESPACE_BEGIN


template<typename _RetType>
std::vector<_RetType> uint64ToRevVector(uint64_t number, const int32_t& base)
{
	std::vector<_RetType>res = {};
	if (number == 0ULL) res.push_back(_RetType(0));
	else
	{
		while (number)
		{
			res.push_back(_RetType(number % base));
			number /= base;
		}
	}
	return res;
}

template<int32_t _Base>
inline int32_t GetCarryBit(const int32_t& lhs, const int32_t& rhs)
{
	return lhs + rhs >= _Base ? 1 : 0;
}
template<int32_t _Base>
inline int32_t GetNowAddBit(const int32_t& lhs, const int32_t& rhs)
{
	int32_t sum = lhs + rhs;
	return sum >= _Base ? sum - _Base : sum;
}

inline std::string stringToEquilong(const std::string& str, const size_t& len)
{
	int32_t blankCount = len - static_cast<int>(str.size());
	std::string res = str;
	res += std::string(blankCount, ' ');
	return res;
}

inline int32_t charToDigit(const char& ch)
{
	return ch - '0';
}

inline bool DoubleIsZero(const double& lhs, const double& eps = 1e-6)
{
	return fabs(lhs) < eps;
}


BN_NAMESPACE_END
#endif// !BN_INCLUDE_ALGORITHM_H