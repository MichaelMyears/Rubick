#include "rubick2x2.h"

#include<vector>
#include<random>
#include <ctime>
#include<functional>

Rubick2x2::Rubick2x2()
{
    auto size = 8;
    for (int i = 1; i <= size; i++)
    {
        cube.push_back(i);
    }
}

static void turning(std::vector<int> num, std::vector<int>& cube)
{
    auto buf = cube[num[0] - 1];
    cube[num[0] - 1] = cube[num[1] - 1];
    cube[num[1] - 1] = cube[num[2] - 1];
    cube[num[2] - 1] = cube[num[3] - 1];
    cube[num[3] - 1] = buf;
}

static std::vector<int> turningFace(std::vector<int> corners, std::vector<int> cube)
{
    auto res = cube;
    turning(corners, res);

    return res;
}

void Rubick2x2::TL()  // relatively white
{
    auto corners = std::vector<int>{ 1, 2, 4, 3 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::TR()  // relatively white
{
    auto corners = std::vector<int>{ 1, 3, 4, 2 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::BoL()  // relatively yellow
{
    auto corners = std::vector<int>{ 7, 8, 6, 5 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::BoR()  // relatively yellow
{
    auto corners = std::vector<int>{ 7, 5, 6, 8 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::LL()  // relatively green
{
    auto corners = std::vector<int>{ 1, 3, 7, 5 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::LR()  // relatively green
{
    auto corners = std::vector<int>{ 1, 5, 7, 3 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::RL()  // relatively blue
{
    auto corners = std::vector<int>{ 4, 2, 6, 8 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::RR()  // relatively blue
{
    auto corners = std::vector<int>{ 4, 8, 6, 2 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::BaL()  // relatively orange
{
    auto corners = std::vector<int>{ 2, 1, 5, 6 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::BaR()  // relatively orange
{
    auto corners = std::vector<int>{ 2, 6, 5, 1 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::FL()  // relatively red
{
    auto corners = std::vector<int>{ 3, 4, 8, 7 };
    cube = turningFace(corners, cube);
}

void Rubick2x2::FR()  // relatively red
{
    auto corners = std::vector<int>{ 3, 7, 8, 4 };
    cube = turningFace(corners, cube);
}

Rubick2x2::Turn Rubick2x2::Turning(Turn turning)
{
    std::mt19937 gen{ std::random_device()() };
    std::uniform_int_distribution<int> uid(1, 12);
    auto turn = std::bind(uid, gen);
    auto currentTurn = turning == 0 ? turn() : turning;

    switch (currentTurn)
    {
    case 1: { TL(); break; }
    case 2: { TR(); break; }
    case 3: { BoL(); break; }
    case 4: { BoR(); break; }
    case 5: { LL(); break; }
    case 6: { LR(); break; }
    case 7: { RL(); break; }
    case 8: { RR(); break; }
    case 9: { BaL(); break; }
    case 10: { BaR(); break; }
    case 11: { FL(); break; }
    case 12: { FR(); break; }
    default:
        break;
    }

    return Rubick2x2::Turn(currentTurn);
}

bool Rubick2x2::operator==(const Rubick2x2& rubick)
{
    for (int i = 0; i < cube.size(); i++)
    {
        if (this->cube[i] != rubick.cube[i]) return false;
    }
    return true;
}