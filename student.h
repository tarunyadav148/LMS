#include<iostream>
#include<string>
using namespace std;

class student
{
int addmno;
string sname;
int Class;
char sec;
int rno;
public:
void sinput()
{
cout<<"Enter Addmission No.:";
cin>>addmno;
cout<<"Enter Name of student:";
getline(cin,sname);
cout<<"Enter class of student:";
cin>>Class;
cout<<"Enter section of student:";
cin>>sec;
cout<<"Enter Roll of student:";
cin>>rno;
}
void sdisplay()
{
cout<<"Name:"<<sname<<endl;
cout<<"Class:"<<Class<<endl;
cout<<"Section:"<<sec<<endl;
cout<<"Addmission Number:"<<addmno<<endl;
cout<<"Roll Number:"<<rno<<endl;
}
int getaddmno()
{
return addmno;
}
};