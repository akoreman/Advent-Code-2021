#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <deque>

using namespace std;

int main()
{
    string line;
    ifstream myFile;
    
    std::deque<int> stack;  

    myFile.open("input.txt");

    char stopCharacter;
    int score = 0;

    while ( getline (myFile,line) )
    {
        stopCharacter = 'x';
        stack.push_back('x');

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

        if (stopCharacter == ')') {score += 3; }
        if (stopCharacter == ']') {score += 57; }
        if (stopCharacter == '}') {score += 1197; }
        if (stopCharacter == '>') {score += 25137; }

        stack.clear();
    }
    
    std::cout << "Answer day 10 part 1: " << "\n";
    std::cout << score << "\n";

    return 0;
}