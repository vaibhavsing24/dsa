#include<iostream>
#include<stack>
#include<string>
using namespace std;
struct Node
{
    char data;
    Node*left;
    Node*right;
};
Node*create(char value)
{
    Node*newNode=new Node;
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}
Node*Construct_ET(string postfix)
{
    stack<Node*>s;
    for(char c:postfix)
    {
        if(isalnum(c))
        {
            Node*newNode=create(c);
            s.push(newNode);
        }
        else
        {
            Node*right_operator=s.top();
            s.pop();
            Node*left_operator=s.top();
            s.pop();
            Node*newNode=create(c);
            newNode->left=left_operator;
            newNode->right=right_operator;
            s.push(newNode);
        }
    }
    return s.top();
}
Node* prefixNonrecursive(Node*root)
{
    stack<Node*>s;
    Node*current = root;

    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
            cout<<current->data<<" ";
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        current = current->right;
    }
}
Node* infixNonrecursive(Node*root)
{
    stack<Node*>s;
    Node*current=root;
    while(current != NULL || !s.empty())
    {
        while(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->data<<" ";
        current = current->right;
    }
}
Node* postfixNonrecursive(Node*root)
{
    stack<Node*>s1,s2;
    Node*current = root;
    s1.push(current);
    while(!s1.empty())
    {
        current = s1.top();
        s1.pop();
        s2.push(current);

        if(current->left != NULL)
        {
            s1.push(current->left);
        }
        if(current->right != NULL)
        {
            s1.push(current->right);
        }
    }
    while(!s2.empty())
    {
        current = s2.top();
        s2.pop();
        cout<<current->data<<" ";
    }

}
int main()
{
    string postfix;
    cout<<"Enter the postfix Expression"<<endl;
    cin>>postfix;

    Node*root = Construct_ET(postfix);

    cout<<"Pre-Root";
    prefixNonrecursive(root);
    cout<<endl;

    cout<<"In-Root";
    infixNonrecursive(root);
    cout<<endl;

    cout<<"Post-Root";
    postfixNonrecursive(root);
    cout<<endl;

    return 0;
}
