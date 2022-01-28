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
    
    vector<int> vec;

    myfile.open("input.txt");
    getline (myfile,line);
    myfile.close();

    while (getline (myfile,line))
    {
        vec.push_back()
    }




    std::cout << "Answer day 7 part 1: ";
    std::cout << " " << "\n";
    
    return 0;
}