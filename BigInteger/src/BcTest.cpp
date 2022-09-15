#include "BcTest.h"
using namespace bc;

void BigTest::testSign()
{
	const auto& msgMaxLen = 12;
	const auto& typeMsg   = stringToEquilong("TestSign", msgMaxLen);
	const auto& inputMsg  = stringToEquilong("Input  value", msgMaxLen);
	const auto& outputMsg = stringToEquilong("Output value", msgMaxLen);

	// 默认构造函数
	auto debugDefaultConstruct = [&]()
	{
		Sign sign;
		printf("%s -> Default construct\n", typeMsg.c_str());
		printf("%s -> %s\n", inputMsg.c_str(), "NULL");
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	// 构造函数
	auto debugConstruct = [&](const eSign& val)
	{
		Sign sign(val);
		printf("%s -> construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	// 拷贝构造函数
	auto debugCopyConstruct = [&](const eSign& val)
	{
		Sign sign = val;
		printf("%s -> Copy construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	// 赋值运算符
	auto debugAssigningOperator = [&](const eSign& val)
	{
		Sign sign;
		sign = val;
		printf("%s -> Assigning operator\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};

	debugDefaultConstruct();

	debugConstruct(eSign::negative);
	debugConstruct(eSign::zero);
	debugConstruct(eSign::positive);

	debugCopyConstruct(eSign::negative);
	debugCopyConstruct(eSign::zero);
	debugCopyConstruct(eSign::positive);

	debugAssigningOperator(eSign::negative);
	debugAssigningOperator(eSign::zero);
	debugAssigningOperator(eSign::positive);
}

void BigTest::testDigit()
{
	const auto& msgMaxLen = 12;
	const auto& typeMsg   = stringToEquilong("TestDigit", msgMaxLen);
	const auto& inputMsg  = stringToEquilong("Input  value", msgMaxLen);
	const auto& outputMsg = stringToEquilong("Output value", msgMaxLen);
	using Type = Digit<10>;

	// 默认构造函数
	auto debugDefaultConstruct = [&]()
	{
		Type value;
		printf("%s -> Default construct\n", typeMsg.c_str());
		printf("%s -> %s\n", inputMsg.c_str(), "NULL");
		printf("%s -> %s\n\n", outputMsg.c_str(), value.debug().c_str());
	};
	// 构造函数
	auto debugConstruct = [&](const eSign& val)
	{
		Sign sign(val);
		printf("%s -> construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	// 拷贝构造函数
	auto debugCopyConstruct = [&](const eSign& val)
	{
		Sign sign = val;
		printf("%s -> Copy construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	// 赋值运算符
	auto debugAssigningOperator = [&](const eSign& val)
	{
		Sign sign;
		sign = val;
		printf("%s -> Assigning operator\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};

	debugDefaultConstruct();


}
