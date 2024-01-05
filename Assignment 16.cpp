#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};
Node*create(int value)
{
    Node*newNode=new Node;
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

Node*insert(Node*root,int value)
{
    if(root == NULL)
    {
        root = create(value);
    }
    else if(value <= root->data)
    {
        root->left = insert(root->left,value);
    }
    else
    {
        root->right = insert(root->right,value);
    }
return root;
}
bool search(Node*root,int value)
{
    if(root == NULL)return false;
    else if(root->data == value)return true;
    else if(value <= root->data)return search(root->left,value);
    else return search(root->right,value);
}
Node* findmin(Node*root)
{
    while(root->left != NULL)
    {
        root = root -> left;
    }
    return root;
}
Node*Delete(Node*root , int value)
{
    if (root == NULL)
        return root;
    else if(value < root->data)
        root->left = Delete(root->left,value);
    else if(value > root->data)
        root->right = Delete(root->right,value);
    else
    {
        //No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //One child
        else if(root->left == NULL)
        {
            Node*temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node*temp = root;
            root = root->left;
            delete temp;
        }
        //two child
        else{
            Node*temp = findmin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }return root;
}
void inorderTraversal(Node*root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}
int main()
{
    int value;
    char choice;
    Node*root=NULL;

    do{
    cout<<"Enter the element to insert"<<endl;
    cin>>value;
    root = insert (root,value);

    cout<<"Do you want to Continue(Y||N)"<<endl;
    cin>>choice;
    }while(choice == 'Y' || choice == 'y');

    do
    {
        cout<<"a.Insert Elements"<<endl;
        cout<<"b.Search Elements"<<endl;
        cout<<"c.Delete Elements"<<endl;
        cout<<"d.In-order Traversal"<<endl;
        cout<<"Enter Your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 'a':
            {
            cout<<"Enter the value of elements"<<endl;
            cin>>value;
            root = insert (root,value);
            }
            break;
        case 'b':
            {
            cout<<"Enter the value to be search"<<endl;
            cin>>value;
            if(search(root,value) == true)
            {
                cout<<"Element Found"<<endl;
            }
            else cout<<"Element not Found"<<endl;}
            break;
        case 'c':
            {
                cout<<"Enter the value to Delete"<<endl;
                cin>>value;
                root = Delete(root,value);
            }
            break;
        case 'd':
            {
                cout<<"Display BST : ";
                inorderTraversal(root);
            }
        default:
            break;
        }
      cout<<"Do you want to continue()"<<endl;
      cin>>choice;
    }
    while(choice == 'Y' || choice == 'y');
        return 0;
}
