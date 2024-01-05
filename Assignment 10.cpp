#include<iostream>
#include <string>
#include "Stack.h"
#include<algorithm>
#include<stdlib.h>
using namespace std;

int PostfixEvaluation(string postfix)
{
    Stack stack;
    for(int c:postfix)
    {
        if(isdigit(c))             //can just enter the digits from 0 to 9->int isdigit{(c>='0'&&c<='9')}
        {
            stack.push(c - '0');
        }
        else
        {
            int op1=stack.pop();
            int op2=stack.pop();
            switch(c)
            {
            case '+':
                stack.push(op2 + op1);
                break;
            case '-':
                stack.push(op2 - op1);
                break;
            case '*':
                stack.push(op2 * op1);
                break;
            case '/':
                stack.push(op2 / op1);
                break;
            }
        }
    }
    return stack.pop();
}

int PrefixEvaluation(string prefix)
{
    reverse(prefix.begin(),prefix.end());
    Stack stack;
    for(int c : prefix)
    {
        if(isdigit(c))
        {
            stack.push(c - '0');
        }
        else
        {
            int op1 = stack.pop();
            int op2 = stack.pop();
            switch(c)
            {
            case '+':
                stack.push(op1 + op2);
                break;
            case '-':
                stack.push(op1 - op2);
                break;
            case '*':
                stack.push(op1 * op2);
                break;
            case '/':
                stack.push(op1 / op2);
                break;
            }
        }
    }
    return stack.pop();
}

int main()
{
    system("cls");
    char choice;
    do
    {
        cout<<"**********MENU************"<<endl;
        cout<<"a.Evaluation Postfix"<<endl;
        cout<<"b.Evaluation Prefix"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 'a':
        {
            string postfix;
            cout<<"Enter the Postfix Expression"<<endl;
            cin>>postfix;
            int result1=PostfixEvaluation(postfix);
            cout<<"Postfix Evaluation is "<<result1<<endl;
        }
        break;
        case 'b':
        {
            string prefix;
            cout<<"Enter the Prefix Expression"<<endl;
            cin>>prefix;
            int result2=PrefixEvaluation(prefix);
            cout<<"Prefix Evaluation is "<<result2<<endl;
        }
        break;
        default:
        {
            cout<<"EXIT";
        }
        break;
        }

        cout<<"DO you want to continue(Y||N)"<<endl;
        cin>>choice;
    }
    while(choice == 'Y' || choice == 'y');
    return 0;
}
