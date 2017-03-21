#include "side.hpp"

Side::Side (std::vector< std::vector< Cell > > &cells, size_t size)
{
    _size = size;
    for (size_t i = 0; i < cells.size (); ++i)
    {
        _side.push_back (std::vector< Cell > (cells.size ()));
    }

    for (size_t i = 0; i < cells.size (); ++i)
    {
        for (size_t j = 0; j < cells.size (); ++j)
        {
            _side[i][j] = cells[i][j];
        }
    }
}

Side::Side () {}

Side::Side(Color c, size_t size)
{
    _size = size;
    for (size_t i = 0; i < size; ++i)
    {
        _side.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            _side[i][j] = c;
        }
    }
}

Side::Side (const Side &side)
{
    for (size_t i = 0; i < side._size; ++i)
    {
        _side.push_back (std::vector< Cell > (side._size));
    }

    for (size_t i = 0; i < side._size; ++i)
    {
        for (size_t j = 0; j < side._size; ++j)
        {
            _side[i][j] = side._side[i][j];
        }
    }
}

size_t Side::getSize () const { return _size; }

void Side::setCell (Cell c, size_t i, size_t j) { _side[i][j] = c; }

Cell Side::getCell (size_t i, size_t j) const { return _side[i][j]; }

std::string Side::printSide()
{
    std::string output;
    for (size_t i = 0; i < _size; ++i)
    {
        for(size_t j = 0; j < _size; ++j)
        {
            output += _side[i][j].printCell() + " ";
        }
        output  += "\n";
    }
    return output;
}
