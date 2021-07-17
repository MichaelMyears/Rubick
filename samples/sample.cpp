#include"rubick_3x3.h"
#include"rubick2x2.h"

#include<iostream>
#include<map>
#include<random>
#include <fstream>
#include <ctime>

using MapVIVI = std::map<std::vector<int>, std::vector<int>>;

void PrintPosition(std::vector<int> cube, Rubick3x3::Turn turn = Rubick3x3::Turn(0))
{
    for (int i = 0; i < cube.size(); i++)
    {
        std::cout << (cube[i] < 10 ? " " : "") << cube[i] << ", ";

    }
    std::cout << turn << std::endl;
}

inline bool isARepeting(std::vector<int> rotations, int turning)
{
    auto size = rotations.size();
    if (rotations.empty()) return false;
    auto delta = rotations[size - 1] % 2 == 0 ? 1 : -1;
    if (rotations[size - 1] == turning + delta) return true;
    if (size < 2) return false;
    return rotations[size - 1] == turning && rotations[size - 2] == turning;
}

void randomBrute(MapVIVI& map, std::vector<int> rotations, int num)
{
    Rubick2x2 rubick;
    for (int i = 1; i < 1000000; i++)
    {
        rubick.Turning();
        map[rubick.getCube()] = {};
        if (map.size() % 100 == 0)
        {
            system("cls");
            std::cout << map.size() << " " << i;
            //PrintPosition(rotations);
            std::cout << std::endl;
        }
    }
}

void Brute(MapVIVI& map, std::vector<int> rotations, int num)
{
    if (num > 10) return;
    Rubick2x2 rubick;
    for (const auto& rot : rotations)
    {
        rubick.Turning(Rubick2x2::Turn(rot));
    }
    auto buf = rotations;
    auto rubickBuf = rubick;
    for (int i = 1; i <= 12; i++)
    {
        if(isARepeting(rotations, i)) continue;
        rotations.push_back(i);
        rubick.Turning(Rubick2x2::Turn(i));
        if (map.find(rubick.getCube()) == map.end())
        {
            map[rubick.getCube()] = rotations;
        }
        else
        {
            if (rotations.size() < map[rubick.getCube()].size())
            {
                map[rubick.getCube()] = rotations;
            }
        }
        Brute(map, rotations, ++num);
        num--;
        rotations = buf;
        rubick = rubickBuf;
        if (map.size() % 100 == 0)
        {
            system("cls");
            std::cout << map.size() << " ";
            PrintPosition(rotations);
            std::cout << std::endl;
        }
    }
}

int main(int argc, char* argv[], char* envp[])
{
    Rubick3x3 rubick1;
    Rubick3x3 rubick2;
    rubick1.BaL();
    rubick2.BaL();
    MapVIVI map;

    unsigned int start_time = clock(); // начальное время
    //Brute(map, std::vector<int>{}, 0);
    randomBrute(map, std::vector<int>{}, 0);
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

    std::cout << search_time << std::endl;

    //PrintPosition(rubick.getCube());
    //for (int i = 0; i < 1000; i++)
    //{
    //    auto turn = rubick.Turning();
    //    PrintPosition(rubick.getCube(), turn);
    //}

    std::ofstream fout("output.txt", std::ios_base::trunc);
    fout << "Работа с файлами в С++";
    fout << "ssss" << std::endl;
    fout.close();

    return 0;
}