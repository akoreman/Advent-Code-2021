#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{

    
    int count = 0;
    int oldnum = 0;
    int newnum = 0;
    
    int x = 0;

    string line;
    ifstream myfile;

    int lineCount = 0;

    myfile.open("input.txt");
    while ( getline (myfile,line) )
        lineCount++;

    myfile.close();

    myfile.open("input.txt");

    int currentWindow = 0;

    int measurement0 = 0;
    int measurement1 = 0;
    int measurement2 = 0;
    int measurement3 = 0;

    int i = 0;
    while ( getline (myfile,line) )
    {
        //if (i == lineCount - 3)
        //    break;

        stringstream ss;  
        ss << line;      
        ss >> x;

        if (i == 0)
        {
            measurement0 = x;
        }

        if (i == 1)
        {
            measurement1 = x;
        }

        if (i == 2)
        {
            measurement2 = x;
        }

        if (i == 3)
        {
            measurement3 = x;

            oldnum = measurement0 + measurement1 + measurement2;
            newnum = measurement1 + measurement2 + measurement3;

            if (newnum > oldnum)
                count++;
        }

        if (i > 3)
        {

            measurement0 = measurement1;
            measurement1 = measurement2;
            measurement2 = measurement3;
            measurement3 = x;

            oldnum = measurement0 + measurement1 + measurement2;
            newnum = measurement1 + measurement2 + measurement3;

            if (newnum > oldnum)
                count++;
        }

        i++;
    }

    myfile.close();

    std::cout << "Answer day 1 part 2: ";
    std::cout << count << '\n';

  return 0;
}