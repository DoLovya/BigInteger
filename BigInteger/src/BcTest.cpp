#include "BcTest.h"
using namespace bc;

void BigTest::testSign()
{
	const auto& msgMaxLen = 12;
	const auto& typeMsg   = stringToEquilong("TestSign", msgMaxLen);
	const auto& inputMsg  = stringToEquilong("Input value", msgMaxLen);
	const auto& outputMsg = stringToEquilong("Output value", msgMaxLen);

	auto debugDefaultConstruct = [&]()
	{
		Sign sign;
		printf("%s -> Default construct\n", typeMsg.c_str());
		printf("%s -> %s\n", inputMsg.c_str(), "NULL");
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	auto debugConstruct = [&](const eSign& val)
	{
		Sign sign(val);
		printf("%s -> construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};
	auto copyConstruct = [&](const eSign& val)
	{
		Sign sign = val;
		printf("%s -> Copy construct\n", typeMsg.c_str());
		printf("%s -> %d\n", inputMsg.c_str(), static_cast<int>(val));
		printf("%s -> %c\n\n", outputMsg.c_str(), (sign.toChar() == '\0') ? '0' : sign.toChar());
	};

	debugDefaultConstruct();
	debugConstruct(eSign::negative);
	debugConstruct(eSign::zero);
	debugConstruct(eSign::positive);
	copyConstruct(eSign::negative);
	copyConstruct(eSign::zero);
	copyConstruct(eSign::positive);

}