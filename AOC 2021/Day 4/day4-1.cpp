#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm> 
#include <unordered_map>

using namespace std;

int main()
{
    int numIterations = 40;

    ifstream myFile;
    
    myFile.open("input.txt");

    string drawnNumbers;
    std::getline(myFile,drawnNumbers);

    vector<BingoBoard> bingoBoards;

    while(std::getline(myFile,drawnNumbers))
    {
        
    }

    
    cout << "Answer day 4 part 1: " << '\n';

    return 0;
}

class BingoBoard
{
    public:
    int * rowPointer;
    int * columnPointer;

    BingoBoard(int input[], int dimension)
    {
        rowPointer = (int*) malloc(sizeof(int) * 5 * 5);
        columnPointer = (int*) malloc(sizeof(int) * 5 * 5);

        int row = 0;
        int column;

        for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++)
        {
            setValue(floor(i / dimension), i % dimension, input[i], dimension);
        }

    }

    void setValue(int row, int column, int value, int dimension)
    {
        *((rowPointer + column) + row * dimension) = value;
        *((columnPointer + row) + column * dimension) = value;
    }

};