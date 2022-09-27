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
    int numIterations = 10;

    ifstream myFile;
    string line;
    
    stringstream ss;

    myFile.open("input.txt");

    string polymer;
    std::getline(myFile,polymer);

    std::getline(myFile,line);

    unordered_map<string, string> translationMap;

    string before;
    string after;

    while(std::getline(myFile,line))
    {
        before = line.substr(0, line.find('>') - 2);
        after = before[0] + line.substr(line.find('>') + 2, line.length()) + before[1];

        translationMap[before] = after;
    }

    string output;

    while (numIterations > 0)
    {
        string output;

        if ( translationMap.find(polymer.substr(0,2)) != translationMap.end() )
            output = translationMap[polymer.substr(0,2)];
        else
            output = polymer.substr(0,2);

        for (int i = 1; i < polymer.length() - 1; i++)
        {
            if ( translationMap.find(polymer.substr(i,  2)) != translationMap.end() )
                output += translationMap[polymer.substr(i, 2)].substr(1,2);
            else
                output += polymer.substr(i + 1,  2);
        }

        polymer = output;
        numIterations--;
    }

    unordered_map<char, int> countMap;

    for (int i = 0; i < polymer.length(); i++)
    {
        countMap[polymer[i]] += 1;
    }

    int max = 0;
    int min = polymer.length();

    for (auto itr: countMap)
    {
        if (itr.second > max)
            max = itr.second;

        if (itr.second < min)
            min = itr.second;
    }

    cout << "Answer day 14 part 1: " << max - min << '\n';

    return 0;
}


