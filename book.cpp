#include"book.h"
#include<iostream>
#include<string>
using namespace std;



book::book()
{
    sno=0;
    bname="Not available";
    issue='N';
}

void book::binput()
{
    cout<<"Enter book sno.:";
    cin>>sno;
    cout<<"Enter book name:";
    getline(cin,bname);
}

void book::getreceive(int addmno)
{
    receive=addmno;
}

int book::putreceive()
{
    return receive;
}

void book::bdisplay()
{
    cout<<"---Details of book---"<<endl;
    cout<<"Name:"<<bname<<endl;
    cout<<"S.No.:"<<sno<<endl;
    cout<<"ISSUE:"<<issue<<endl;
}

void book::getissue(char c)
{
    issue=c;
}

char book::putissue()
{
    return issue;
}

int book::getsno()
{
    return sno;
}

