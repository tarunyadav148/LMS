#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class book{
int sno;
string bname;
char issue;
int receive;
public:
book()
{
sno=0;
bname="Not available";
issue='N';
}
void binput()
{
cout<<"Enter book sno.:";
cin>>sno;
cout<<"Enter book name:";
getline(cin,bname);
}
void getreceive(int addmno)
{
receive=addmno;
}
int putreceive()
{
return receive;
}
void bdisplay()
{
cout<<"---Details of book---"<<endl;
cout<<"Name:"<<bname<<endl;
cout<<"S.No.:"<<sno<<endl;
cout<<"ISSUE:"<<issue<<endl;
}
void getissue(char c)
{
issue=c;
}
char putissue()
{
return issue;
}
int getsno()
{
return sno;
}
};

