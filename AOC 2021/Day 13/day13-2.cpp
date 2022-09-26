#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm> 
#include <unordered_map>

using namespace std;

int main()
{
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

    myFile.open("input.txt");

    int x;
    string xString;

    int y;
    string yString;

    unordered_map<vector<int>, bool, VectorHasher> positionMap;

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

        vector<int> position{x,y};

        positionMap[position] = true;
    }

    int lastFoldX = 0;
    int lastFoldY = 0;

    while(std::getline(myFile,line))
    {
        char foldAxis = line[line.find('=') - 1];

        string foldLineString = line.substr(line.find('=') + 1, line.length());
        int foldLine;

        ss.str(std::string());
        ss.clear();
        ss << foldLineString;
        ss >> foldLine;

        for (auto itr: positionMap)
        {
            if (foldAxis == 'x')
            {
                lastFoldX = foldLine;

                if (itr.first[0] >= foldLine)
                {
                    vector<int> transformedVector{foldLine - (itr.first[0] - foldLine), itr.first[1]};

                    if ( positionMap.find(transformedVector) == positionMap.end() )
                        positionMap[transformedVector] = true;
                }
            }
            else
            {
                lastFoldY = foldLine;

                if (itr.first[1] >= foldLine)
                {
                    vector<int> transformedVector{itr.first[0], foldLine - (itr.first[1] - foldLine)};

                    if ( positionMap.find(transformedVector) == positionMap.end() )
                        positionMap[transformedVector] = true;
                }
            }
        }
    }
    
    for (int j = 0; j < lastFoldY; j++)
    {
        string output = "|";

        for (int i = 0; i < lastFoldX; i++)
        {
            vector<int> position{i,j};

            if ( positionMap.find(position) != positionMap.end() )
                output += 'x';
            else
                output += ' ';
        }

        output += '|';
        std::cout << output << '\n';
    }

    return 0;
}


