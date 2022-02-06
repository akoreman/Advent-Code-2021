#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int horPos = 0;
    int aim = 0;
    int depth = 0;

    string line;
    ifstream myFile;

    myFile.open("input.txt");

    string word;
    string number;
    int intNumber;
    char splitChar = ' ';
    int splitPos;

    while ( getline (myFile,line) )
    {
        stringstream ss;  
        ss << line;  
    
        splitPos = line.find(splitChar);
        word = line.substr(0,splitPos);
        number = line.substr(splitPos + 1, splitPos + 2);

        intNumber = (int) number[0] - 48;

        if (word == "forward")
        {
            horPos += intNumber;
            depth += Aim * intNumber;
        }
        else if (word == "down")
        {
            aim += intNumber;
        }
        else if (word == "up")
        {
            aim -= intNumber;
        }
    }

    myfile.close();

    std::cout << "Answer day 2 part 2: ";
    std::cout << horPos * depth << "\n";

    return 0;
}