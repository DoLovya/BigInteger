#pragma once
#ifndef BN_HEADER_H
#define BN_HEADER_H

#include <vector>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>
#include <cinttypes>
#include <algorithm>

#define BN_NAMESPACE_BEGIN namespace BN {
#define BN_NAMESPACE_END }

#ifndef _DEBUG
#define XASSERT(exp_, msgw_) ((void)0)
#else
#define XASSERT(exp_, msgw_) _ASSERT_EXPR((exp_), (std::wstring(L#exp_)+L"\r\nMessage: "+(msgw_)).c_str())
#endif

// System Header
#endif // !BN_HEADER_H
