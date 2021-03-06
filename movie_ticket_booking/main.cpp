#include "movie_tickrt_booking.h"
int main()
{
    User *user=NULL;
    Theatre *theatre=NULL;
    int choice;
    int choice_;
    char option;
    update_user_data_base(&user);
    update_theatre_data_base(&theatre);
    do
    {
        system("cls");
        system("Color 70");
        cout << "   Welcome to login screen"<< endl;
        cout << "Do you want to login or signup" <<endl;
        cout << "1.Login"<<endl;
        cout << "2.signup"<<endl;
        cout << "3.admin login"<< endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            if(login(&user) == FAILED_)
            {
                cout << "\nLogin error\n" << endl;
                break;
            }
user_menu:
            display_menu();
            cout << "Enter your choice" << endl;
            cin >> choice_;
            switch(choice_)
            {
            case 1:
            {
                //booking function
                system("cls");
                string movie;
                cout<< "Enter the movie to book ticket"<< endl;
                cin >> movie;
                if(book_movie_ticket(user,&theatre,movie) == FAILED_)
                {
                    cout<<"Booking FAILED"<<endl;
                }
                system("cls");
                goto user_menu;
                break;
            }
            case 2:
            {
                system("cls");
                cout<< "Available movies\n"<<endl;
                display_movies(theatre);
                break;
            }
            case 3:
            {
                //cancel booking function
                break;
            }
            case 4:
            {
                system("cls");
                goto EXIT;
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
                system("cls");
                goto EXIT;
                break;
            }
            }
            break;
        }
        case 2:
        {
            if(signup(&user) == FAILED_)
            {
                cout << "\nsignup error\n" << endl;
            }
            break;
        }
        case 3:
        {

            if(admin_login() == FAILED_)
            {
                cout << "\nLogin error\n" << endl;
                break;
            }
            display_admin_menu();
            cout << "Enter your choice" << endl;
            cin >> choice_;
            switch(choice_)
            {
            case 1:
            {

                system("cls");
                add_theatre(&theatre);
                break;
            }
            case 2:
            {
                system("cls");
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
            }
            break;

        }
        default:
            cout << "wrong choice" << endl;
        }
EXIT:
        cout << "do you want to continue?(y/n)"<< endl;
        cin >> option;
    }
    while(option == 'y' || option == 'Y');
    return 0;
}
