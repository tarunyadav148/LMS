#include"interface.h"
#include"student.h"
#include"book.h"
#include<iostream>
#include<fstream>
#include<string>

void sgetdata()
{
    std::fstream fout;
    student s;
    s.sinput();
    fout.open("Student.dat",std::ios::binary|std::ios::app);
    fout.write((char*)&s,sizeof(s));
    fout.close();
    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0){
        interface();
    }
    else{
        sgetdata();
    }
}

void bgetdata()
{
    std::fstream fout;
    book b;
    b.binput();
    fout.open("Book.dat",std::ios::binary|std::ios::app);
    fout.write((char*)&b,sizeof(b));
    std::cout<<"Book is register"<<std::endl;
    fout.close();
    fout.close();
    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0){
        interface();
    }
    else{
        bgetdata();
    }
}

void bookissue()
{
    int n1,n2;
    student s;
    book b;
    std::cout<<"Enter Student Addmission No.:"<<std::endl;
    std::cin>>n1;
    cout<<"Enter Serial NO. of Book:"<<endl;
    cin>>n2;
    std::fstream fin,fout;
    fin.open("Book.dat",std::ios::binary|std::ios::in|std::ios::out);
    fin.read((char*)&b,sizeof(b));

    while(b.getsno()!=n2)
    {
        fin.read((char*)&b,sizeof(b));
        }
        b.getreceive(n1);
        b.getissue('Y');
        b.bdisplay();
        fin.seekg(-(int)sizeof(b),std::ios::cur);;
        fin.write((char*)&b,sizeof(b));
        cout<<"Book is issued to student:"<<endl;
        fout.open("Student.dat",std::ios::binary|std::ios::in);
        fout.read((char*)&s,sizeof(s));

        while(fout)
        {
            if(s.getaddmno()==n1){
                s.sdisplay();
            }
            fout.read((char*)&s,sizeof(s));
        }

        fout.close();
        fin.close();
        int back;
        std::cout<<"1:Continue"<<std::endl;
        std::cout<<"0:Back to main menu";
        std::cin>>back;
        if(back==0){
            interface();
        }
        else{
            bookissue();
        }
}


void bookreturn()
{
    int n;
    book b;
    std::cout<<"Enter Serial No. of book:"<<std::endl;
    std::cin>>n;
    std::fstream fout;
    fout.open("Book.dat",std::ios::binary|std::ios::out|std::ios::in);
    fout.read((char*)&b,sizeof(b));

    while(b.getsno()!=n)
    {
        fout.read((char*)&b,sizeof(b));
    }

    b.getreceive(0);
    b.getissue('N');
    fout.seekg(-(int)sizeof(b),std::ios::cur);
    fout.write((char*)&b,sizeof(b));
    std::cout<<"Book is returned"<<std::endl;
    fout.close();

    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    cin>>back;
    if(back==0){
        interface();
    }
    else{
        bookreturn();
    }
}


void sstatus()
{
    int addmno;
    std::cout<<"Enter the addmission No. of student:"<<std::endl;
    std::cin>>addmno;
    book b;
    student s;
    std::fstream fout;
    fout.open("Student.dat",std::ios::binary|std::ios::in);
    fout.read((char*)&s,sizeof(s));

    while(s.getaddmno()!=addmno)
    {
        fout.read((char*)&s,sizeof(s));
    }

    s.sdisplay();
    fout.close();
    cout<<"Details of book issued:"<<endl;
    std::fstream fin;
    fin.open("Book.dat",std::ios::binary|std::ios::in);
    fin.read((char*)&b,sizeof(b));

    while(fin)
    {
        if(b.putreceive()==addmno){
            b.bdisplay();
        }

        fin.read((char*)&b,sizeof(b));
    }

    fin.close();
    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0){
        interface();
    }
    else{
        sstatus();
    }
}


void bstatus()
{
    int sno;
    std::cout<<"Enter serial No.:";
    std::cin>>sno;
    book b;
    student s;
    std::fstream fin;
    fin.open("Book.dat",std::ios::binary|std::ios::in);
    fin.read((char*)&b,sizeof(b));

    while(b.getsno()!=sno)
    {
        fin.read((char*)&b,sizeof(b));
    }

    b.bdisplay();
    cout<<"The book is issued to:"<<std::endl;
    fin.close();
    fin.open("Student.dat",std::ios::binary|std::ios::in);
    fin.read((char*)&s,sizeof(s));

    while(fin)
    {
        if(s.getaddmno()==b.putreceive()){
            s.sdisplay();
            break;
        }
        fin.read((char*)&s,sizeof(s));
    }
    fin.close();

    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0){
        interface();
    }
    else{
        bstatus();
    }
}

void updatestudent()
{
    std::cout<<"Enter the Addmission No.:"<<std::endl;
    int n;
    std::cin>>n;
    student s1,s2;
    book b;
    s1.sinput();
    std::fstream fout;
    fout.open("Student.dat",std::ios::binary|std::ios::out|std::ios::in);
    fout.read((char*)&s2,sizeof(s2));

    while(s2.getaddmno()!=n)
    {
        fout.read((char*)&s2,sizeof(s2));
    }

    fout.seekg(-(int)sizeof(s2),std::ios::cur);
    fout.write((char*)&s1,sizeof(s1));
    fout.close();
    fout.open("Book.dat",std::ios::binary|std::ios::out|std::ios::in);
    fout.read((char*)&b,sizeof(b));

    while(b.putreceive()!=s2.getaddmno())
    {
        fout.read((char*)&b,sizeof(b));
    }

    b.getreceive(s1.getaddmno());
    fout.seekg(-(int)sizeof(b));
    fout.write((char*)&b,sizeof(b));

    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0){
        interface();
    }
    else{
        updatestudent();
    }
}

void updatebook()
{
    std::cout<<"Enter the Serial No.:"<<std::endl;
    int n;
    std::cin>>n;
    book b1,b2;
    b1.binput();
    std::fstream fin;
    fin.open("Book.dat",std::ios::binary|std::ios::in|std::ios::out);
    fin.read((char*)&b2,sizeof(b2));

    while(b2.getsno()!=n)
    {
        fin.read((char*)&b2,sizeof(b2));
    }
    b1.getreceive(b2.putreceive());
    b1.getissue(b2.putissue());
    fin.seekg(-(int)sizeof(b2),std::ios::cur);
    fin.write((char*)&b1,sizeof(b1));
    fin.close();

    int back;
    std::cout<<"1:Continue"<<std::endl;
    std::cout<<"0:Back to main menu";
    std::cin>>back;
    if(back==0)
    {
    interface();
    }
    else{
        updatebook();
    }
}
