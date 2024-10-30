#include "direction.hpp"

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    switch (direction)
    {
    case Direction::Top:
        out << "Top";
        break;
    case Direction::Left:
        out << "Left";
        break;
    case Direction::Right:
        out << "Right";
        break;
    case Direction::Bottom:
        out << "Bottom";
        break;
    default:
        break;
    }
    return out;
}