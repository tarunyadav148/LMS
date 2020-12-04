//Student header file
struct student
    {
        long rollno;
        char name[30];
        char fathers_name[30];

        struct DOB
        {
        int dd;
        int mm;
        int yyyy;
        }dob;

        char branch[5];
        char sec;
        int sub_sec;
    };