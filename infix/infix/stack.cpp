//******************************************************
//                S T A C K . C P P

#include "stack.h"
#include <iostream>
#include<string>

//*************************************************************************************
//Name: Default constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state of the object has been initailized
//Description:   This is the default constructor which will be called automatically when
//               an object is declared. It will initialize the state of the class.
//*************************************************************************************
stack::stack()
{
    s_top = NULL;
}

//*************************************************************************************
//Name: Explicit-value constructor
//Precondition: 
//Postcondition:
//Description:
//*************************************************************************************
stack::stack(const stack& Org)
{
    stack_node* p = Org.s_top;
    (*this).s_top = 0;
    while (p != NULL)
    {
        (*this).push(p->data);
        p = p->next;
    }
}

//*************************************************************************************
//Name: Destructor
//Precondition: List is initialized.
//Postcondition: Memory for list is de-allocated.
//Description: De-allocates all memory allocated for the list.
//*************************************************************************************
stack::~stack()
{
    while (s_top != NULL)
    {
        pop();
    }
}

//*************************************************************************************
//Name: pop()
//Precondition: Stack is initialized
//Postcondition: Value at top of stack has been removed
//Description: Remove value at top of stack
//*************************************************************************************
string stack::pop()
{
    stack_node* p;
    string s = "";
    if (s_top != NULL)
    {
        p = s_top;
        s = p->data;
        s_top = s_top->next;
        delete p;
    }
    return s;
}

//*************************************************************************************
//Name: push()
//Precondition: value is to be added to stack
//Postcondition: value is added at top of stack
//Description: Add value to a stack
//*************************************************************************************
void stack::push(const stack_element& value)
{
    stack_node* p = new stack_node;
    p->data = value;
    p->next = s_top;
    s_top = p;
}

//*************************************************************************************
//Name: top()
//Precondition: Stack is initialized
//Postcondition: Value at top of stack is returned
//Description: Retrieve value at top of stack
//*************************************************************************************
stack_element stack::top()
{
    if (s_top == NULL)
    {
        exit(0);
    }
    else
    {
        return s_top->data;
    }
}

//*************************************************************************************
//Name: isEmpty()
//Precondition: None
//Postcondition: Returns true if stack is empty and false otherwise
//Description: Check if stack is empty
//*************************************************************************************
bool stack::isEmpty()
{
    if (s_top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*************************************************************************************
//Name: size()
//Precondition: Stack is initialzed
//Postcondition: Return size of stack
//Description: Returns the size of the stack
//*************************************************************************************
int stack::size()
{
    int s = 0;
    for (stack_node* p = s_top; p != NULL; p = p->next)
    {
        s++;
    }
    return s;
}

//*************************************************************************************
//Name: char2string
//Precondition: Paremeter c is passed
//Postcondition: String equivalent returned
//Description: Return string equivalent of char
//*************************************************************************************
string char2string(char c)
{
    string s;
    s += c;
    return s;
}

//*************************************************************************************
//Name: revString
//Precondition: Paremeter str is passed
//Postcondition: str is reversed
//Description: Reverse string passed through function
//*************************************************************************************
// Function to reverse a string
void revString(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}

//*************************************************************************************
//Name: infix
//Precondition: Paremeter prefix is passed
//Postcondition: Appropriate infix returned, if any
//Description: Find and return infix expression for given prefix expression
//*************************************************************************************
string infix(string prefix)
{
    stack stck;
 
    if (prefix.length() == 0)
    {
        return "";
    }
    for (int i = prefix.length() - 1; i >= 0; i = i - 2) {
     
        if (!(prefix[i] == '+') && !(prefix[i] == '-') && !(prefix[i] == '*') && !(prefix[i] == '/'))
        {
            stck.push(char2string(prefix[i]));
        }
        else {
           
            if (stck.isEmpty())
            {
                cout << "too many operators and not enough operands" << endl;
                return "error";
            }
            string s1 = stck.pop();
           
            if (stck.isEmpty())
            {
                cout << "too many operators and not enough operands" << endl;
                return "error";
            }
            string s2 = stck.pop();

            stck.push(")" + s2 + prefix[i] + s1 + "(");
        }
    }

    if (stck.size() > 1)
    {
        cout << "too many operands and not enough operators" << endl;
        return "error";
    }
    string result = stck.pop();
    revString(result);
    return result;
}


	




