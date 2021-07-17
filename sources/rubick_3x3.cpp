#include "rubick_3x3.h"

#include<vector>
#include<random>
#include <ctime>
#include<functional>

Rubick3x3::Rubick3x3(Model model)
{
    this->model = model;
    auto size = model == 1 ? 27 : model == 2 ? 26 : 20;
    for (int i = 1; i <= size; i++)
    {
        cube.push_back(i);
    }
}

static void turning(std::vector<int> num, std::vector<int> &cube)
{
    auto buf = cube[num[0] - 1];
    cube[num[0] - 1] = cube[num[1] - 1];
    cube[num[1] - 1] = cube[num[2] - 1];
    cube[num[2] - 1] = cube[num[3] - 1];
    cube[num[3] - 1] = buf;
}

static std::vector<int> turningFace(std::vector<int> corners, std::vector<int> edges, std::vector<int> cube)
{
    auto res = cube;
    turning(corners, res);
    turning(edges, res);

    return res;
}

void Rubick3x3::TL()  // relatively white
{
    auto corners = std::vector<int>{ 1, 3, 9, 7 };
    auto edges = std::vector<int>{ 2, 6, 8, 4 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::TR()  // relatively white
{
    auto corners = std::vector<int>{ 1, 7, 9, 3 };
    auto edges = std::vector<int>{ 2, 4, 8, 6 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::BoL()  // relatively yellow
{
    auto corners = std::vector<int>{ 25, 27, 21, 19 };
    auto edges = std::vector<int>{ 26, 24, 20, 22 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::BoR()  // relatively yellow
{
    auto corners = std::vector<int>{ 25, 19, 21, 27 };
    auto edges = std::vector<int>{ 26, 22, 20, 24 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::LL()  // relatively green
{
    auto corners = std::vector<int>{ 1, 7, 25, 19 };
    auto edges = std::vector<int>{ 4, 16, 22, 10 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::LR()  // relatively green
{
    auto corners = std::vector<int>{ 1, 19, 25, 7 };
    auto edges = std::vector<int>{ 4, 10, 22, 16 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::RL()  // relatively blue
{
    auto corners = std::vector<int>{ 9, 3, 21, 27 };
    auto edges = std::vector<int>{ 6, 12, 24, 18 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::RR()  // relatively blue
{
    auto corners = std::vector<int>{ 9, 27, 21, 3 };
    auto edges = std::vector<int>{ 6, 18, 24, 12 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::BaL()  // relatively orange
{
    auto corners = std::vector<int>{ 3, 1, 19, 21 };
    auto edges = std::vector<int>{ 2, 10, 20, 12 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::BaR()  // relatively orange
{
    auto corners = std::vector<int>{ 3, 21, 19, 1 };
    auto edges = std::vector<int>{ 2, 12, 20, 10 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::FL()  // relatively red
{
    auto corners = std::vector<int>{ 7, 9, 27, 25 };
    auto edges = std::vector<int>{ 8, 18, 26, 16 };
    cube = turningFace(corners, edges, cube);
}

void Rubick3x3::FR()  // relatively red
{
    auto corners = std::vector<int>{ 7, 25, 27, 9 };
    auto edges = std::vector<int>{ 8, 16, 26, 18 };
    cube = turningFace(corners, edges, cube);
}

Rubick3x3::Turn Rubick3x3::Turning(Turn turning)
{
    std::mt19937 gen{ std::random_device()() };
    std::uniform_int_distribution<int> uid(1, 12);
    auto turn = std::bind(uid, gen);
    auto currentTurn = turning == 0 ? turn() : turning;

    switch (currentTurn)
    {
    case 1:{ TL(); break; }
    case 2:{ TR(); break; }
    case 3:{ BoL(); break; }
    case 4:{ BoR(); break; }
    case 5:{ LL(); break; }
    case 6:{ LR(); break; }
    case 7:{ RL(); break; }
    case 8:{ RR(); break; }
    case 9:{ BaL(); break; }
    case 10:{ BaR(); break; }
    case 11:{ FL(); break; }
    case 12:{ FR(); break; }
    default:
        break;
    }

    return Rubick3x3::Turn(currentTurn);
}

bool Rubick3x3::operator==(const Rubick3x3& rubick)
{
    if (this->model != rubick.model) return false;

    for (int i = 0; i < cube.size(); i++)
    {
        if (this->cube[i] != rubick.cube[i]) return false;
    }
    return true;
}
