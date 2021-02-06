#ifndef COLLEGE_H
#define COLLEGE_H

#include<string>

class college{
    bool check_first_time;
    std::string college_name;
    std::string password;
    public:
    college();
    void input();
    bool check_status();
    std::string get_name();
    std::string get_password();
};

#endif