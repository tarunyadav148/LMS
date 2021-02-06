#include"book.h"
#include<iostream>
#include<string>
#include<ios>
#include<limits>



book::book()
{
    sno=0;
    bname="Not available";
    issue='N';
}

void book::binput()
{
    std::cout<<"Enter book sno.:";
    std::cin>>sno;
    std::cout<<"Enter book name:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin,bname);
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
    std::cout<<"---Details of book---"<<std::endl;
    std::cout<<"Name:"<<bname<<std::endl;
    std::cout<<"S.No.:"<<sno<<std::endl;
    std::cout<<"ISSUE:"<<issue<<std::endl;
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

