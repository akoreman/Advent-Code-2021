#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>

using namespace std;

int main()
{
    cout << "yaay" << '\n';

    string line;
    ifstream myfile;
    
    myfile.open("input.txt");
    getline (myfile,line);
    myfile.close();

    myfile.open("input.txt");

    int inputLength = line.length();
    double inputDepth = 0;

    vector<vector<int>> O2Vector;
    vector<vector<int>> CO2Vector;

    while (getline(myfile,line))
    {
        vector<int> var;

        for (int i = 0; i < inputDepth; i++)
            var.push_back(line[i] - '0');

        O2Vector.push_back(var);
        CO2Vector.push_back(var);
    }

    int m = 0;

    while(O2Vector.size() != 1)
    {
        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < O2Vector.size(); i++)
        {
            if (O2Vector[i][m] == 0)
                zeroCount++;
            else   
                oneCount++;
        }

        m++;

        for (int i = 0; i < O2Vector.size(); i++)
        {
            if (oneCount >= zeroCount)
            {
                if (O2Vector[i][m] == 0)
                    O2Vector.erase(O2Vector.begin() + i);
            }
            else 
            {
                if (O2Vector[i][m] == 1)
                    O2Vector.erase(O2Vector.begin() + i);
            }
        }
    }

    while(CO2Vector.size() != 1)
    {
        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < CO2Vector.size(); i++)
        {
            if (CO2Vector[i][m] == 0)
                zeroCount++;
            else   
                oneCount++;
        }

        m++;

        for (int i = 0; i < CO2Vector.size(); i++)
        {
            if (zeroCount >= oneCount)
            {
                if (CO2Vector[i][m] == 1)
                    CO2Vector.erase(CO2Vector.begin() + i);
            }
            else 
            {
                if (CO2Vector[i][m] == 0)
                    CO2Vector.erase(CO2Vector.begin() + i);
            }
        }
    }
    
    for (int i = 0; i < O2Vector[0].size(); i++)
        cout << O2Vector[0][i];

    cout << '\n';

    for (int i = 0; i < CO2Vector[0].size(); i++)
        cout << CO2Vector[0][i];

    cout << '\n';

    cout << "Answer day 3 part 2: ";

    return 0;
}