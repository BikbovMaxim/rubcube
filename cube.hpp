#ifndef __CUBE_HPP__
#define __CUBE_HPP__

#include "types.hpp"
#include "side.hpp"

class Cube
{
public:
    Cube ();
    Cube (const Side &front,
          const Side &left,
          const Side &right,
          const Side &up,
          const Side &down,
          const Side &back);
    Cube (const Cube &cube);
    ReturnCode TurnLeftHor (size_t row);
    ReturnCode TurnRightHor (size_t row);
    ReturnCode TurnDownVer (size_t column);
    ReturnCode TurnUpVer (size_t column);
    std::string printCube ();

    Side getFrontSide () const;
    Side getLeftSide () const;
    Side getRightSide () const;
    Side getUpSide () const;
    Side getDownSide () const;
    Side getBackSide () const;

private:
    Side _front;
    Side _left;
    Side _right;
    Side _up;
    Side _down;
    Side _back;
};

bool operator == (const Cube &cub1, const Cube &cub2);

#endif /* __CUBE_HPP__ */
