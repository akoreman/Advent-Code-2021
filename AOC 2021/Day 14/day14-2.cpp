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
    int numIterations = 40;

    ifstream myFile;
    string line;
    
    stringstream ss;

    myFile.open("input.txt");

    string polymer;
    std::getline(myFile,polymer);

    // Map to store each combination and their frequency.
    unordered_map<string, unsigned long long> combinationMap;

    for (int i = 0; i < polymer.length() - 1; i++)
        combinationMap[polymer.substr(i,2)] += 1;

    std::getline(myFile,line);

    // Map to store the polymer splitting rules.
    unordered_map<string, string> translationMap;
    
    // Read the rules into the map.
    while(std::getline(myFile,line))
    {
        string before = line.substr(0, 2);
        string after = before[0] + line.substr(line.find('>') + 2, 1) + before[1];

        translationMap[before] = after;
    }

    // For each iteration step apply the rules to each pair and keep track of the frequency of pairs in the new step.
    while (numIterations > 0)
    {
        unordered_map<string, unsigned long long> newMap;

        for (auto itr: combinationMap)
            if (translationMap.find(itr.first) != translationMap.end())
            {   
                string translatedString = translationMap[itr.first];

                newMap[translatedString.substr(0,2)] += itr.second;
                newMap[translatedString.substr(1,2)] += itr.second;
            }
            else
            {
                newMap[itr.first] += itr.second;
            }

        combinationMap = newMap;
        numIterations--;
    }

    unordered_map<char, unsigned long long> countMap;

    // Count the number of letters in the map.
    for (auto itr: combinationMap)
    {
        countMap[itr.first[0]] += itr.second;
        countMap[itr.first[1]] += itr.second;
    }

    // We count every letter twice, except the first and last.
    countMap[polymer[0]] += 2;
    countMap[polymer[polymer.length() - 1]] += 2;

    unsigned long long max = 0;
    unsigned long long min = ULLONG_MAX;

    for (auto itr: countMap)
    {
        unsigned long long count = itr.second / 2;

        if (count > max)
            max = count;

        if (count < min)
            min = count;
    }
    
    cout << "Answer day 14 part 2: " << max - min << '\n';

    return 0;
}


