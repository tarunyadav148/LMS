#ifndef BOOK_H
#define BOOK_H

#include<string>

class book{
    int sno;
    std::string bname;
    char issue;
    int receive;
    public:
    book();
    void binput();
    void getreceive(int addmno);
    int putreceive();
    void bdisplay();
    void getissue(char c);
    char putissue();
    int getsno();
};

#endif