#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
};

class Stack
{
private:
    Node*top;
    public:
        Stack()
        {
            top = 0;
        }
    void push(int value)
    {
        Node*newNode=new Node;
        newNode->data=value;
        newNode->next=top;
        top=newNode;
    }

    int pop()
    {
        Node*temp=top;
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
        {
            char popped=top->data;
            top=top->next;
            delete (temp);
            return popped;
        }
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        return (top == 0);
    }
};
