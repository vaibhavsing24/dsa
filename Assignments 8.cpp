#include<iostream>
#include "Stack.h"
#include <string.h>

using namespace std;
int precedence(char c)
{
    if(c == '^')
    return 3;

    else if(c == '*' || c == '/')
    return 2;

    else if(c == '+' || c == '-')
    return 1;

    else
    return -1;
}
string InfixToPostfix(string infix)
{
    Stack stack;
    string postfix = " ";
    for(char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            while(!stack.isEmpty() && stack.peek() != '(')
            {
                postfix+=stack.pop();
            }
            stack.pop();
        }
        else
        {
            while(!stack.isEmpty() && precedence(c) <= precedence(stack.peek()))
            {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }
       while(!stack.isEmpty())
       {
           postfix+=stack.pop();
       }
    return postfix;
}
int main()
{
    string infix;
    cout<<"Enter the Infix Expression String"<<endl;
    cin>>infix;

    string result=InfixToPostfix(infix);
    cout<<"Infix to Postfix Expression is "<<result;

    return 0;
}
