#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm> 
#include <unordered_map>

using namespace std;

bool AreVectorsEqual(vector<int> A, vector<int> B)
{
    if (A.size() != B.size())
        return false;

    for (int x = 0; x < A.size(); x++)
        if (A[x] != B[x])
            return false;

    return true;
};

int main()
{
    struct Position2D{
        int x;
        int y;
    };

    // Borrowed from https://stackoverflow.com/questions/10405030/c-unordered-map-fail-when-used-with-a-vector-as-key
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            int hash = V.size();
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };  

    string line;
    ifstream myFile;
    
    stringstream ss;

    int score = 0;

    int maxX = 0;
    int maxY = 0;

    int lineCount = 0;

    myFile.open("input.txt");

    int x;
    string xString;

    int y;
    string yString;

    vector<vector<int>> positionVector;
    unordered_map<vector<int>, vector<int>, VectorHasher> map;

    while ( std::getline(myFile,line)  )
    {
        if (line.length() == 0) { break; }

        xString = line.substr(0, line.find(','));
        yString = line.substr(line.find(',') + 1, line.length());

        ss.str(std::string());
        ss.clear();
        ss << xString;
        ss >> x;

        ss.str(std::string());
        ss.clear();
        ss << yString;
        ss >> y;

        if (x > maxX) { maxX = x; }
        if (y > maxY) { maxY = y; }

        vector<int> position{x,y};

        map[position] = position;
        positionVector.push_back(position);

        lineCount++;
    }

    std::getline(myFile,line);

    char foldAxis = line[line.find('=') - 1];

    string foldLineString = line.substr(line.find('=') + 1, line.length());
    int foldLine;

    ss.str(std::string());
    ss.clear();
    ss << foldLineString;
    ss >> foldLine;

    score = lineCount;

    for (int i = 0; i < lineCount; i++)
    {
        if (foldAxis == 'x')
        {
            if (positionVector[i][0] >= foldLine)
            {
                vector<int> transformedVector{foldLine - (positionVector[i][0] - foldLine), positionVector[i][1]};

                if ( map.find(transformedVector) != map.end() )
                    score--;                
            }
        }
        else
        {
            if (positionVector[i][1] >= foldLine)
            {
                vector<int> vec{positionVector[i][0], foldLine - (positionVector[i][1] - foldLine)};

                if ( map.find(vec) == map.end() )
                    score--;
            }
        }
    }
    /*
    cout << "fold axis: " << foldAxis << '\n';
    cout << "fold line: " << foldLine << '\n';

    cout << "max x: " << maxX << '\n';
    cout << "max y: " << maxX << '\n';
    */

    std::cout << "Answer day 13 part 1: " << score << "\n";

    return 0;
}





