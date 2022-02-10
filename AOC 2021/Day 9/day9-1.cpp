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
    ifstream myFile;
    
    // Read the file and create a double vector to store it in. Pad the array with rows of 10s and columns of 10s.

    myFile.open("input.txt");
    getline (myFile,line);
    myFile.close();

    int intputWidth = line.length();
    
    myFile.open("input.txt");

    vector<vector<int>> array;

    vector<int> tenRow;

    for (int i = 0; i < intputWidth + 2; i++)
    {
        tenRow.push_back(10);
    }

    array.push_back(tenRow);

    while ( getline (myFile,line) )
    {
        vector<int> row;

        row.push_back(10);
        
        for (int i = 0; i < line.length(); i++)
        {
            row.push_back((int) line[i] - 48);
        }

        row.push_back(10);

        array.push_back(row);
    }

    array.push_back(tenRow);

    myFile.close();

    // See whether points are a minimum, since we padded the array with 10s we can use a single if check.

    int counter = 0;

    for (int i = 1; i < array.size() - 1 ; i++)
    {
        for (int j = 1; j < intputWidth + 1; j++)
        {
            if ( array[i][j] < array[i-1][j] && array[i][j] < array[i+1][j]  && array[i][j] < array[i][j-1]  && array[i][j] < array[i][j+1] )
            {             
                counter += 1 + array[i][j];
            }
            
        }
    }

    cout << "Answer day 9 part 1: " << "\n";
    cout << counter << "\n";

    return 0;
}

