#include "movie_tickrt_booking.h"

int main()
{
    User *user=NULL;
    int choice;
    int choice_;
    char option;
    update_data_base(&user);
    system("Color 70");
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
            if(login(&user) == FAILED)
            {
                cout << "\nLogin error\n" << endl;
                break;
            }
            display_menu();
            cout << "Enter your choice" << endl;
            cin >> choice_;
            switch(choice_)
            {
            case 1:
            {
                //booking function
                break;
            }
            case 2:
            {
                //browse movie function
                break;
            }
            case 3:
            {
                //cancel booking function
                break;
            }
            case 4:
            {
                //logout function
                break;
            }
            case 5:
            {
                //sign-out function
                break;
            }
            case 6:
            {
                //exit
                break;
            }
            }
            break;
        }
        case 2:
        {
            if(signup(&user) == FAILED)
            {
                cout << "\nsignup error\n" << endl;
            }
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
