#ifndef __RUBICK_H__
#define __RUBICK_H__

namespace lm
{

    // Classical Rubik's Cube have red/orange, blue/green, white/yellow side.
    // In this model I decided not to get attached to these colors and just
    // numbered them from 1 to 6.
    // 1 and 2, 3 and 4, 5 and 6 are not adjacent sides.

enum Corner
{
    centercolor12 = 0x1,
    centercolor34 = 0x2,
    centercolor56 = 0x4,
    color12orientation34 = 0x8,
    color12orientation56 = 0x10,
    color12 = 0x20,
    color34 = 0x40,
    color56 = 0x80
};

class Rubick
{
    // Rubick NxNxN have:
    // count of corners = 8
    // count of edges = 12 * (N - 2) or 12N - 24
    // count of centers = 6 * (N - 2) * (N - 2) or 6N^2 - 24N + 24

    // Rubick NxNxN have:
    // 2N counterclockwise, clockwise spins on any orientations
    // Top-Front (TP), Top-Right(TR) and Front-Right(FR) orientations
    // total of such spins - 6N
    // 4 side spins and 2N - 4 internal spins

    // 

    char8_t w;
};

};


#endif
