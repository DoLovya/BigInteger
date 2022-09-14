//#include "BcEnum.h"
//#include "BcBigInteger.h"
//using namespace bc;
//
///****************************************************
// * module -> 构造函数
//*****************************************************/
//BigInteger::BigInteger() noexcept
//{
//	_initInt(0);
//}
//BigInteger::BigInteger(int64_t qNumber) noexcept
//{
//	_initInt(qNumber);
//}
//BigInteger::BigInteger(QString qsNumber) noexcept
//{
//	_initStr(qsNumber);
//}
//BigInteger::BigInteger(const char* sNumber) noexcept
//{
//	_initStr(sNumber);
//}
//BigInteger::BigInteger(const BigInteger& mNumber) noexcept
//{
//	_initMyself(mNumber);
//}
///****************************************************
// * module -> 析构函数
//*****************************************************/
//BigInteger::~BigInteger() noexcept
//{
//	m_qvNum.clear();
//}
///****************************************************
// * module -> 接口函数
//****************************************************/
//size_t BigInteger::digitalNum() const noexcept
//{
//	return m_qvNum.size();
//}
//auto BigInteger::getData() const noexcept -> data
//{
//	return data(m_Sign, m_qvNum);
//}
//auto BigInteger::getSign() const noexcept -> const sign&
//{
//	return m_Sign;
//}
//auto BigInteger::getNumber() const noexcept -> const number&
//{
//	return m_qvNum;
//}
///****************************************************
// * module -> 运算符重载
//****************************************************/
//BigInteger& BigInteger::operator= (const QString & qsNumber) noexcept
//{
//	_initStr(qsNumber);
//	return *this;
//}
//QDebug operator<<(QDebug qdDebug, const BigInteger& mInt) noexcept
//{
//	QString qsOutput;
//	if (mInt.m_Sign != Sign::zero)
//		qsOutput += mInt.m_Sign;
//	for (auto iPos = mInt.m_qvNum.rbegin(); iPos != mInt.m_qvNum.rend(); iPos++)
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
//void BigInteger::_initInt(int64_t qNumber) noexcept
//{
//	if (qNumber == 0LL) m_Sign = Sign::zero;
//	if (qNumber > 0LL)  m_Sign = Sign::positive;
//	if (qNumber < 0LL)  m_Sign = Sign::negative;
//
//	switch (m_Sign)
//	{
//	case zero: // 0由于分解的时候为空，所以需要特殊处理
//		m_qvNum.push_back((int8_t)0);
//		break;
//	case negative:
//	case positive:
//		qNumber = std::abs(qNumber);
//		while (qNumber)
//		{
//			m_qvNum.push_back(qNumber % 10);
//			qNumber /= 10;
//		}
//		break;
//	default: break;
//	}
//}
//void BigInteger::_initStr(const QString& qsNumber) noexcept
//{
//	Q_ASSERT_X(qsNumber.length(), "BigInteger::_init", "Not a number");
//	auto iPos = qsNumber.rbegin();
//	for (; iPos != qsNumber.rend(); iPos++)
//	{
//		const QChar& qcNum = *iPos;
//		if (!qcNum.isNumber()) break;
//		const int8_t& bNum = qcNum.unicode() - '0';
//		m_qvNum.push_back(bNum);
//	}
//	if (iPos == qsNumber.rend())
//	{
//		m_Sign = Sign::positive;
//	}
//	else if (iPos == qsNumber.rend() - 1)
//	{
//		if (qsNumber.length() == 1)
//			Q_ASSERT_X(false, "BigInteger::_init", "Not a number");
//		else if (*iPos == '+')
//			m_Sign = Sign::positive;
//		else if (*iPos == '-')
//			m_Sign = Sign::negative;
//		else
//			Q_ASSERT_X(false, "BigInteger::_init", "Not a number");
//	}
//	else Q_ASSERT_X(false, "BigInteger::_init", "Not a number");
//}
//void BigInteger::_initMyself(const BigInteger & mNumber) noexcept
//{
//	m_Sign = mNumber.m_Sign;
//	m_qvNum = mNumber.m_qvNum;
//}