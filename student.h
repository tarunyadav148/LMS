#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class student
{
    int addmno;
    std::string sname;
    int Class;
    char sec;
    int rno;
    
    public:
    void sinput();
    void sdisplay();
    int getaddmno();
};

#endif