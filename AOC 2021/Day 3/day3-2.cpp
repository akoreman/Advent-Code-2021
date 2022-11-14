#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int bitVectorToBase10(vector<int> vector);

int main()
{
    string line;
    ifstream myfile;
    
    myfile.open("input.txt");
    getline (myfile,line);
    myfile.close();

    myfile.open("input.txt");

    vector<vector<int>> O2Vector;
    vector<vector<int>> CO2Vector;

    while (getline(myfile,line))
    {
        vector<int> vec;

        for (int i = 0; i < line.length(); i++)
            vec.push_back(line[i] - '0');

        O2Vector.push_back(vec);
        CO2Vector.push_back(vec);
    }

    myfile.close();

    int m = 0;
    
    do
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

        vector<vector<int>> newVector;

        for (int i = 0; i < O2Vector.size(); i++)
        {
            if (oneCount >= zeroCount)
            {
                if (O2Vector[i][m] == 1)
                    newVector.push_back(O2Vector[i]);
            }
            else 
            {
                if (O2Vector[i][m] == 0)
                    newVector.push_back(O2Vector[i]);
            }
        }

        O2Vector = newVector;

        m++;
    }while(O2Vector.size() != 1);
    
    m = 0;
    
    do
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

        vector<vector<int>> newVector;

        for (int i = 0; i < CO2Vector.size(); i++)
        {
            if (zeroCount <= oneCount)
            {
                if (CO2Vector[i][m] == 0)
                    newVector.push_back(CO2Vector[i]);
            }
            else 
            {
                if (CO2Vector[i][m] == 1)
                    newVector.push_back(CO2Vector[i]);
            }
        }

        CO2Vector = newVector;

        m++;
    }while(CO2Vector.size() != 1);
    
    long Orating = bitVectorToBase10(O2Vector[0]);
    long COrating = bitVectorToBase10(CO2Vector[0]);

    cout << "Answer day 3 part 2: " << Orating * COrating << '\n';

    return 0;
}

// function to convert from an array of bits to a base 10 int.
int bitVectorToBase10(vector<int> vector)
{
    int output = 0;

    for (int i = 0; i < vector.size(); i++)
        output += pow(2, vector.size() - 1 - i) * vector[i];

    return output;
}