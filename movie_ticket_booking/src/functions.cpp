#include "movie_tickrt_booking.h"
int insert_to_list(User **user,string id,string name,string passwd)
{
    User *new_one,*temp;
    new_one=new User;
    if(new_one == NULL)
        cout << " malloc failed"<<endl;
    new_one->user_id=id;
    new_one->user_name=name;
    new_one->user_password=passwd;
    new_one->link=NULL;
    temp=*user;
    if(temp == NULL)
    {
        *user=new_one;
        return 0;
    }
    while(temp->link!= NULL)
    {
        temp=temp->link;
    }
    temp->link=new_one;
    return 0;
}
int insert_to_theature_list(Theatre **theatre,string id,string seats,string location,string movie)
{
    Theatre *new_one,*temp;
    new_one=new Theatre;
    if(new_one == NULL)
        cout << " malloc failed"<<endl;
    new_one->id=id;
    new_one->seats=seats;
    new_one->location=location;
    new_one->movie=movie;
    new_one->link=NULL;
    temp=*theatre;
    if(temp == NULL)
    {
        *theatre=new_one;
        return 0;
    }
    while(temp->link!= NULL)
    {
        temp=temp->link;
    }
    temp->link=new_one;

    return 0;
}

int display_list(User *user)
{
    if(user == NULL)
    {
        cout << "List empty" << endl;
        return 0;
    }
    while(user)
    {
        cout << user->user_id << endl;
        cout << user->user_name << endl;
        cout << user->user_password << endl;
        user=user->link;
    }
    return 0;
}
int display_list_theatre(Theatre *theatre)
{
    if(theatre == NULL)
    {
        cout << "List empty" << endl;
        return 0;
    }
    while(theatre)
    {
        cout << theatre->id << endl;
        cout << theatre->seats << endl;
        cout << theatre->location << endl;
        cout << theatre->movie<< endl;
        theatre=theatre->link;
    }
    return 0;
}
int display_movies(Theatre *theatre)
{
    if(theatre == NULL)
    {
        cout << "List empty" << endl;
        return 0;
    }
    while(theatre)
    {
        cout <<"-->> "<< theatre->movie<< endl;
        theatre=theatre->link;
    }
    return 0;

}
int find_id(User *user, string name)
{
    while(user)
    {
        if(user->user_name == name)
            return FOUND;
        user=user->link;
    }
    return 0;
}
int find_theatre(Theatre *theatre, string movie)
{
    while(theatre)
    {
        if(theatre->movie == movie)
            return FOUND;
        theatre=theatre->link;
    }
    return 0;
}
int find_id_password(User *user,string passwd,string name)
{
    while(user)
    {
        if(user->user_name == name)
        {
            if(user->user_password == passwd)
            {
                return FOUND;
            }
        }
        user=user->link;
    }
    return 0;
}
int update_user_data_base(User **user)
{
    FILE *fptr = fopen("user_info.txt","r");
    char id[20];
    char name[20];
    char password[20];
    while(fscanf(fptr,"%s %s %s",id,name,password) != EOF)
    {
        insert_to_list(user,id,name,password);
    }
    fclose(fptr);
    return 0;
}
int update_theatre_data_base(Theatre **theatre)
{
    FILE *fpt = fopen("theatre_data.txt","r");
    char id[10];
    char seats[10];
    char location[10];
    char movie[30];
    while(fscanf(fpt,"%s %s %s %s",id,seats,location,movie) != EOF)
    {
        insert_to_theature_list(theatre,id,seats,location,movie);
    }
    fclose(fpt);
    return 0;
}
int add_user_to_database(User **user,string id,string name,string password)
{
    char id_[10]= {'\0'};
    char name_[20]= {'\0'};
    char password_[20]= {'\0'};
    for(int i=0; isalnum(id[i]); i++)
    {
        id_[i]=id[i];
    }
    for(int i=0; isalnum(name[i]); i++)
    {
        name_[i]=name[i];
    }
    for(int i=0; isalnum(password[i]); i++)
    {
        password_[i]=password[i];
    }
    FILE *fptr = fopen("user_info.txt","a");
    insert_to_list(user,id,name,password);
    fprintf(fptr,"%s %s %s\n",id_,name_,password_);
    fclose(fptr);
    return 0;
}
int add_movie_to_database(Theatre **theatre,string id,string location,string seats,string movie)
{
    char id_[10]= {'\0'};
    char location_[20]= {'\0'};
    char seats_[20]= {'\0'};
    char movie_[20]= {'\0'};
    for(int i=0; isalnum(id[i]); i++)
    {
        id_[i]=id[i];
    }
    for(int i=0; isalnum(location[i]); i++)
    {
        location_[i]=location[i];
    }
    for(int i=0; isalnum(seats[i]); i++)
    {
        seats_[i]=seats[i];
    }
    for(int i=0; isalnum(movie[i]); i++)
    {
        movie_[i]=movie[i];
    }
    FILE *fptr = fopen("theatre_data.txt","a");
    insert_to_theature_list(theatre,id,location,seats,movie);
    fprintf(fptr,"%s %s %s %s\n",id_,location_,seats_,movie_);
    fclose(fptr);
    return 0;
}
int login(User **user)
{
    string name,password;
    int tries=MAX_TRIES;

    cout << "Enter user name" << endl;
    cin >> name;
    while(FOUND != find_id(*user,name))
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
        if(FOUND == find_id_password(*user,password,name))
        {
            system("cls");
            cout << setw(70)<< "login successful\n" << endl;
            cout << setw(60)<<"Hello! " << name << "\n" << endl;
            return SUCCESSFULL;
        }
        if(tries==0)
        {
            cout << "Login failed"<<endl;
            cout<<"wait for 10 seconds"<< endl;
            for(int i=1; i<=10; i++)
            {
                Sleep(1000);
            }
            tries=3;
            continue;
        }
        else
            cout << "!!wrong password "<< tries << try_ <<endl;

    }
    return FAILED;
}
int signup(User **user)
{

    string name_,id_,password_;

    cout <<"Enter new user name"<< endl;
    cin>>name_;
    if(FOUND == find_id(*user,name_))
    {
        cout << "Username already exists" << endl;
        return FAILED;
    }
    cout <<"Enter new user ID"<< endl;
    cin>>id_;
    cout <<"Enter new user password"<< endl;
    cin>>password_;

    add_user_to_database(user,id_,name_,password_);
    return SUCCESSFULL;
}
int add_theatre(Theatre **theatre)
{

    string id_,location_,seats_,movie_;

    cout <<"Enter movie name"<< endl;
    cin>>movie_;
    if(FOUND == find_theatre(*theatre,movie_))
    {
        cout << "Theatre already exists" << endl;
        return FAILED;
    }
    cout <<"Enter new  ID"<< endl;
    cin>>id_;
    cout <<"Enter new  location"<< endl;
    cin>>location_;
    cout <<"Enter no of  seats"<< endl;
    cin>>seats_;

    add_movie_to_database(theatre,id_,location_,seats_,movie_);
    return SUCCESSFULL;
}
void display_menu()
{
    cout << setw(62)<< "MENU" << endl;
    cout << setw(70)<< "1. Book movie ticket" << endl;
    cout << setw(66)<< "2. Browse movies" << endl;
    cout << setw(67)<< "3. Cancel booking" << endl;
    cout << setw(59)<< "4. Logout" << endl;
    cout << setw(60)<< "5. Signout" << endl;
    cout << setw(57)<< "6. exit" << endl;
}
int admin_login(void)
{
    string name,password;
    cout<< "Enter admin name"<<endl;
    cin >> name;
    cout<< "Enter admin password"<<endl;
    cin >> password;
    if(name == ADMIN_NAME)
    {
        if(password == ADMIN_PASSWORD)
        {
            system("cls");
            cout << setw(70)<< "Admin login successful\n" << endl;
            cout << setw(59)<<"Hello Admin! " << name << "\n" << endl;
            return SUCCESSFULL;
        }
    }
    return FAILED;
}
void display_admin_menu()
{
    cout << setw(57)<< "MENU" << endl;
    cout << setw(63)<< "1. ADD theatre" << endl;
    cout << setw(66)<< "2. Delete theatre" << endl;
    cout << setw(63)<< "3. Remove user" << endl;
    cout << setw(59)<< "4. Signout" << endl;
    cout << setw(56)<< "5. exit" << endl;
}
int search_movie(Theatre *theatre,string movie)
{
    if(theatre == NULL)
    {
        cout << "List empty" << endl;
        return 0;
    }
    while(theatre)
    {
        if(theatre->movie == movie)
            return SUCCESSFULL;
        theatre=theatre->link;
    }
    return FAILED;

}
int search_seats(Theatre *theatre,int  seats,string movie)
{
    if(theatre == NULL)
    {
        cout << "List empty" << endl;
        return 0;
    }
    while(theatre)
    {
        if(theatre->movie == movie)
        {
            stringstream geek(theatre->seats);
            int x = 0;
            geek >> x;
            if( x >= seats)
            return SUCCESSFULL;
        }
        theatre=theatre->link;
    }
    return FAILED;

}
int book_movie_ticket(Theatre **theatre,string movie)
{
    int no_seats;
    if(search_movie(*theatre,movie) == FAILED)
    {
        cout<< "No such movies found"<<endl;
        return FAILED;
    }
    cout<<"Enter the number of seats to book"<< endl;
    cin>>no_seats;
    if(search_seats(*theatre,no_seats,movie) == FAILED)
    {
        cout<< "Sorry House full"<<endl;
        return FAILED;
    }
    return SUCCESSFULL;
}
