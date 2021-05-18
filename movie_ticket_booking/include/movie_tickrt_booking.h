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
using namespace std;
#define SUCCESSFULL 0
#define FAILED -1
#define FOUND 2
#define MAX_TRIES 3

typedef struct user_data{

    string user_id;
    string user_name;
    string user_password;
    struct user_data *link;
}User;

int insert_to_list(User **user,string word,string word1,string word2);
int display_list(User *user);
int find_id(User *user,string id);
int find_id_password(User *user,string passwd,string name);
int update_data_base(User **user);
int add_user_to_database(User **user,string id,string name,string password);
#endif // MOVIE_TICKRT_BOOKING_H_INCLUDED
