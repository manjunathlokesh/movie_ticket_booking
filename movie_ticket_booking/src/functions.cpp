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
int update_data_base(User **user)
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
int add_user_to_database(User **user,string id,string name,string password)
{
    char id_[10]={'\0'};
    char name_[20]={'\0'};
    char password_[20]={'\0'};
    for(int i=0;isalnum(id[i]);i++)
    {
        id_[i]=id[i];
    }
    for(int i=0;isalnum(name[i]);i++)
    {
        name_[i]=name[i];
    }
    for(int i=0;isalnum(password[i]);i++)
    {
        password_[i]=password[i];
    }
    FILE *fptr = fopen("user_info.txt","a");
    insert_to_list(user,id,name,password);
    fprintf(fptr,"%s %s %s\n",id_,name_,password_);
    fclose(fptr);
    return 0;
}
