#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
    string line;
    ifstream myfile;
    
    myfile.open("input.txt");
    getline (myfile,line);
    myfile.close();

    int inputLength = line.length();
    double inputDepth = 0;

    double* Array = new double[inputLength];

    double gamma = 0;
    double epsilon = 0;

    int i = 0;
    while (i < inputLength)
    {
        myfile.open("input.txt");
        Array[i] = 0;

        while ( getline (myfile,line) )
        {
            if (i == 0)
                inputDepth++;

            stringstream ss;  
            ss << line;  

            Array[i] += (double) line[i] - 48;
        }

        if (Array[i]/inputDepth > 0.5)
            gamma += pow(2, inputLength - 1 - i);
        else
            epsilon += pow(2,  inputLength - 1 - i);

        i++;
        myfile.close();
    }
    
    std::cout << gamma << "\n";
    std::cout << epsilon << "\n";

    std::cout << "Answer day 3 part 1: ";
    std::cout << gamma * epsilon << "\n";
    
    return 0;
}