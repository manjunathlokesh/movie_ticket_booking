#ifndef MOVIE_TICKRT_BOOKING_H_INCLUDED
#define MOVIE_TICKRT_BOOKING_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <ctype.h>
#include <errno.h>
#include <bits/stdc++.h>
#include <windows.h>
#define SUCCESSFULL 0
#define FAILED_ -1
#define FOUND 2
#define MAX_TRIES 3
#define ADMIN_NAME "imtheadmin"
#define ADMIN_PASSWORD "letmein"
#define ADMIN_EMAIL "manjunath.lokesh12@gmail.com"
using namespace std;
typedef struct user_data{

    string user_id;
    string user_name;
    string user_password;
    struct user_data *link;
}User;

typedef struct theatre_data{

    string  id;
    string  location;
    string  seats;
    string  movie;
    struct theatre_data *link;
}Theatre;
int insert_to_list(User **user,string word,string word1,string word2);
int insert_to_theature_list(Theatre **theatre,string id,string seats,string location,string  movie);
int display_list(User *user);
int display_list_theatre(Theatre *user);
int display_movies(Theatre *theatre);
int find_id(User *user,string id);
int find_theatre(Theatre *theatre, string movie);
int find_id_password(User *user,string passwd,string name);
int update_user_data_base(User **user);
int update_theatre_data_base(Theatre **theatre);
int add_user_to_database(User **user,string id,string name,string password);
int add_movie_to_database(Theatre **theatre,string id,string location,string seats,string movie);
int add_theatre(Theatre **theatre);
int admin_login(void);
int login(User **user);
int signup(User **user);
void display_menu();
void display_admin_menu();
int search_movie(Theatre *theatre,string movie);
int search_seats(Theatre *theatre,int seats,string movie);
int book_movie_ticket(Theatre **theatre,string movie);
#endif // MOVIE_TICKRT_BOOKING_H_INCLUDED
