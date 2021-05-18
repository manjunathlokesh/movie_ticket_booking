#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;
class user
{
    private:
        int user_id;
        string user_name;
        string user_password;
    public:
        int register_user(int id,string name,string password)
        {
            user_id=id;
            user_name=name;
            user_password=password;
            return 0;
        }
        void show_details()
        {
            cout << user_id << " " << user_name<< " h" << user_password << endl;
        }
        user();
        virtual ~user();
};

#endif // USER_H
