#include"college.h"
#include"interface.h"
#include<fstream>
#include<iostream>

void first_time()
{
    std::fstream fobj;
    college col;
    std::string temp_pass;
    fobj.open("College.dat",std::ios::in);
    fobj.read((char*)&col,1*sizeof(col));
    if(!col.check_status()){
        col.input();
        fobj.close();
        fobj.open("College.dat",std::ios::out);
        fobj.write((char*)&col,sizeof(col));
        interface();
    }else{
        std::cout<<col.get_name();
        std::cout<<"\nEnter password:";
        std::cin>>temp_pass;
        while(temp_pass!=(col.get_password()))
        {
            std::cout<<"Wrong password"<<std::endl;
            std::cout<<"Please enter again"<<std::endl;
            std::cout<<"\nEnter password:";
            std::cin>>temp_pass;
        }

        interface();

    }
} 