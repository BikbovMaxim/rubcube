#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "types.hpp"

class Cell
{
public:
    Cell ();
    Cell (Color c);
    Cell (const Cell &c);

    Color getColor () const;
    void setColor (Color c);
    std::string printCell ();

private:
    Color _color;
};

bool operator== (const Cell &c1, const Cell &c2) ;

#endif /* __CELL_HPP__ */
