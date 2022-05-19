#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <deque>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    ifstream myFile;
    
    std::deque<int> stack;  

    myFile.open("input.txt");

    char stopCharacter;
    vector<unsigned long long> score;
    unsigned long long tempScore = 0;

    while ( getline (myFile,line) )
    {
        stopCharacter = 'x';
        stack.push_back('x');

        tempScore = 0;

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ')' && line[i] != ']' && line[i] != '}' && line[i] != '>')
            {
                stack.push_back(line[i]);
                continue;
            }
      
            if (line[i] == ')')
            {
                if (stack.back() == '(')
                {
                    stack.pop_back();
                }
                else
                {
                    stopCharacter = line[i];
                    break;
                }
            }

            if (line[i] == ']')
            {
                if (stack.back() == '[')
                {
                    stack.pop_back();
                }
                else
                {
                    stopCharacter = line[i];
                    break;
                }
            }

            if (line[i] == '}')
            {
                if (stack.back() == '{')
                {
                    stack.pop_back();
                }
                else
                {
                    stopCharacter = line[i];
                    break;
                }
            }

            if (line[i] == '>')
            {
                if (stack.back() == '<')
                {
                    stack.pop_back();
                }
                else
                {
                    stopCharacter = line[i];
                    break;
                }
            }

        }

        if (stopCharacter != 'x') { continue;}

        while (true)
        {
            if (stack.back() == 'x') { break; }

            tempScore *= 5;

            if (stack.back() == '(') { tempScore += 1; }
            if (stack.back() == '[') { tempScore += 2; }
            if (stack.back() == '{') { tempScore += 3; }
            if (stack.back() == '<') { tempScore += 4; }

            stack.pop_back();
        }

        score.push_back(tempScore);
        std::cout << tempScore << "\n";
        stack.clear();
    }
    
    sort(score.begin(), score.end());

    std::cout << "Answer day 10 part 2: " << "\n";
    std::cout << score[score.size() / 2] << "\n";

    return 0;
}