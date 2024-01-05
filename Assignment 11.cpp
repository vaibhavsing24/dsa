#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    Node*next;
    int data;
};
class Queue
{
public:
    Node*front=0;
    Node*rear=0;
    Node* create(int value)
    {
        Node*newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;

        return newNode;
    }
    void enqueue(int value)            //Data is Entered from rear pointer
    {
        Node*newNode=create(value);
        if(front == 0 && rear == 0)    //Entering 1st Node
        {
           front = rear = newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
        rear->next=front;             //Making circular queue
    }
    void dequeue()                    //Data is deleted from front pointer
    {
        Node*temp;
        temp=front;
        if(front == 0 && rear == 0)   //Queue is Empty
        {
            cout<<"Underflow!!"<<endl;
        }
        else if(front == rear)        //One Node Remaining in the Queue
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        delete (temp);
    }
    void peek()
    {
        cout<<"Display element at rear end:"<<front->data;
    }
    void display()
    {
        Node*temp = front;
        if(front == 0 && rear == 0)
        {
            cout<<"Underflow!!"<<endl;
        }
        else
        {
            while(temp->next != front)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<" ";

        }
    }
};

int main()
{
    system("cls");
    Queue q;
    char choice;
    do{
        cout<<"a.Enqueue data"<<endl;
        cout<<"b.Dequeue data"<<endl;
        cout<<"c.peek data"<<endl;
        cout<<"d.Display Queue"<<endl;
        cout<<"e.Reverse Queue"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;
        switch(choice)
        {
        case 'a':
            {
                int x;
                cout<<"Enter the value to be Enqueued : "<<endl;
                cin>>x;
                q.enqueue(x);
            }break;
        case 'b':
            {
                q.dequeue();
            }break;
        case 'c':
            {
                q.peek();
            }break;
        case 'd':
            {
                q.display();
            }break;
        case 'e':
            {
                cout<<"Reverse"<<endl;
            }break;
        default:
            {
                cout<<"GOOD BYEEE!!"<<endl;
            }break;
        }
    cout<<"Do you want to continue"<<endl;
    cin>>choice;
    }while(choice == 'Y' || choice == 'y');
    return 0;
}
