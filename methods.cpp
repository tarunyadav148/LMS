#include<iostream>
#include<fstream>
#include<string>
#include"interface.h"
#include"student.h"
#include"book.h"
using namespace std;

void sgetdata()
{
    fstream fout;
    student s;
    s.sinput();
    fout.open("Student.dat",ios::binary|ios::app);
    fout.write((char*)&s,sizeof(s));
    fout.close();
    int back;
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
    if(back==0){
        interface();
    }
    else{
        sgetdata();
    }
}

void bgetdata()
{
    fstream fout;
    book b;
    b.binput();
    fout.open("Book.dat",ios::binary|ios::app);
    fout.write((char*)&b,sizeof(b));
    cout<<"Book is register"<<endl;
    fout.close();
    fout.close();
    int back;
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
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
    cout<<"Enter Student Addmission No.:"<<endl;
    cin>>n1;
    cout<<"Enter Serial NO. of Book:"<<endl;
    cin>>n2;
    fstream fin,fout;
    fin.open("Book.dat",ios::binary|ios::in|ios::out);
    fin.read((char*)&b,sizeof(b));

    while(b.getsno()!=n2)
    {
        fin.read((char*)&b,sizeof(b));
        }
        b.getreceive(n1);
        b.getissue('Y');
        b.bdisplay();
        fin.seekg(-(int)sizeof(b),ios::cur);;
        fin.write((char*)&b,sizeof(b));
        cout<<"Book is issued to student:"<<endl;
        fout.open("Student.dat",ios::binary|ios::in);
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
        cout<<"1:Continue"<<endl;
        cout<<"0:Back to main menu";
        cin>>back;
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
    cout<<"Enter Serial No. of book:"<<endl;
    cin>>n;
    fstream fout;
    fout.open("Book.dat",ios::binary|ios::out|ios::in);
    fout.read((char*)&b,sizeof(b));

    while(b.getsno()!=n)
    {
        fout.read((char*)&b,sizeof(b));
    }

    b.getreceive(0);
    b.getissue('N');
    fout.seekg(-(int)sizeof(b),ios::cur);
    fout.write((char*)&b,sizeof(b));
    cout<<"Book is returned"<<endl;
    fout.close();

    int back;
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
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
    cout<<"Enter the addmission No. of student:"<<endl;
    cin>>addmno;
    book b;
    student s;
    fstream fout;
    fout.open("Student.dat",ios::binary|ios::in);
    fout.read((char*)&s,sizeof(s));

    while(s.getaddmno()!=addmno)
    {
        fout.read((char*)&s,sizeof(s));
    }

    s.sdisplay();
    fout.close();
    cout<<"Details of book issued:"<<endl;
    fstream fin;
    fin.open("Book.dat",ios::binary|ios::in);
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
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
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
    cout<<"Enter serial No.:";
    cin>>sno;
    book b;
    student s;
    fstream fin;
    fin.open("Book.dat",ios::binary|ios::in);
    fin.read((char*)&b,sizeof(b));

    while(b.getsno()!=sno)
    {
        fin.read((char*)&b,sizeof(b));
    }

    b.bdisplay();
    cout<<"The book is issued to:"<<endl;
    fin.close();
    fin.open("Student.dat",ios::binary|ios::in);
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
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
    if(back==0){
        interface();
    }
    else{
        bstatus();
    }
}

void updatestudent()
{
    cout<<"Enter the Addmission No.:"<<endl;
    int n;
    cin>>n;
    student s1,s2;
    book b;
    s1.sinput();
    fstream fout;
    fout.open("Student.dat",ios::binary|ios::out|ios::in);
    fout.read((char*)&s2,sizeof(s2));

    while(s2.getaddmno()!=n)
    {
        fout.read((char*)&s2,sizeof(s2));
    }

    fout.seekg(-(int)sizeof(s2),ios::cur);
    fout.write((char*)&s1,sizeof(s1));
    fout.close();
    fout.open("Book.dat",ios::binary|ios::out|ios::in);
    fout.read((char*)&b,sizeof(b));

    while(b.putreceive()!=s2.getaddmno())
    {
        fout.read((char*)&b,sizeof(b));
    }

    b.getreceive(s1.getaddmno());
    fout.seekg(-(int)sizeof(b));
    fout.write((char*)&b,sizeof(b));

    int back;
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
    if(back==0){
        interface();
    }
    else{
        updatestudent();
    }
}

void updatebook()
{
    cout<<"Enter the Serial No.:"<<endl;
    int n;
    cin>>n;
    book b1,b2;
    b1.binput();
    fstream fin;
    fin.open("Book.dat",ios::binary|ios::in|ios::out);
    fin.read((char*)&b2,sizeof(b2));

    while(b2.getsno()!=n)
    {
        fin.read((char*)&b2,sizeof(b2));
    }
    b1.getreceive(b2.putreceive());
    b1.getissue(b2.putissue());
    fin.seekg(-(int)sizeof(b2),ios::cur);
    fin.write((char*)&b1,sizeof(b1));
    fin.close();

    int back;
    cout<<"1:Continue"<<endl;
    cout<<"0:Back to main menu";
    cin>>back;
    if(back==0)
    {
    interface();
    }
    else{
        updatebook();
    }
}
