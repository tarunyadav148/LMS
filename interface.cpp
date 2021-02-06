#include"methods.h"
#include<iostream>

void interface()
{
    if(system("clear")) system("cls");

    std::cout<<"\t\tLibrary Management System"<<std::endl;
    
    int choice;

    std::cout<<"Enter your choice"<<std::endl;
    std::cout<<"1:Enter Student data"<<std::endl;
    std::cout<<"2:Enter Book data"<<std::endl;
    std::cout<<"3:Issue a book"<<std::endl;
    std::cout<<"4:Return a book"<<std::endl;
    std::cout<<"5:Status of a book"<<std::endl;
    std::cout<<"6:Status of student"<<std::endl;
    std::cout<<"7:Upadate Student data"<<std::endl;
    std::cout<<"8:Upate Book data"<<std::endl;
    std::cout<<"0:Exit"<<std::endl;

    std::cin>>choice;

    switch(choice)
    {
        case 0:
        exit(0);
        break;
        case 1:
        sgetdata();
        break;
        case 2:
        bgetdata();
        break;
        case 3:
        bookissue();
        break;
        case 4:
        bookreturn();
        break;
        case 5:
        bstatus();
        break;
        case 6:
        sstatus();
        break;
        case 7:
        updatestudent();
        break;
        case 8:
        updatebook();
        break;
        default:std::cout<<"Please enter mention value only"<<std::endl;
    }
}