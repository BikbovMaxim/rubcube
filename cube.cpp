#include "cube.hpp"

Cube::Cube ()
{
    size_t size = 3;
    std::vector< std::vector< Cell > > blue;
    for (size_t i = 0; i < size; ++i)
    {
        blue.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            blue[i][j] = Color::Blue;
        }
    }
    _front = Side (blue, size);

    std::vector< std::vector< Cell > > green;
    for (size_t i = 0; i < size; ++i)
    {
        green.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            green[i][j] = Color::Green;
        }
    }
    _left = Side (green, size);

    std::vector< std::vector< Cell > > orange;
    for (size_t i = 0; i < size; ++i)
    {
        orange.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            orange[i][j] = Color::Orange;
        }
    }
    _right = Side (orange, size);

    std::vector< std::vector< Cell > > red;
    for (size_t i = 0; i < size; ++i)
    {
        red.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            red[i][j] = Color::Red;
        }
    }
    _up = Side (red, size);

    std::vector< std::vector< Cell > > white;
    for (size_t i = 0; i < size; ++i)
    {
        white.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            white[i][j] = Color::White;
        }
    }
    _down = Side (white, size);

    std::vector< std::vector< Cell > > yellow;
    for (size_t i = 0; i < size; ++i)
    {
        yellow.push_back (std::vector< Cell > (size));
    }
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            yellow[i][j] = Color::Yellow;
        }
    }
    _back = Side (yellow, size);
}

Cube::Cube (const Side &front,
            const Side &left,
            const Side &right,
            const Side &up,
            const Side &down,
            const Side &back)
{
    _front = front;
    _left  = left;
    _right = right;
    _up    = up;
    _down  = down;
    _back  = back;
}

Cube::Cube (const Cube &cube)
{
    _front = cube._front;
    _left  = cube._left;
    _right = cube._right;
    _up    = cube._up;
    _down  = cube._down;
    _back  = cube._back;
}

ReturnCode Cube::TurnLeftHor (size_t row)
{
    if (_front.getSize () < row)
    {
        return ReturnCode::InvalidArg;
    }
    Side tmp_r = _right;
    Side tmp_u = _up;
    Side tmp_d = _down;
    for (size_t i = 0; i < _front.getSize (); ++i)
    {
        if (row == 0)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _up.setCell (tmp_u.getCell (_up.getSize () - j - 1, i), i, j);
            }
        }
        if (row == _front.getSize () - 1)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _down.setCell (
                    tmp_d.getCell (i, _down.getSize () - j - 1), j, i);
            }
        }
        _right.setCell (_back.getCell (row, i), row, i);
        _back.setCell (_left.getCell (row, i), row, i);
        _left.setCell (_front.getCell (row, i), row, i);
        _front.setCell (tmp_r.getCell (row, i), row, i);
    }
    return ReturnCode::Ok;
}

ReturnCode Cube::TurnRightHor (size_t row)
{
    if (_front.getSize () < row)
    {
        return ReturnCode::InvalidArg;
    }
    Side tmp_l = _left;
    Side tmp_u = _up;
    Side tmp_d = _down;
    for (size_t i = 0; i < _front.getSize (); ++i)
    {
        if (row == 0)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _up.setCell (tmp_u.getCell (i, _up.getSize () - j - 1), j, i);
            }
        }
        if (row == _front.getSize () - 1)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _down.setCell (
                    tmp_d.getCell (_down.getSize () - j - 1, i), i, j);
            }
        }
        _left.setCell (_back.getCell (row, i), row, i);
        _back.setCell (_right.getCell (row, i), row, i);
        _right.setCell (_front.getCell (row, i), row, i);
        _front.setCell (tmp_l.getCell (row, i), row, i);
    }
    return ReturnCode::Ok;
}

ReturnCode Cube::TurnDownVer (size_t column)
{
    if (_front.getSize () < column)
    {
        return ReturnCode::InvalidArg;
    }
    Side tmp_u = _up;
    Side tmp_l = _left;
    Side tmp_r = _right;
    for (size_t i = 0; i < _front.getSize (); ++i)
    {
        if (column == 0)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _left.setCell (
                    tmp_l.getCell (_left.getSize () - j - 1, i), i, j);
            }
        }
        if (column == _front.getSize () - 1)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _right.setCell (
                    tmp_r.getCell (i, _right.getSize () - j - 1), j, i);
            }
        }
        _up.setCell (_back.getCell (i, column), i, column);
        _back.setCell (_down.getCell (i, column), i, column);
        _down.setCell (_front.getCell (i, column), i, column);
        _front.setCell (tmp_u.getCell (i, column), i, column);
    }
    return ReturnCode::Ok;
}

ReturnCode Cube::TurnUpVer (size_t column)
{
    if (_front.getSize () < column)
    {
        return ReturnCode::InvalidArg;
    }
    Side tmp_l = _left;
    Side tmp_r = _right;
    Side tmp_d = _down;
    for (size_t i = 0; i < _front.getSize (); ++i)
    {
        if (column == 0)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _left.setCell (tmp_l.getCell (i, _up.getSize () - j - 1), j, i);
            }
        }
        if (column == _front.getSize () - 1)
        {
            for (size_t j = 0; j < _front.getSize (); ++j)
            {
                _right.setCell (
                    tmp_r.getCell (_right.getSize () - j - 1, i), i, j);
            }
        }
        _down.setCell (_back.getCell (i, column), i, column);
        _back.setCell (_up.getCell (i, column), i, column);
        _up.setCell (_front.getCell (i, column), i, column);
        _front.setCell (tmp_d.getCell (i, column), i, column);
    }
    return ReturnCode::Ok;
}

std::string Cube::printCube ()
{
    std::string output;
    output += "Front:\n";
    output += _front.printSide ();
    output += "Left:\n";
    output += _left.printSide ();
    output += "Right:\n";
    output += _right.printSide ();
    output += "Up:\n";
    output += _up.printSide ();
    output += "Down:\n";
    output += _down.printSide ();
    output += "Back:\n";
    output += _back.printSide ();
    return output;
}

Side Cube::getFrontSide () const { return this->_front; }

Side Cube::getLeftSide () const { return this->_left; }

Side Cube::getRightSide () const { return this->_right; }

Side Cube::getUpSide () const { return this->_up; }

Side Cube::getDownSide () const { return this->_down; }

Side Cube::getBackSide () const { return this->_back; }

bool operator== (const Cube &cub1, const Cube &cub2)
{
    if (cub1.getFrontSide () == cub2.getFrontSide () &&
        cub1.getLeftSide () == cub2.getLeftSide () &&
        cub1.getRightSide () == cub2.getRightSide () &&
        cub1.getUpSide () == cub2.getUpSide () &&
        cub1.getDownSide () == cub2.getDownSide () &&
        cub1.getBackSide () == cub2.getBackSide ())
    {
        return true;
    }
    else
    {
        return false;
    }
}
