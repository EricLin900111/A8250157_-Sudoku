#include <iostream>
#include <sstream>
#include <string>
#include "common.h"
#include "utility.inl"

// return number of grids to be erased
int inputDifficulty()
{
    cls();

    std::string cmd;
    while (1)
    {
        std::cout << "設置難度：1簡單 2普通 3困難" << std::endl;

        std::cin >> cmd;

        Difficulty difficulty = static_cast<Difficulty>(std::stoi(cmd));

        switch (difficulty)
        {
        case Difficulty::EASY:
            return 20;
        case Difficulty::NORMAL:
            return 35;
        case Difficulty::HARD:
            return 50;
        default:
            std::cout << "輸入錯誤！" << std::endl;
            continue;
        }
    }

    assert(0);
    return 0;
}