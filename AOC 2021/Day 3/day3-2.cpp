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

    myfile.open("input.txt");

    int inputLength = line.length();

    vector<vector<int>> O2Vector;
    vector<vector<int>> CO2Vector;

    while (getline(myfile,line))
    {
        vector<int> var;

        for (int i = 0; i < inputLength; i++)
            var.push_back(line[i] - '0');

        O2Vector.push_back(var);
        CO2Vector.push_back(var);
    }

    myfile.close();

    int m = 0;
    
    do
    {
        //cout << O2Vector.size() << '\n';

        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < O2Vector.size(); i++)
        {
            if (O2Vector[i][m] == 0)
                zeroCount++;
            else   
                oneCount++;
        }

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

        m++;
    }while(O2Vector.size() != 1);
    
    cout << O2Vector.size() << '\n';

    m = 0;
    
    do
    {
        //cout << CO2Vector.size() << '\n';

        int zeroCount = 0;
        int oneCount = 0;

        for (int i = 0; i < CO2Vector.size(); i++)
        {
            if (CO2Vector[i][m] == 0)
                zeroCount++;
            else   
                oneCount++;
        }

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

        m++;
    }while(CO2Vector.size() != 1);
    
    cout << CO2Vector.size() << '\n';
    
    long Orating = 0;

    for (int i = 0; i < O2Vector[0].size(); i++)
    {
        cout << O2Vector[0][i];
        Orating += pow(2, inputLength - 1 - i) * O2Vector[0][i];
    }

    cout << '\n';
    
    cout << Orating << '\n';

    long COrating = 0;

    for (int i = 0; i < CO2Vector[0].size(); i++)
    {
        cout << CO2Vector[0][i];
        COrating += pow(2, inputLength - 1 - i) * CO2Vector[0][i];
    }

    cout << '\n';
    
    cout << COrating << '\n';

    cout << "Answer day 3 part 2: " << Orating * COrating << '\n';

    return 0;
}