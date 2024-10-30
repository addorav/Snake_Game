#pragma once

#include <iostream>
#include "point.hpp"

class Apple {
   Point _position;
public:
   Apple();
   Apple(const Point& position);
   Apple(const Apple& other);
   Point GetPosition() const;

   Apple operator = (const Apple& other);
   bool operator == (const Apple& other) const;
};

std::istream& operator >> (std::istream& in, Apple& apple);
std::ostream& operator << (std::ostream& out, const Apple& apple);