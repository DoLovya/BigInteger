#include "BcAlgorithm.h"
using namespace bc;

std::string bc::stringToEquilong(const std::string& str, const size_t& len)
{
	assert(str.size() <= len);

	int32_t blankCount = len - static_cast<int>(str.size());
	std::string res = str;
	res += std::string(blankCount, ' ');
	return res;
}
