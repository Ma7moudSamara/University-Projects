#ifndef PROJECT3_LOCAL_H
#define PROJECT3_LOCAL_H

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <string.h>
#include <queue>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <fstream>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <map>
#include <GL/glut.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include <sys/types.h>
#include <signal.h>
using namespace std;

pthread_t thread[3][8];
pthread_t thread1[2][6];
pthread_t thread2[2][5];
pthread_t thread3[2];
pthread_t thread4[3];
pthread_t thread5[3]; // boxes employees
pthread_t thread6[2];
pthread_t thread7[2];
pthread_t terminat_thread;
pthread_t terminat_thread1;


// expiry rect
int l, q = 0;
float x1 = 1050;
float x2 = 1050;
float y11 = 350;
float y2 = 280;
// end expiry rect

// box rect
int a, b, c = 0;
float x11 = 250;
float x12 = 250;
float x13 = 250;
float y = 240;
float y12 = 210;
float y13 = 180;
// end box rect

// storage rect
int d, e = 0;
float x21 = 680;
float x22 = 680;
float y21 = 190;
float y22 = 225;
// end storage rect

// truck
int f,g = 0;
float x30 = 1150;
float x31 = 1150;
float y24 = 80;
float y25 = 110;
//trucks

bool flag = true;
bool testt=false;
bool test1=false;
bool test2=false;
bool test3 =false;
bool test4=false;
bool test5=false;
bool test6=false;
bool test7=false;
bool test8=false;
bool truck2=false;

int number_of_trucks = 0, truck_capacity = 0, truck_travel_time = 0;
int number_of_typeA_in_storage = 0, number_of_typeB_in_storage = 0, number_of_typeC_in_storage = 0;
int storage_area_capacity = 0, storage_area_counter = 0,storage_area_min=0;
int time_to_place_the_carton_in_the_storage_area_min = 0, time_to_place_the_carton_in_the_storage_area_max = 0;
int printing_expiration_date_typeA = 0, printing_expiration_date_typeB = 0, printing_expiration_date_typeC = 0;
int containers_typeA = 0, containers_typeB = 0, containers_typeC = 0, carton_typeA = 0, carton_typeB = 0, carton_typeC = 0;
int printing_time_min, printing_time_max, carton_capacity, Batch_size,targetA, targetB, targetC,termTime;
int typeB_total_number = 0, typeC_total_number = 0, typeA_total_number = 0;
int minA, maxA, minB, maxB, minC, maxC, number_of_line, number_of_employee_of_typeA, number_of_employee_of_typeB, number_of_employee_of_typeC;
int order[4], order1[3];

typedef struct employees {
    int line;
    int worker; // number of step
} employees;
typedef struct chocolate {
    unsigned int chocolate_id;
    char type;
    int finished_steps;
    pthread_mutex_t chocolate_mutex;
} chocolate;
queue<chocolate> list_of_chocolate;
queue<chocolate> storage_area;
queue<chocolate> list_of_chocolate_printing;
queue<chocolate> list_of_chocolate_printing_typeA, list_of_chocolate_printing_typeB, list_of_chocolate_printing_typeC;
queue<chocolate> list_of_chocolate_packed_typeA, list_of_chocolate_packed_typeB, list_of_chocolate_packed_typeC;
queue<chocolate> queue1[9][9];
queue<chocolate> queue2[9][9];
queue<chocolate> queue3[9][9];

int truck[3];
time_t trucks_time[3];
int current_truck = 0;
time_t current_time;

/*
 * mutex look
 */
pthread_mutex_t typeA_l1_mutex[4], typeC_mutex[2], total_queue, total_queue_printing, truck_mutex, storage_mutex;
pthread_cond_t line8_cond, storage_area_cond,employee_cond;

#endif //PROJECT3_LOCAL_H