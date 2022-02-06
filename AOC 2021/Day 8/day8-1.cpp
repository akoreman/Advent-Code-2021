#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

// Number of segments per digit: 1-2, 2-5, 3-5, 4-5, 5-5, 6-6, 7-3, 8-7, 9-6
// Unique digits: 1, 4, 7, 8

using namespace std;

vector<string> vec;

int main()
{
    string line;
    ifstream myFile;
    
    myFile.open("input.txt");
    
    int counter = 0;
    
    // Iterate over all lines in the input, take the part after the '|', chop that part at ' ' and when it has 2,3,4 or 7 segments increment the counter.
    while ( getline (myFile,line) )
    {
        string outputPart = line.substr(line.find("|") + 2, line.length() );

        while (outputPart.find(' ') != string::npos)
        {
            string chopPart = outputPart.substr(0,outputPart.find(' ') );
            
            if (chopPart.length() == 2 || chopPart.length() == 3 || chopPart.length() == 4 || chopPart.length() == 7)
                counter++;

            outputPart = outputPart.substr(outputPart.find(' ') + 1, outputPart.length() );
        }

        // Also count the part trailing after tha last ' '.
        if (outputPart.length() == 2 || outputPart.length() == 3 || outputPart.length() == 4 || outputPart.length() == 7)
                counter++;
    }

    myFile.close();

    std::cout << "Answer day 8 part 1: ";
    std::cout << counter << "\n";

    return 0;
}