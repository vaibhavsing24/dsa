#include<iostream>
#include<string>
#include"StackA.h"
#include<algorithm>            //to access reverse function
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
string InfixToPrefix(string infix)
{
    Stack stack;

    reverse(infix.begin() , infix.end());
    string prefix=" ";
    for(char c:infix)
    {
        if(isalnum(c))
        {
            prefix += c;
        }
        else if (c == ')')
        {
            stack.push(c);
        }
        else if(c == '(')
        {
            while(!stack.isEmpty() && stack.peek() != ')')
            {
                prefix += stack.pop();
            }
            stack.pop();
        }
        else
        {
         while(!stack.isEmpty() && precedence(c) < precedence(stack.peek()))
         {
            prefix += stack.pop();
         }
         stack.push(c);
        }
    }
   while(!stack.isEmpty())
   {
       prefix+=stack.pop();
   }
   reverse(prefix.begin(),prefix.end());
   return prefix;
}
int main()
{
    string infix;
    cout<<"Enter the infix Expression"<<endl;
    cin>>infix;

    string result = InfixToPrefix(infix);
    cout<<"Infix to Prefix Expression : "<<result;
    return 0;
}
