#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int count = 0;
    int oldnum = 0;
    int newnum = 0;

    string line;
    ifstream myfile;

    myfile.open("input.txt");

    getline (myfile,line);
    stringstream ss; 
    ss << line;  
    ss >> oldnum; 

    while ( getline (myfile,line) )
    {
        stringstream ss;  
        ss << line;  
        ss >> newnum; 

        if (newnum > oldnum)
            count++;

        oldnum = newnum;       
    }
    myfile.close();

    std::cout << count << '\n';

  return 0;
}