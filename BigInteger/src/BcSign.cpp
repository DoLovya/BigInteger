#include "BcSign.h"

/****************************************************
 * module -> 构造函数
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
 * module -> 析构函数
****************************************************/
Sign::~Sign() noexcept
{
	destruct();
}
/****************************************************
 * module -> 接口函数
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
		assert(false);
		break;
	}
}
Sign& Sign::operator= (const Sign& val) noexcept
{
	//sign_ = Sign(val.sign_);
	return *this;
}
/****************************************************
 * module -> 私有函数
****************************************************/
inline void  Sign::defauleConstruct()
{
	sign_ = eSign::zero;
}
inline void Sign::construct(const eSign& sign)
{
	sign_ = sign;
}
inline void Sign::copyConstruct(const Sign& sign)
{
	sign_ = sign.sign_;
}
inline void Sign::destruct()
{
}
