#include "painter.hpp"

void Painter::SetCursorPosition(int x, int y) const {
    std::cout << "\033[" << y << ";" << x << "H";
}

void Painter::DrawImage(
    Point topLeft,
    Point bottomRight,
    const std::vector<std::string> &image) const
{
    for(int i = 0; i < image.size(); ++i) {
        SetCursorPosition(topLeft.x, topLeft.y + i);
        std::cout << image[i];
    }
}

void Painter::WriteText(Point position, const std::string &text) const {
    SetCursorPosition(position.x, position.y);
    std::cout << text;
}