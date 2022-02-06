#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int count = 0;
    int oldNum = 0;
    int newNum = 0;

    string line;
    ifstream myFile;

    myFile.open("input.txt");

    getline (myFile,line);
    stringstream ss; 
    ss << line;  
    ss >> oldNum; 

    // Loop over every line and check whether it is an increase from the previous entry.
    while ( getline (myFile,line) )
    {
        stringstream ss;  
        ss << line;  
        ss >> newNum; 

        if (newNum > oldNum)
            count++;

        oldNum = newNum;       
    }
    myFile.close();

    std::cout << count << '\n';

  return 0;
}