#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

stack<int> inputStack;

void inp(int *a);
void add(int *a, int *b);
void mul(int *a, int *b);
void div(int *a, int *b);
void mod(int *a, int *b);
void eql(int *a, int *b);


// Value of the number to check.
unsigned long long input = 29991993698469;
//unsigned long long input = 14691271141118;



int main()
{
    ifstream myFile;
    myFile.open("input.txt");

    // Setup the 4 variables.
    int* w = (int*) calloc(1, sizeof(int));
    int* x = (int*) calloc(1, sizeof(int));
    int* y = (int*) calloc(1, sizeof(int));
    int* z = (int*) calloc(1, sizeof(int));

    stringstream ss;
    ss << input;
    string inputString = ss.str();

    // Read the input value into a stack.
    inputStack = {};

    for (int i = inputString.length() - 1; i >= 0; i--)
        inputStack.push(inputString[i] - '0');

    string operation;
    string line;

    // Read each of the instructions and apply to the variables.
    while (std::getline(myFile,line))
    {
        int* aPointer;
        int* bPointer;

        // Interpret the instruction line.
        operation = line.substr(0,3);

        char a = line[4];
        char b0 = line[6];
        char b1 = line[7];
        char b2 = line[8];

        // Assign the right variable to the first pointer.
        switch(a) 
        {
            case 'w':
                aPointer = w;
                break;

            case 'x':
                aPointer = w;
                break;

            case 'y':
                aPointer = w;
                break;

            case 'z':
                aPointer = w;
                break;
        }

        // If b is a variable, assign the right pointer.
        // If b a value, read and assign the right value to the pointer.
        if (b0 == 'w')
            bPointer = w;
        else if (b0 == 'x')
            bPointer = x;
        else if (b0 == 'y')
            bPointer = y;
        else if (b0 == 'z')
            bPointer = z;
        else if (b0 > '0' && b0 <= '9')
        {
            bPointer = (int*) calloc(1, sizeof(int));

            if (b1 != NULL)
                *bPointer = (b0 - '0') * 10 + (b1 - '0');
            else
                *bPointer = (b0 - '0');
        }
        else if (b0 == '-')
        {
            bPointer = (int*) calloc(1, sizeof(int));

            if (b2 != NULL)
                *bPointer = -1 * ( (b1 - '0') * 10 + (b2 - '0'));
            else
                *bPointer = -1 * (b1 - '0');
        }
        
        // Apply the operation.
        if (operation == "inp")
            inp(aPointer);
        else if (operation == "add")
            add(aPointer, bPointer);
        else if (operation == "mul")
            mul(aPointer, bPointer);
        else if (operation == "div")
            div(aPointer, bPointer);
        else if (operation == "mod")
            mod(aPointer, bPointer);
        else if (operation == "eql")
            eql(aPointer, bPointer);  
    }

    std::cout << "Final value in z for input " << input << ": " << *z << '\n';

    return 0;
}


// The 6 possible operations.

void inp(int* a)
{
    *a = inputStack.top();
    inputStack.pop();
    return;
};

void add(int* a, int* b)
{
    *a += *b;
    return;
};

void mul(int* a, int* b)
{
    *a *= *b;
    return;
};

void div(int* a, int* b)
{
    *a = floor(*a / *b);
    return;
};

void mod(int* a, int* b)
{
    *a %= *b;
    return;
};

void eql(int* a, int* b)
{
    *a = (*a == *b) ? 1 : 0;
    return;
};
