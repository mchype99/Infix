//******************************************************
//                I N F I X . C P P

/*******************************************************************************************************************************
Name: McKerlton Hyppolite    Z#: Z23590874
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 06/30/2021    Due Time: 11:59
Total Points: 25    Assignment: Module 7 Programming Assignment   Date: 06/28/2021

Description: Program that analyzes prefix expressions and convert each expression into 
             the corresponding infix expression using the stack ADT.
********************************************************************************************************************************/

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
    string post, ignore;
    string in;
    char choice;
    while (true)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Input Prefix expression: ";
        getline(cin, post);
        in = infix(post);
        if (in != "error")
        {
            if (in == "")
                cout << "Infix: " << endl;
            else
                cout << "Infix: " << in << endl;
        }
        cout << "Do you want to do another conversion (Y/N): ";
        cin >> choice;
        cout << "-------------------------------------------------" << endl;
        if (choice == 'N' || choice == 'n')
            break;
        getline(cin, ignore);
    }

    return 0;
}