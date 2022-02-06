#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int horPos = 0;
    int Aim = 0;
    int Depth = 0;

    string line;
    ifstream myfile;

    myfile.open("input.txt");

    string Word;
    string Number;
    int intNumber;
    char splitChar = ' ';
    int splitPos;

    while ( getline (myfile,line) )
    {
        stringstream ss;  
        ss << line;  
    
        splitPos = line.find(splitChar);
        Word = line.substr(0,splitPos);
        Number = line.substr(splitPos + 1, splitPos + 2);

        intNumber = (int) Number[0] - 48;

        if (Word == "forward")
        {
            horPos += intNumber;
            Depth += Aim * intNumber;
        }
        else if (Word == "down")
        {
            Aim += intNumber;
        }
        else if (Word == "up")
        {
            Aim -= intNumber;
        }
    }

    myfile.close();

    std::cout << "Answer day 2 part 2: ";
    std::cout << horPos * Depth << "\n";

    return 0;
}