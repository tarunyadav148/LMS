#include"student.h"
#include<iostream>
#include<string>
#include<ios>
#include<limits>


void student::sinput()
{
    std::cout<<"Enter Addmission No.:";
    std::cin>>addmno;
    std::cout<<"Enter Name of student:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin,sname);
    std::cout<<"Enter class of student:";
    std::cin>>Class;
    std::cout<<"Enter section of student:";
    std::cin>>sec;
    std::cout<<"Enter Roll of student:";
    std::cin>>rno;
}

void student::sdisplay()
{
    std::cout<<"Name:"<<sname<<std::endl;
    std::cout<<"Class:"<<Class<<std::endl;
    std::cout<<"Section:"<<sec<<std::endl;
    std::cout<<"Addmission Number:"<<addmno<<std::endl;
    std::cout<<"Roll Number:"<<rno<<std::endl;
}

int student::getaddmno()
{
    return addmno;
}
