#pragma once
#ifndef INCLUDE_BC_TEST_H
#define INCLUDE_BC_TEST_H

// My Header
#include "BcHeader.h"
#include "BcAlgorithm.h"
#include "BcSign.h"
#include "BcDigit.h"

BC_NAMESPACE_BEGIN
using namespace bc;
class BigTest
{
public:
	static void testSign();
	static void testDigit();
};



BC_NAMESPACE_END
#endif // !INCLUDE_BC_TEST_H