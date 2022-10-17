#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm> 
#include <unordered_map>
#include <stack>

using namespace std;

stack<int> inputStack;

void inp(int *a);
void add(int *a, int *b);
void mul(int *a, int *b);
void div(int *a, int *b);
void mod(int *a, int *b);
void eql(int *a, int *b);

int main()
{
    ifstream myFile;
    string line;
    
    stringstream ss;

    long long input = 99999999999999;

    bool finished = false;

    do
    {
        myFile.open("input.txt");
        bool skip = false;

        int* w = (int*) calloc(1, sizeof(int));
        int* x = (int*) calloc(1, sizeof(int));
        int* y = (int*) calloc(1, sizeof(int));
        int* z = (int*) calloc(1, sizeof(int));

        std::cout << input << '\n';

        ss << input;
        string inputString = ss.str();

        for (int i = inputString.length() - 1; i >= 0; i--)
        {
            if (inputString[i] == '0') {skip = true;}
            inputStack.push(inputString[i] - '0');
        }

        string operation;

        char a;
        char b;

        int* aPointer = (int*) malloc(sizeof(int));
        int* bPointer = (int*) malloc(sizeof(int));

        while (std::getline(myFile,line))
        {
            operation = line.substr(0,3);

            a = line[4];
            b = line[6];

            if (a == 'w')
                aPointer = w;

            if (a == 'x')
                aPointer = x;

            if (a == 'y')
                aPointer = y;

            if (a == 'z')
                aPointer = z;
            
            if (b > '0' && b <= '9'){
                *bPointer = b - '0';
            } else {
                if (b == 'w')
                    bPointer = w;

                if (b == 'x')
                    bPointer = x;

                if (b == 'y')
                    bPointer = y;

                if (b == 'z')
                    bPointer = z;
            }

            if (operation == "inp")
                inp(aPointer);

            if (operation == "add")
                add(aPointer, bPointer);

            if (operation == "mul")
                mul(aPointer, bPointer);

            if (operation == "div")
                div(aPointer, bPointer);

            if (operation == "mod")
                mod(aPointer, bPointer);

            if (operation == "eql")
                eql(aPointer, bPointer);  
        }

        std::cout << *z << '\n';

        if (*z == 0 && !skip)
        {
            finished = true;
        } else {
            input--;
        }

    }while(!finished);

    std::cout << "Answer day 24 part 1: " << input << '\n';
    return 0;
}

void inp(int *a)
{
    *a = inputStack.top();
    inputStack.pop();
    return;
};

void add(int *a, int *b)
{
    *a = *a + *b;
    return;
};

void mul(int *a, int *b)
{
    *a = *a * *b;
    return;
};

void div(int *a, int *b)
{
    *a = floor(*a / *b);
    return;
};

void mod(int *a, int *b)
{
    *a = *a % *b;
    return;
};

void eql(int *a, int *b)
{
    *a = (*a == *b) ? 1 : 0;
    return;
};
