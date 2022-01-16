#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string line;
    ifstream myfile;

    myfile.open("input.txt");


    while ( getline (myfile,line) )
    {
        stringstream ss;  
        ss << line;  
    

    }

    myfile.close();

    std::cout << "Answer day 3 part 1: ";
    std::cout << " " << "\n";

    return 0;
}