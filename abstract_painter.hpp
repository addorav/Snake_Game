#pragma once

#include <vector>
#include <string>
#include "point.hpp"

struct AbstractPainter {
   virtual void DrawImage(
      Point topLeft,
      Point bottomRight,
      const std::vector<std::string>& image) const = 0;
   virtual void WriteText(Point position, const std::string& text) const = 0;
};