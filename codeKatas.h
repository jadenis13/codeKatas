#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
	if (!v.empty()) {
		out << '['; std::ranges::copy(v, std::ostream_iterator<T>(out, ", ")); out << "\b\b]"; // overwrite trailing comma separator
	}
	return out;
}
