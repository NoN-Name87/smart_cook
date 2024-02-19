#include <iostream>
#include <vector>

constexpr int TOMATO_J = 4;
constexpr int TOMATO_S = 2;

class Solution {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        std::vector<int> burgers;
        int counter = 0;
        while(tomatoSlices >= 0 && cheeseSlices >= 0)
        {
            int jumbo = get_burgers(tomatoSlices, cheeseSlices, TOMATO_J);
            int small = get_burgers(tomatoSlices, cheeseSlices, TOMATO_S);
            if(jumbo != 0 || small != 0 || (tomatoSlices == 0 && cheeseSlices == 0))
            {
                burgers.emplace_back(jumbo + counter);
                burgers.emplace_back(small + counter);
                break;
            }
            counter++;
            cheeseSlices -= 2;
            tomatoSlices = tomatoSlices - TOMATO_J - TOMATO_S;
        }
        return burgers;
    }
private:
    int get_burgers(int tomatoSlices, int cheeseSlices, int numTomato)
    {
        int result = tomatoSlices % numTomato == 0 && tomatoSlices / numTomato == cheeseSlices ?
        tomatoSlices / numTomato : 0;
        return result;
    }
};

int main(int argc, char **argv)//cmd: smart_cook <tomato> <cheese>
{
    try
    {
        if(argc > 2)
        {
            Solution sol;
            int tomato = std::stoi(argv[1]);
            int cheese = std::stoi(argv[2]);
            auto result = sol.numOfBurgers(tomato, cheese);
            for(const auto & i : result)
            {
                std::cout << i << " ";
            }
        }      
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << "\n";
    }
}