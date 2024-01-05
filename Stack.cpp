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

    void pop()
    {
        Node*temp=top;
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
        {
            int popped=top->data;
            top=top->next;
            cout<<popped;
            delete (temp);
        }
    }

    void peek()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
            return ;
        }
        else
        {
            cout<<top->data;
        }
    }

    bool isEmpty()
    {
        return (top == 0);
    }
};
int main()
{
     Stack stack;
     stack.push(10);
     stack.push(100);
     stack.push(20);
     stack.pop();
     stack.push(201);
     stack.peek();
return 0;
}
