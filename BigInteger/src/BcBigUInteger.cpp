//#include "BcBigUInteger.h"
//using namespace bc;
//
///****************************************************
// * module -> 构造函数
//*****************************************************/
//BigUInteger::BigUInteger() noexcept
//{
//	defauleConstruct();
//}
//BigUInteger::BigUInteger(uint64_t number) noexcept
//{
//	construct(number);
//}
//BigUInteger::BigUInteger(QString number) noexcept
//{
//	construct(number);
//}
//BigUInteger::BigUInteger(const char* number) noexcept
//{
//	construct(number);
//}
//BigUInteger::BigUInteger(const BigUInteger& mNumber) noexcept
//{
//	_initMyself(mNumber);
//}
///****************************************************
// * module -> 析构函数
//*****************************************************/
//BigUInteger::~BigUInteger() noexcept
//{
//	number_.clear();
//}
///****************************************************
// * module -> 接口函数
//****************************************************/
//size_t BigUInteger::digitalNum() const noexcept
//{
//	return number_.size();
//}
//auto BigUInteger::getData() const noexcept -> data
//{
//	return data(sign_, m_qvNum);
//}
//auto BigUInteger::getSign() const noexcept -> const sign&
//{
//	return sign_;
//}
//auto BigUInteger::getNumber() const noexcept -> const number_&
//{
//	return number_;
//}
///****************************************************
// * module -> 运算符重载
//****************************************************/
//BigUInteger& BigUInteger::operator= (const QString & qsNumber) noexcept
//{
//	_initStr(qsNumber);
//	return *this;
//}
//QDebug operator<<(QDebug qdDebug, const BigUInteger& mInt) noexcept
//{
//	QString qsOutput;
//	if (mInt.sign_ != Sign::zero)
//		qsOutput += mInt.sign_;
//	for (auto iPos = mInt.number_.rbegin(); iPos != mInt.number_.rend(); iPos++)
//	{
//		const int8_t& bNum = *iPos;
//		qsOutput += QString::number(bNum);
//	}
//
//	qdDebug << qsOutput.toUtf8().data();
//	return qdDebug;
//}
//
//
///****************************************************
// * module -> 私有函数
//****************************************************/
//void BigUInteger::defauleConstruct() noexcept
//{
//	construct(0ULL);
//}
//void BigUInteger::construct(uint64_t number) noexcept
//{
//	assert(number >= 0, __FUNCDNAME__, "Unsigned number must greater than or equal to zero");
//	number_ = uint64ToRevVector<Number>(number, 10);
//}
//void BigUInteger::construct(const QString& number) noexcept
//{
//	//Q_ASSERT_X(qsNumber.length(), "BigUInteger::_init", "Not a number");
//	auto iPos = qsNumber.rbegin();
//	for (; iPos != qsNumber.rend(); iPos++)
//	{
//		const QChar& qcNum = *iPos;
//		if (!qcNum.isNumber()) break;
//		const int8_t& bNum = qcNum.unicode() - '0';
//		number_.push_back(bNum);
//	}
//	if (iPos == qsNumber.rend())
//	{
//		sign_ = Sign::positive;
//	}
//	else if (iPos == qsNumber.rend() - 1)
//	{
//		if (qsNumber.length() == 1)
//			Q_ASSERT_X(false, "BigUInteger::_init", "Not a number");
//		else if (*iPos == '+')
//			sign_ = Sign::positive;
//		else if (*iPos == '-')
//			sign_ = Sign::negative;
//		else
//			Q_ASSERT_X(false, "BigUInteger::_init", "Not a number");
//	}
//	else Q_ASSERT_X(false, "BigUInteger::_init", "Not a number");
//}
//void BigUInteger::construct(const BigUInteger & mNumber) noexcept
//{
//	sign_ = mNumber.sign_;
//	number_ = mNumber.number_;
//}