#ifndef __TYPES_HPP__
#define __TYPES_HPP__

enum class Color
{
    Red,
    Blue,
    Yellow,
    Green,
    White,
    Orange
};


enum class ReturnCode
{
    Ok,
    Error,
    InvalidArg,
    InvalidSide
};

enum class CubeSide
{
    Front,
    Left,
    Right,
    Up,
    Down,
    Back
};

#endif /* __TYPES_HPP__ */
