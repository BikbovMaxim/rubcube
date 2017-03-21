#ifndef __SIDE_HPP__
#define __SIDE_HPP__

#include <iostream>
#include <vector>
#include "types.hpp"
#include "cell.hpp"

class Side
{
public:
    Side ();
    Side (Color c, size_t size);
    Side (std::vector< std::vector< Cell > > &cells, size_t size);
    Side (const Side &side);

    size_t getSize () const;
    void setCell (Cell c, size_t i, size_t j);
    Cell getCell (size_t i, size_t j) const;
    std::string printSide ();

private:
    size_t _size;
    std::vector< std::vector< Cell > > _side;
};

bool operator == (const Side &s1, const Side &s2);

#endif /* __SIDE_HPP__ */
