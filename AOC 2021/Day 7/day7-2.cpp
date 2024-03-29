#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <cmath>  

using namespace std;

// This can probably be done more efficiently.

int sum(int x)
{
    int temp = 0;
    int i = 0;

    while(i <= x)
    {
        temp += i;
        i++;
    }
    
    return temp;
}

int main()
{
    string line;
    ifstream myFile;
    
    vector<int> vec;

    myFile.open("input.txt");
    getline (myFile,line);
    myFile.close();

    int i = 0;

    string storageString = "";
    int nearestPosition = 1000000;
    int farthestPosition = 0;

    while (i < line.length() )
    {
        if (line[i] != ',')
        {
            storageString += line[i];
        }
        else
        {
            int position = stoi(storageString);
            nearestPosition = (position < nearestPosition) ? position : nearestPosition;
            farthestPosition = (position > farthestPosition) ? position : farthestPosition;

            vec.push_back(position);
            storageString = "";
        }

        if (i == line.length() - 1)
        {
            int position = stoi(storageString);
            nearestPosition = (position < nearestPosition) ? position : nearestPosition;
            farthestPosition = (position > farthestPosition) ? position : farthestPosition;

            vec.push_back(position);
            storageString = "";
        }
        
        i++;
    }

    i = nearestPosition;

    long minFuelCost = 1000000000;

    while(i <= farthestPosition)
    {
        int fuelCost = 0;
        int j = 0;

        while (j < vec.size())
        {
            fuelCost += sum(abs(vec[j] - i));
            j++;
        }

        if (fuelCost < minFuelCost)
        {
            minFuelCost = fuelCost;
        }
        
        cout << fuelCost << "\n";

        i++;   
    }


    std::cout << "Answer day 7 part 2: " << minFuelCost << "\n";
    
    return 0;
}

