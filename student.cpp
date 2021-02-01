#include"student.h"
#include<iostream>
#include<string>
#include<ios>
#include<limits>
using namespace std;


void student::sinput()
{
    cout<<"Enter Addmission No.:";
    cin>>addmno;
    cout<<"Enter Name of student:";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,sname);
    cout<<"Enter class of student:";
    cin>>Class;
    cout<<"Enter section of student:";
    cin>>sec;
    cout<<"Enter Roll of student:";
    cin>>rno;
}

void student::sdisplay()
{
    cout<<"Name:"<<sname<<endl;
    cout<<"Class:"<<Class<<endl;
    cout<<"Section:"<<sec<<endl;
    cout<<"Addmission Number:"<<addmno<<endl;
    cout<<"Roll Number:"<<rno<<endl;
}

int student::getaddmno()
{
    return addmno;
}
