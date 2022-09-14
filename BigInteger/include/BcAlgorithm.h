#pragma once

#ifndef INCLUDE_BC_ALGORITHM_H
#define INCLUDE_BC_ALGORITHM_H

#include "BcHeader.h"
BC_NAMESPACE_BEGIN


template<typename RetType>
RetType uint64ToRevVector(uint64_t number, const int32_t& base)
{
	RetType res = {};
	if (number == 0ULL) res.push_back(0);
	else
	{
		while (number)
		{
			res.push_back(number % base);
			number /= base;
		}
	}
	return res;
}

std::string stringToEquilong(const std::string& str, const size_t& len);



BC_NAMESPACE_END
#endif// !INCLUDE_BC_ALGORITHM_H

