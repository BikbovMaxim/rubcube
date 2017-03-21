#include <string>
#include "cell.hpp"

Cell::Cell () {}

Cell::Cell (Color c) { _color = c; }

Cell::Cell (const Cell &c) { _color = c._color; }

Color Cell::getColor () const { return _color; }

void Cell::setColor (Color c) { _color = c; }

std::string Cell::printCell ()
{
    switch (_color)
    {
    case Color::Blue:
        return std::string ("B");
    case Color::Green:
        return std::string ("G");
    case Color::Orange:
        return std::string ("O");
    case Color::Red:
        return std::string ("R");
    case Color::White:
        return std::string ("W");
    case Color::Yellow:
        return std::string ("Y");
    }
}
