#pragma once

#include <iostream>

enum class Direction {
   Top, Left, Right, Bottom
};

std::ostream& operator<<(std::ostream& out, const Direction& direction);