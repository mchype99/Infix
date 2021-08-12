//******************************************************
//                S T A C K . H

#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

typedef string stack_element;
void revString(string&);//Reverse string
string infix(string);//Return infix expression
string char2string(char);//Return string equivalent of char

class stack_node
{
public:
    stack_element data;
    stack_node* next;
};

class stack
{
public:
    stack();//Default constructor
    ~stack();//Destructor
    stack(const stack&);//Explicit-value constructor
    stack_element top();//Retrieve value at top of stack (if any).
    string pop();//Remove value at top of stack (if any).
    void push(const stack_element&);//Add a value to a stack.
    bool isEmpty();//Checks if stack is empty
    int size();//Checks for stack size
private:
    stack_node* s_top;
};

#endif
