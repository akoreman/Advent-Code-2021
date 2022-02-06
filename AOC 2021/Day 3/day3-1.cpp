#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

// First retrieve the bitstrings from all bits from the 1st, 2nd,.. etc. positions. Then make the appropriate counting.

int main()
{
    string line;
    ifstream myFile;
    
    myFile.open("input.txt");
    getline (myFile,line);
    myFile.close();

    int inputLength = line.length();
    double inputDepth = 0;

    double* array = new double[inputLength];

    double gamma = 0;
    double epsilon = 0;

    int i = 0;
    while (i < inputLength)
    {
        myFile.open("input.txt");
        array[i] = 0;

        while ( getline (myFile,line) )
        {
            if (i == 0)
                inputDepth++;

            stringstream ss;  
            ss << line;  

            array[i] += (double) line[i] - 48;
        }

        if (array[i]/inputDepth > 0.5)
            gamma += pow(2, inputLength - 1 - i);
        else
            epsilon += pow(2,  inputLength - 1 - i);

        i++;
        myFile.close();
    }
    
    std::cout << gamma << "\n";
    std::cout << epsilon << "\n";

    std::cout << "Answer day 3 part 1: ";
    std::cout << gamma * epsilon << "\n";
    
    return 0;
}