#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int bitVectorToBase10(vector<int> vector);

int main()
{
    string line;
    ifstream myfile;
    
    myfile.open("input.txt");
    getline (myfile,line);
    myfile.close();

    

    cout << "Answer day 22 part 1: " << '\n';

    return 0;
}

class instructionSet{
    public:
        vector<cubeInstruction> vec;

    void addInstruction(cubeInstruction instruction)
    {
        vec.push_back(instruction);
    }

}

class cubeInstruction{
    public:
        int xStart;
        int xEnd;
        int yStart;
        int yEnd;
        int zStart;
        int zEnd;

        cubeInstruction(int xStart, int xEnd)
        {
            this->xStart = xStart;
            this->xEnd = xEnd;
            this->yStart = yStart;
            this->yEnd = yEnd;
            this->zStart = zStart;
            this->zEnd = zEnd;
        }
};
