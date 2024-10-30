#pragma once

#include "abstract_painter.hpp"

class Painter: public AbstractPainter {
   void SetCursorPosition(int x, int y) const;
public:
   virtual void DrawImage(
      Point topLeft,
      Point bottomRight,
      const std::vector<std::string>& image) const override;
   virtual void WriteText(Point position, const std::string& text) const override;
};