#include "movie_tickrt_booking.h"
#include "user.h"

//code starts from here
int main()
{
    User *user=NULL;
    int choice;
    char option;
    int tries=MAX_TRIES;
    string id,name,password;
    update_data_base(&user);
    cout << "   Welcome to login screen"<< endl;
    cout << "Do you want to login or signup" <<endl;
    do
    {

        cout << "1.Login"<<endl;
        cout << "2.signup"<<endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            cout << "Enter user name" << endl;
            cin >> name;
            while(FOUND != find_id(user,name))
            {
                cout << "wrong id"<<endl;
                cout << "Enter user name" << endl;
                cin >> name;
            }
            while(tries--)
            {
                string try_=(tries != 1)? " tries left":" try left";
                cout << "Enter password" << endl;
                cin >> password;
                if(FOUND == find_id_password(user,password,name))
                {
                    system("cls");
                    cout << "login successful\n" << endl;
                    cout << "Hello! " << name << endl;
                    break;
                }
                if(tries==0)
                {
                    cout << "Login failed"<<endl;
                    cout<<"wait for 10 seconds"<< endl;
                    for(int i=1;i<=10;i++)
                    {
                        Sleep(1000);
                    }
                    tries=3;
                    continue;
                }
                else
                    cout << "!!wrong password "<< tries << try_ <<endl;

            }
            break;
        }
        case 2:
        {
            string name_,id_,password_;
            cout <<"Enter new user name"<< endl;
            cin>>name_;
            if(FOUND == find_id(user,name_))
                {
                    cout << "Username already exists" << endl;
                    break;
                }

            cout <<"Enter new user ID"<< endl;
            cin>>id_;
            cout <<"Enter new user password"<< endl;
            cin>>password_;

            add_user_to_database(&user,id_,name_,password_);
            break;
        }
        default:
            cout << "wrong choice" << endl;
        }
        cout << "do you want to continue?(y/n)"<< endl;
        cin >> option;
    }
    while(option == 'y' || option == 'Y');

    return 0;
}
