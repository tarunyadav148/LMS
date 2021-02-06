#include"college.h"
#include<iostream>

college::college()
{
    check_first_time=false;
    college_name="null";
    password="null";
}

bool college::check_status()
{
    return check_first_time;
}

void college::input()
{
    check_first_time=true;
    std::cout<<"Enter name of college:";
    std::cin>>college_name;
    std::cout<<"Enter password:";
    std::cin>>password;
    std::string temp_pass;
    std::cout<<"Enter password again:";
    std::cin>>temp_pass;
    while (password!=temp_pass)
    {
        std::cout<<"Please re-enter password as both not macthed\n";
        std::cout<<"Enter password:";
        std::cin>>password;
        std::cout<<"Enter passord again:";
        std::cin>>temp_pass;
    }
    
}

std::string college::get_name()
{
    return college_name;
}

std::string college::get_password()
{
    return password;
}