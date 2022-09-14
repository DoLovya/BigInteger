#include "BcSign.h"

/****************************************************
 * module -> ���캯��
****************************************************/
using namespace bc;
Sign::Sign() noexcept
{
	defauleConstruct();
}
Sign::Sign(const eSign& sign) noexcept
{
	construct(sign);
}
Sign::Sign(const Sign& sign) noexcept
{
	copyConstruct(sign);
}
/****************************************************
 * module -> ��������
****************************************************/
Sign::~Sign() noexcept
{
	destruct();
}
/****************************************************
 * module -> �ӿں���
****************************************************/
const eSign& Sign::data() const noexcept
{
	return sign_;
}
char Sign::toChar() const noexcept
{
	switch (sign_)
	{
	case eSign::negative:
		return '-';
		break;
	case eSign::zero:
		return '\0';
		break;
	case eSign::positive:
		return '+';
		break;
	default:
		Q_ASSERT_X(false, "const char&  Sign::toChar() const noexcept", "Impossible Event");
		break;
	}
}
/****************************************************
 * module -> ˽�к���
****************************************************/
void  Sign::defauleConstruct()
{
	sign_ = eSign::zero;
}
void Sign::construct(const eSign& sign)
{
	sign_ = sign;
}
void Sign::copyConstruct(const Sign& sign)
{
	*this = Sign(sign);
}
void Sign::destruct()
{

}
