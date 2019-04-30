#pragma once

#include "cg.h"
#include "Matrix.h"
#include <limits>

bool equals(const double& n1, const double& n2) {
	return abs(n1 - n2) < 16 * std::numeric_limits<double>::epsilon();
}