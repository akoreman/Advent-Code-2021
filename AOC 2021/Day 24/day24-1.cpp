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
    long long input = 99999999999999;

    bool finished = false;

    do
    {
        ifstream myFile;
        myFile.open("input.txt");
        bool skip = false;

        int* w = (int*) calloc(1, sizeof(int));
        int* x = (int*) calloc(1, sizeof(int));
        int* y = (int*) calloc(1, sizeof(int));
        int* z = (int*) calloc(1, sizeof(int));

        //std::cout << input << '\n';
        stringstream ss;
        ss << input;
        string inputString = ss.str();

        inputStack = {};

        for (int i = inputString.length() - 1; i >= 0; i--)
        {
            if (inputString[i] == '0') {skip = true;}
            inputStack.push(inputString[i] - '0');
        }

        string operation;

        string line;

        int* varPointer = (int*) malloc(sizeof(int));

        while (std::getline(myFile,line))
        {
            cout << w << '\n';

            int* aPointer;
            int* bPointer = (int*) calloc(1, sizeof(int));

            operation = line.substr(0,3);

            char a = line[4];
            char b = line[6];
            char bl = line[7];

            //cout << "a " << a << " b " << b << bl << '\n';

            if (a == 'w')
                aPointer = w;

            if (a == 'x')
                aPointer = x;

            if (a == 'y')
                aPointer = y;

            if (a == 'z')
                aPointer = z;
            



            if (b > '0' && b <= '9')
            {
                bPointer = varPointer;
                if (bl != NULL)
                    *bPointer = (b - '0') * 10 + (bl - '0');
                else
                    *bPointer = (b - '0');
            }

            if (b == 'w')
                bPointer = w;

            if (b == 'x')
                bPointer = x;

            if (b == 'y')
                bPointer = y;

            if (b == 'z')
                bPointer = z;
            




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
            finished = true;
        else 
            input--;

    }while(!finished);

    std::cout << "Answer day 24 part 1: " << input << '\n';
    return 0;
}

void inp(int* a)
{
    //cout << "inp " << *a << " " << inputStack.top() << '\n';
    *a = inputStack.top();
    inputStack.pop();
    //cout << "a " << *a << '\n';
    return;
};

void add(int* a, int* b)
{
    //cout << "add " << *a << " " << *b << '\n';
    *a += *b;
    return;
};

void mul(int* a, int* b)
{
    //cout << "mul " << *a << " " << *b << '\n';
    *a *= *b;
    return;
};

void div(int* a, int* b)
{
    //cout << "div " << *a << " " << *b << '\n';
    *a = floor(*a / *b);
    return;
};

void mod(int* a, int* b)
{
    //cout << "mod " << *a << " " << *b << '\n';
    *a %= *b;
    return;
};

void eql(int* a, int* b)
{
    //cout << "eql " << *a << " " << *b << '\n';
    *a = (*a == *b) ? 1 : 0;
    return;
};
