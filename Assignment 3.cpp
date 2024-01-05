#include <iostream>
#include<stdlib.h>
using namespace std;
struct Student
{
    int rollno;
    char name[20];
    float sgpa;

};
void insertion(Student arr[],int data)
{
    for(int i=1;i<data;i++)
    {
        Student current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j].sgpa > current.sgpa)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
int binary(Student arr[],int data,int key)
{
    int s=0;
    int e=data;

    while(s<=e)
    {
        int mid=(s+e)/2;

        if(arr[mid].sgpa == key)
        {
            return mid;
        }
        else if(arr[mid].sgpa > key)
        {
            e=mid-1;
        }
        else
        {
            e=mid+1;
        }
    }
    return -1;
}
int main()
{
    system ("cls");
    int size= 3;
    Student student[size];
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the data of student"<<endl;
        cout<<"Enter the Roll no. of student"<<endl;
        cin>>student[i].rollno;
        cout<<"Enter the Name of student"<<endl;
        cin>>student[i].name;
        cout<<"Enter the SGPA of student"<<endl;
        cin>>student[i].sgpa;
    }
    char choice;
    do
    {
        cout<<"********MENU*********"<<endl;
        cout<<"a.Insertion sorting"<<endl;
        cout<<"b.Binary search"<<endl;
        cout<<"c.EXIT"<<endl;
        cout<<"Enter the choice;"<<endl;
        cin>>choice;
        switch(choice)
        {
        case'a':
            {
                insertion(student,size);
                for(int i=0; i<size; i++)
            {
                cout<<"\nRoll No:"<<student[i].rollno
                    <<"\nName:"<<student[i].name
                    <<"\nSGPA:"<<student[i].sgpa;
            }
        }
        break;
        case 'b':
        {
            float searchkey;
            cout<<"Enter the search key"<<endl;
            cin>>searchkey;
            int result=binary(student,size,searchkey);
            if(result != -1)
            {
                cout<<"\nRoll No:"<<student[result].rollno
                    <<"\nName:"<<student[result].name
                    <<"\nSGPA:"<<student[result].sgpa;
            }
            else
            {
                cout<<"Student data of Search key:"<<searchkey<<"Is not found"<<endl;
            }

        }
        break;
        case 'c':
        {
            cout<<"EXIT"<<endl;
        }
        break;

        }
        cout<<"Do you want to continue"<<endl;
        cin>>choice;
    }while(choice == 'Y' || choice == 'y');
return 0;
}
