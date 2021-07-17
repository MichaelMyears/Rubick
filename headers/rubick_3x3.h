#ifndef __RUBICK_3X3_H__
#define __RUBICK_3X3_H__

#include<vector>

class Rubick3x3
{
public:
    enum Model
    {
        allParts = 0x1,
        withoutCenter = 0x2,
        centerless = 0x4
    };

    enum Turn
    {
        noTurn = 0,
        tTL = 1,
        tTR = 2,
        tBoL = 3,
        tBoR = 4,
        tLL = 5,
        tLR = 6,
        tRL = 7,
        tRR = 8,
        tBaL = 9,
        tBaR = 10,
        tFL = 11,
        tFR = 12
    };

    Rubick3x3(Model model = Model::allParts);
    std::vector<int> getCube() { return cube; }
    // left rotation - counterclockwise , right rotation - clockwise
    void TL();  // top left rotate
    void TR();  // top right rotate
    void BoL();  // bottom left rotate
    void BoR();  // bottom right rotate
    void LL();  // left left rotate
    void LR();  // left right rotate
    void RL();  // right left rotate
    void RR();  // right right rotate
    void BaL();  // back left rotate
    void BaR();  // back right rotate
    void FL();  // front left rotate
    void FR();  // front right rotate

    Turn Turning(Turn tern = Turn(0));

    bool operator ==(const Rubick3x3& rubick);

private:
    std::vector<int> cube;
    Model model;


};


#endif
