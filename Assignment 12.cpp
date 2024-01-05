#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct Node
{
    char data;
    Node*left;
    Node*right;
};
Node*create(char c)
{
    Node*newNode = new Node();
    newNode->data=c;
    newNode->left=NULL;
    newNode->right=NULL;

return newNode;
}
Node*Construct_ET(string postfix)
{
    stack<Node*>s;
    for(char c : postfix)
    {
        if(isalnum(c))
        {
            Node* newNode=create(c);
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
void preorderRecursive(Node*root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}
void inorderRecursive(Node*root)
{
    if(root!=NULL)
    {
        inorderRecursive(root->left);
        cout<<root->data<<" ";
        inorderRecursive(root->right);
    }
}
void postorderRecursive(Node*root)
{
    if(root!=NULL)
    {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    system("cls");
    string postfix;
    cout<<"Enter the postfix Expression"<<endl;
    cin>>postfix;

    Node*root=Construct_ET(postfix);
    cout<<"Root Element : "<<root->data<<" "<<endl;

    preorderRecursive(root);
    cout<<endl;
    inorderRecursive(root);
    cout<<endl;
    postorderRecursive(root);

    return 0;
}
