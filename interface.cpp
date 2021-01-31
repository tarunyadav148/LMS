#include<iostream>
#include"methods.h"
using namespace std;

void interface()
{
system("cls");
cout<<"\t\tLibrary Management System"<<endl;
cout<<"\t\tKendriya Vidyalaya Aliganj Lucknow"<<endl;
int choice;
cout<<"Enter your choice"<<endl;
cout<<"1:Enter Student data"<<endl;
cout<<"2:Enter Book data"<<endl;
cout<<"3:Issue a book"<<endl;
cout<<"4:Return a book"<<endl;
cout<<"5:Status of a book"<<endl;
cout<<"6:Status of student"<<endl;
cout<<"7:Upadate Student data"<<endl;
cout<<"8:Upate Book data"<<endl;
cout<<"0:Exit"<<endl;
cin>>choice;
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
default:cout<<"Please enter mention value only"<<endl;
}
}