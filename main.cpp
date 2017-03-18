#include <iostream>
#include "types.hpp"
#include "cell.hpp"
#include "side.hpp"
#include "cube.hpp"

int main (int argc, char *argv[])
{
    size_t n = 3;
    std::vector< std::vector< Cell > > blue;
    for (size_t i = 0; i < n; ++i)
    {
        blue.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            blue[i][j] = Color::Blue;
        }
    }
    Side side_b (blue, n);

    std::vector< std::vector< Cell > > green;
    for (size_t i = 0; i < n; ++i)
    {
        green.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            green[i][j] = Color::Green;
        }
    }
    Side side_g (green, n);

    std::vector< std::vector< Cell > > orange;
    for (size_t i = 0; i < n; ++i)
    {
        orange.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            orange[i][j] = Color::Orange;
        }
    }
    Side side_o (orange, n);

    std::vector< std::vector< Cell > > red;
    for (size_t i = 0; i < n; ++i)
    {
        red.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            red[i][j] = Color::Red;
        }
    }
    Side side_r (red, n);

    std::vector< std::vector< Cell > > white;
    for (size_t i = 0; i < n; ++i)
    {
        white.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            white[i][j] = Color::White;
        }
    }
    Side side_w (white, n);

    std::vector< std::vector< Cell > > yellow;
    for (size_t i = 0; i < n; ++i)
    {
        yellow.push_back (std::vector< Cell > (n));
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            yellow[i][j] = Color::Yellow;
        }
    }
    Side side_y (yellow, n);

    Cube cube (side_b, side_g, side_o, side_r, side_w, side_y);

    std::cout << cube.printCube () << "\n";
    return 0;
}
