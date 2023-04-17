#include "local.h"

void read_file();

int generate_waiting_time(int lower, int upper);

void *endSimulation_Time(void *);

void *endSimulation_Products(void *);

void *typeA(void *arg);

void *typeB(void *arg);

void *typeC(void *arg);

void *line_8(void *arg);

void *containers(void *arg);

void *carton_boxes(void *arg);

void *storage_boxes(void *arg);

void *trucks(void *arg);

void startOpenGl();

void display();

void reshape(int w, int h);

void renderBitMap(char *string, void *font, float x, float y);

void timer(int);

void border();

void Arrow(int x, int y);

void Arrow2(int x, int y);

void TypesManuRooms();

void ExpirationDManuline();

void ContainersSection();

void Boxes();

void Storage();

void UpperCircle(int radius, int x, int y);

void LowerCircle(int radius, int x, int y);

void LoadingIntoTrucks();

char TypeAcountsSting[256];
char TypeBcountsSting[256];
char TypeCcountsSting[256];
char PatchNumSting[256];
char title[100];
char ExpNumASting[256];
char ExpNumBSting[256];
char ExpNumCSting[256];
char ContACapString[256];
char ContBCapString[256];
char ContCCapString[256];
char AllCartonNumSting[256];
char CartonNumASting[256];
char CartonNumBSting[256];
char CartonNumCSting[256];
char FullCartonANumSting[256];
char FullCartonBNumSting[256];
char FullCartonCNumSting[256];
char T1CapacitySting[256];
char T2CapacitySting[256];
char T3CapacitySting[256];


bool typeA_employee_working[3][8];
bool typeB_employee_working[2][6];
bool typeC_employee_working[2][5];

void init() {
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
}


int main(int argc, char **argv) {

    read_file();

    memset(order, 0, sizeof(order));
    memset(order1, 0, sizeof(order1));

    total_queue = PTHREAD_MUTEX_INITIALIZER;
    total_queue_printing = PTHREAD_MUTEX_INITIALIZER;
    truck_mutex = PTHREAD_MUTEX_INITIALIZER;
    storage_mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_init(&line8_cond, NULL);
    pthread_cond_init(&storage_area_cond, NULL);
    pthread_cond_init(&employee_cond, NULL);
    for (int i = 0; i < 4; ++i) {
        typeA_l1_mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    }
    for (int i = 0; i < 2; ++i) {
        typeC_mutex[i] = PTHREAD_MUTEX_INITIALIZER;
    }
    // type A
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 8; ++i) {
            employees x;
            x.line = j;
            x.worker = i; //at ane step
            employees *emp = (employees *) malloc(sizeof(employees));
            *emp = x;
            if (pthread_create(&thread[j][i], NULL, &typeA, emp) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    // type B
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 6; ++i) {
            employees x;
            x.line = j;
            x.worker = i; //at ane step
            employees *emp = (employees *) malloc(sizeof(employees));
            *emp = x;
            if (pthread_create(&thread1[j][i], NULL, &typeB, emp) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    // type C
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 5; ++i) {
            employees x;
            x.line = j;
            x.worker = i; //at ane step
            employees *emp = (employees *) malloc(sizeof(employees));
            *emp = x;
            if (pthread_create(&thread2[j][i], NULL, &typeC, emp) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    // TWO EMPLOYEE FOR DATE
    for (int i = 0; i < 2; ++i) {
        employees x;
        x.line = 8;
        x.worker = i; //at ane step
        employees *emp = (employees *) malloc(sizeof(employees));
        *emp = x;
        if (pthread_create(&thread3[i], NULL, &line_8, emp) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }

    //containers employee

    for (int i = 0; i < 3; ++i) {
        employees x;
        x.worker = i; //at ane step
        employees *emp = (employees *) malloc(sizeof(employees));
        *emp = x;
        if (pthread_create(&thread4[i], NULL, &containers, emp) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }
    // boxes employee
    for (int i = 0; i < 3; ++i) {
        employees x;
        x.worker = i; //at ane step
        employees *emp = (employees *) malloc(sizeof(employees));
        *emp = x;
        if (pthread_create(&thread5[i], NULL, &carton_boxes, emp) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }

    // storage employee
    for (int i = 0; i < 2; ++i) {
        employees x;
        x.worker = i; //at ane step
        employees *emp = (employees *) malloc(sizeof(employees));
        *emp = x;
        if (pthread_create(&thread6[i], NULL, &storage_boxes, emp) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }

    // truck employee
    for (int i = 0; i < 2; ++i) {
        employees x;
        x.worker = i; //at ane step
        employees *emp = (employees *) malloc(sizeof(employees));
        *emp = x;
        if (pthread_create(&thread7[i], NULL, &trucks, emp) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }

    // exit thread
    if (pthread_create(&terminat_thread, NULL, &endSimulation_Time, NULL) != 0) {
        perror("pthread_create");
        exit(-1);
    }

    // exit thread
    if (pthread_create(&terminat_thread1, NULL, &endSimulation_Products, NULL) != 0) {
        perror("pthread_create");
        exit(-1);
    }

    glutInit(&argc, argv);
    startOpenGl();


    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 8; ++i) {
            if (pthread_join(thread[j][i], NULL) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 6; ++i) {
            if (pthread_join(thread1[j][i], NULL) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (pthread_join(thread2[j][i], NULL) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (pthread_join(thread3[i], NULL) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (pthread_join(thread4[i], NULL) != 0) {
            perror("pthread_create");
            exit(-1);
        }

        for (int i = 0; i < 3; ++i) {
            if (pthread_join(thread5[i], NULL) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        if (pthread_join(thread6[i], NULL) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (pthread_join(thread7[i], NULL) != 0) {
            perror("pthread_create");
            exit(-1);
        }
    }


    if (pthread_join(terminat_thread, NULL) != 0) {
        perror("pthread_create");
        exit(-1);
    }
    if (pthread_join(terminat_thread1, NULL) != 0) {
        perror("pthread_create");
        exit(-1);
    }

    return 0;
}

void read_file() {
    char tmp[250];
    FILE *arguments;
    arguments = fopen("inputData.txt", "r");
    if (arguments == NULL) {
        perror("CANT OPEN FILE");
        exit(1);
    }
    fscanf(arguments, "%s %s %d %d\n", tmp, tmp, &minA, &maxA);
    fscanf(arguments, "%s %s %d %d\n", tmp, tmp, &minB, &maxB);
    fscanf(arguments, "%s %s %d %d\n", tmp, tmp, &minC, &maxC);
    fscanf(arguments, "%s %d\n", tmp, &number_of_line);
    fscanf(arguments, "%s %d\n", tmp, &number_of_employee_of_typeA);
    fscanf(arguments, "%s %d\n", tmp, &number_of_employee_of_typeB);
    fscanf(arguments, "%s %d\n", tmp, &number_of_employee_of_typeC);
    fscanf(arguments, "%s %d %d\n", tmp, &printing_time_min, &printing_time_max);
    fscanf(arguments, "%s %d\n", tmp, &carton_capacity);
    fscanf(arguments, "%s %d\n", tmp, &Batch_size);
    fscanf(arguments, "%s %d %d\n", tmp, &time_to_place_the_carton_in_the_storage_area_min,
           &time_to_place_the_carton_in_the_storage_area_max);
    fscanf(arguments, "%s %d\n", tmp, &storage_area_capacity);
    fscanf(arguments, "%s %d\n", tmp, &number_of_trucks);
    fscanf(arguments, "%s %d\n", tmp, &truck_capacity);
    fscanf(arguments, "%s %d\n", tmp, &truck_travel_time);
    fscanf(arguments, "%s %d\n", tmp, &targetA);
    fscanf(arguments, "%s %d\n", tmp, &targetB);
    fscanf(arguments, "%s %d\n", tmp, &targetC);
    fscanf(arguments, "%s %d\n", tmp, &termTime);
    fscanf(arguments, "%s %d\n", tmp, &storage_area_min);
    fclose(arguments);

}


int generate_waiting_time(int lower, int upper) {
    int s, numb;
    FILE *f;
    f = fopen("/dev/urandom", "rb");
    fread(&s, sizeof(int), 1, f);
    fclose(f);
    srand(s);
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void *endSimulation_Time(void *) {
    sleep(termTime * 60);
    cout << "Simulation Ends Now" << endl;
    pthread_cond_destroy(&line8_cond);
    pthread_cond_destroy(&storage_area_cond);
    pthread_cond_destroy(&employee_cond);
    kill(getpid(), SIGTERM);
    return NULL;
}

void *endSimulation_Products(void *) {

    while (true) {
        sleep(1);
        if (targetA == carton_typeA && targetB == carton_typeB && targetC == carton_typeC) {
            cout << "Prdoducts Reached The Target" << endl;
            sleep(1);
            pthread_cond_destroy(&line8_cond);
            pthread_cond_destroy(&storage_area_cond);
            pthread_cond_destroy(&employee_cond);
            kill(getpid(), SIGTERM);

        }
    }
    return NULL;
}

void *typeA(void *arg) {
    employees c = *(employees *) arg;
    if (c.worker == 0) {
        typeA_employee_working[c.line][c.worker] = true;
        int z = 1;
        while (1) {
            while (storage_area_counter > storage_area_capacity) {
                pthread_cond_wait(&employee_cond, &storage_mutex);
            }
            chocolate coco;
            coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
            pthread_mutex_lock(&coco.chocolate_mutex);
            coco.chocolate_id = z;
            coco.type = 'A';
            coco.finished_steps = 1;
            sleep(generate_waiting_time(minA, maxA));
            queue1[c.line][c.worker].push(coco);
            z += 1;
            typeA_employee_working[c.line][c.worker] = false;
            usleep(50000);
            pthread_mutex_unlock(&coco.chocolate_mutex);
        }
    }
    if (c.worker == 1) {
        typeA_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue1[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue1[c.line][c.worker - 1].front();
                queue1[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minA, maxA));
                coco.finished_steps++;
                queue1[c.line][c.worker].push(coco);
                typeA_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 2) {
        typeA_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue1[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue1[c.line][c.worker - 1].front();
                queue1[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minA, maxA));
                coco.finished_steps++;
                queue1[c.line][c.worker].push(coco);
                typeA_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 3) {
        typeA_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue1[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue1[c.line][c.worker - 1].front();
                queue1[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minA, maxA));
                coco.finished_steps++;
                queue1[c.line][c.worker].push(coco);
                typeA_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 4 || c.worker == 5 || c.worker == 6 || c.worker == 7) {
        pthread_mutex_lock(&typeA_l1_mutex[c.line]);
        order[c.line]++;
        pthread_mutex_unlock(&typeA_l1_mutex[c.line]);

        if (order[c.line] == 1) {
            typeA_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue1[c.line][3].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue1[c.line][3].front();
                    queue1[c.line][3].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minA, maxA));
                    coco.finished_steps++;
                    queue1[c.line][4].push(coco);
                    typeA_employee_working[c.line][c.worker] = false;
                    usleep(500000);
                    pthread_mutex_unlock(&coco.chocolate_mutex);
                }
            }
        }
        if (order[c.line] == 2) {
            typeA_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue1[c.line][4].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue1[c.line][4].front();
                    queue1[c.line][4].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minA, maxA));
                    coco.finished_steps++;
                    queue1[c.line][5].push(coco);
                    typeA_employee_working[c.line][c.worker] = false;
                    usleep(500000);
                    pthread_mutex_unlock(&coco.chocolate_mutex);
                }
            }
        }
        if (order[c.line] == 3) {
            typeA_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue1[c.line][5].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue1[c.line][5].front();
                    queue1[c.line][5].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minA, maxA));
                    coco.finished_steps++;
                    queue1[c.line][6].push(coco);
                    typeA_employee_working[c.line][c.worker] = false;
                    usleep(500000);
                    pthread_mutex_unlock(&coco.chocolate_mutex);
                }
            }
        }
        if (order[c.line] == 4) {
            typeA_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue1[c.line][6].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue1[c.line][6].front();
                    queue1[c.line][6].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minA, maxA));
                    coco.finished_steps++;
                    coco.type = 'A';

                    pthread_mutex_lock(&total_queue);
                    list_of_chocolate.push(coco);
                    pthread_mutex_unlock(&total_queue);

                    typeA_total_number++;
                    typeA_employee_working[c.line][c.worker] = false;
                    usleep(500000);
                    pthread_mutex_unlock(&coco.chocolate_mutex);
                    pthread_cond_broadcast(&line8_cond);

                }
            }
        }
    }

    free(arg);
    return NULL;
}

void *typeB(void *arg) {
    employees c = *(employees *) arg;
    if (c.worker == 0) {
        typeB_employee_working[c.line][c.worker] = true;
        int z = 1;
        while (1) {
            while (storage_area_counter > storage_area_capacity) {
                pthread_cond_wait(&employee_cond, &storage_mutex);
            }
            chocolate coco;
            coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
            pthread_mutex_lock(&coco.chocolate_mutex);
            coco.chocolate_id = z;
            coco.type = 'B';
            coco.finished_steps = 1;
            sleep(generate_waiting_time(minB, maxB));
            queue2[c.line][c.worker].push(coco);
            z += 1;
            typeB_employee_working[c.line][c.worker] = false;
            usleep(500000);
            pthread_mutex_unlock(&coco.chocolate_mutex);
        }
    }

    if (c.worker == 1) {
        typeB_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue2[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue2[c.line][c.worker - 1].front();
                queue2[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minB, maxB));
                coco.finished_steps++;
                queue2[c.line][c.worker].push(coco);
                typeB_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 2) {
        typeB_employee_working[c.line][c.worker] = true;

        while (1) {
            if (!queue2[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue2[c.line][c.worker - 1].front();
                queue2[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minB, maxB));
                coco.finished_steps++;
                queue2[c.line][c.worker].push(coco);
                typeB_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 3) {
        typeB_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue2[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue2[c.line][c.worker - 1].front();
                queue2[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minB, maxB));
                coco.finished_steps++;
                queue2[c.line][c.worker].push(coco);
                typeB_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }
    if (c.worker == 4) {
        typeB_employee_working[c.line][c.worker] = true;

        while (1) {
            if (!queue2[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue2[c.line][c.worker - 1].front();
                queue2[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minB, maxB));
                coco.finished_steps++;
                queue2[c.line][c.worker].push(coco);
                typeB_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }
    if (c.worker == 5) {
        typeB_employee_working[c.line][c.worker] = true;
        while (1) {
            if (!queue2[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue2[c.line][c.worker - 1].front();
                queue2[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minB, maxB));
                coco.finished_steps++;
                pthread_mutex_lock(&total_queue);
                list_of_chocolate.push(coco);
                pthread_mutex_unlock(&total_queue);

                typeB_total_number++;
                typeB_employee_working[c.line][c.worker] = false;
                usleep(500000);
                pthread_mutex_unlock(&coco.chocolate_mutex);
                pthread_cond_broadcast(&line8_cond);


            }
        }
    }
    free(arg);
    return NULL;
}

void *typeC(void *arg) {
    employees c = *(employees *) arg;
    if (c.worker == 0) {
        typeC_employee_working[c.line][c.worker] = true;

        int z = 1;
        while (1) {
            while (storage_area_counter > storage_area_capacity) {
                pthread_cond_wait(&employee_cond, &storage_mutex);
            }
            chocolate coco;
            coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
            pthread_mutex_lock(&coco.chocolate_mutex);
            coco.chocolate_id = z;
            coco.type = 'C';
            coco.finished_steps = 1;
            sleep(generate_waiting_time(minC, maxC));
            queue3[c.line][c.worker].push(coco);
            z += 1;
            typeC_employee_working[c.line][c.worker] = false;
            usleep(500000);
            pthread_mutex_unlock(&coco.chocolate_mutex);
        }
    }
    if (c.worker == 1) {
        typeC_employee_working[c.line][c.worker] = true;

        while (1) {
            if (!queue3[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue3[c.line][c.worker - 1].front();
                queue3[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minC, maxC));
                coco.finished_steps++;
                queue3[c.line][c.worker].push(coco);
                typeC_employee_working[c.line][c.worker] = false;
                usleep(500000);

                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }
    if (c.worker == 2) {
        typeC_employee_working[c.line][c.worker] = true;

        while (1) {
            if (!queue3[c.line][c.worker - 1].empty()) {
                while (storage_area_counter > storage_area_capacity) {
                    pthread_cond_wait(&employee_cond, &storage_mutex);
                }
                chocolate coco = queue3[c.line][c.worker - 1].front();
                queue3[c.line][c.worker - 1].pop();
                coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                pthread_mutex_lock(&coco.chocolate_mutex);
                sleep(generate_waiting_time(minC, maxC));
                coco.finished_steps++;
                queue3[c.line][c.worker].push(coco);
                typeC_employee_working[c.line][c.worker] = false;
                usleep(500000);

                pthread_mutex_unlock(&coco.chocolate_mutex);
            }
        }
    }

    if (c.worker == 3 || c.worker == 4) {
        pthread_mutex_lock(&typeC_mutex[2 - c.line]);
        order1[c.line]++;
        pthread_mutex_unlock(&typeC_mutex[2 - c.line]);
        if (order1[c.line] == 1) {
            typeC_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue3[c.line][2].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue3[c.line][2].front();
                    queue3[c.line][2].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minC, maxC));
                    coco.finished_steps++;
                    queue3[c.line][3].push(coco);
                    typeC_employee_working[c.line][c.worker] = false;
                    usleep(500000);

                    pthread_mutex_unlock(&coco.chocolate_mutex);
                }
            }
        }
        if (order1[c.line] == 2) {
            typeC_employee_working[c.line][c.worker] = true;

            while (1) {
                if (!queue3[c.line][3].empty()) {
                    while (storage_area_counter > storage_area_capacity) {
                        pthread_cond_wait(&employee_cond, &storage_mutex);
                    }
                    chocolate coco = queue3[c.line][3].front();
                    queue3[c.line][3].pop();
                    coco.chocolate_mutex = PTHREAD_MUTEX_INITIALIZER;
                    pthread_mutex_lock(&coco.chocolate_mutex);
                    sleep(generate_waiting_time(minC, maxC));
                    coco.finished_steps++;

                    pthread_mutex_lock(&total_queue);
                    list_of_chocolate.push(coco);
                    pthread_mutex_unlock(&total_queue);

                    typeC_total_number++;
                    typeC_employee_working[c.line][c.worker] = false;
                    usleep(500000);

                    pthread_mutex_unlock(&coco.chocolate_mutex);
                    pthread_cond_broadcast(&line8_cond);
                }
            }
        }
    }

    free(arg);
    return NULL;
}

void *line_8(void *arg) {
    employees c = *(employees *) arg;
    sleep(1);
    if (c.worker == 0) {
        while (1) {
            if (flag) {
                pthread_mutex_lock(&total_queue);
                while (list_of_chocolate.size() < Batch_size + 1) {
                    pthread_cond_wait(&line8_cond, &total_queue);
                }
                testt = true;
                test1 = false;
                for (int i = 0; i < Batch_size; ++i) {
                    if (list_of_chocolate.front().type == 'A') {
                        printing_expiration_date_typeA++;
                        typeA_total_number--;
                    } else if (list_of_chocolate.front().type == 'B') {
                        printing_expiration_date_typeB++;
                        typeB_total_number--;
                    } else if (list_of_chocolate.front().type == 'C') {
                        printing_expiration_date_typeC++;
                        typeC_total_number--;
                    }
                    list_of_chocolate_printing.push(list_of_chocolate.front());
                    list_of_chocolate.pop();
                }
                pthread_mutex_unlock(&total_queue);
                flag = false;
                sleep(generate_waiting_time(printing_time_min, printing_time_max));
            }
        }
    }
    if (c.worker == 1) {
        while (1) {
            if (!flag) {
                pthread_mutex_lock(&total_queue);
                while (list_of_chocolate.size() < 11) {
                    pthread_cond_wait(&line8_cond, &total_queue);
                }
                testt = false;
                test1 = true;
                for (int i = 0; i < 10; ++i) {
                    if (list_of_chocolate.front().type == 'A') {
                        printing_expiration_date_typeA++;
                        typeA_total_number--;
                    } else if (list_of_chocolate.front().type == 'B') {
                        printing_expiration_date_typeB++;
                        typeB_total_number--;
                    } else if (list_of_chocolate.front().type == 'C') {
                        printing_expiration_date_typeC++;
                        typeC_total_number--;
                    }
                    list_of_chocolate_printing.push(list_of_chocolate.front());
                    list_of_chocolate.pop();
                }
                pthread_mutex_unlock(&total_queue);
                flag = true;
                sleep(generate_waiting_time(printing_time_min, printing_time_max));
            }
        }
    }
    free(arg);
    return NULL;
}

void *containers(void *arg) {

    employees c = *(employees *) arg;

    if (c.worker == 0) {
        while (1) {
            if (!list_of_chocolate_printing.empty()) {
                test6 = true;
                if (list_of_chocolate_printing.front().type == 'A') {
                    pthread_mutex_lock(&total_queue_printing);
                    list_of_chocolate_printing_typeA.push(list_of_chocolate_printing.front());
                    list_of_chocolate_printing.pop();
                    containers_typeA++;
                    printing_expiration_date_typeA--;
                    usleep(5000);
                    pthread_mutex_unlock(&total_queue_printing);
                } else {
                    sleep(1);
                }
            }
        }
    }
    if (c.worker == 1) {
        while (1) {
            if (!list_of_chocolate_printing.empty()) {
                test7 = true;
                if (list_of_chocolate_printing.front().type == 'B') {
                    pthread_mutex_lock(&total_queue_printing);
                    list_of_chocolate_printing_typeB.push(list_of_chocolate_printing.front());
                    list_of_chocolate_printing.pop();
                    containers_typeB++;
                    printing_expiration_date_typeB--;

                    usleep(5000);
                    pthread_mutex_unlock(&total_queue_printing);

                } else {
                    sleep(1);
                }
            }
        }
    }

    if (c.worker == 2) {
        while (1) {
            if (!list_of_chocolate_printing.empty()) {
                test8 = true;
                if (list_of_chocolate_printing.front().type == 'C') {
                    pthread_mutex_lock(&total_queue_printing);
                    list_of_chocolate_printing_typeC.push(list_of_chocolate_printing.front());
                    list_of_chocolate_printing.pop();
                    containers_typeC++;
                    printing_expiration_date_typeC--;

                    usleep(5000);

                    pthread_mutex_unlock(&total_queue_printing);

                } else {
                    sleep(1);
                }
            }

        }
    }

    return NULL;
}

void *carton_boxes(void *arg) {
    employees c = *(employees *) arg;
    if (c.worker == 0) {
        while (1) {
            if (!list_of_chocolate_printing_typeA.empty()) {
                test2 = true;
                pthread_mutex_lock(&total_queue_printing);
                list_of_chocolate_packed_typeA.push(list_of_chocolate_printing_typeA.front());
                list_of_chocolate_printing_typeA.pop();

                pthread_mutex_unlock(&total_queue_printing);

                if ((list_of_chocolate_packed_typeA.size() % carton_capacity) == 0) {
                    carton_typeA++;
                    containers_typeA = containers_typeA - carton_capacity;
                    number_of_typeA_in_storage++;
                    pthread_cond_signal(&storage_area_cond);
                }
                usleep(50000);

            }
        }

    }
    if (c.worker == 1) {
        while (1) {
            if (!list_of_chocolate_printing_typeB.empty()) {
                test3 = true;

                pthread_mutex_lock(&total_queue_printing);
                list_of_chocolate_packed_typeB.push(list_of_chocolate_printing_typeB.front());
                list_of_chocolate_printing_typeB.pop();
                pthread_mutex_unlock(&total_queue_printing);

                if ((list_of_chocolate_packed_typeB.size() % carton_capacity) == 0) {
                    carton_typeB++;
                    containers_typeB = containers_typeB - carton_capacity;
                    number_of_typeB_in_storage++;
                    pthread_cond_signal(&storage_area_cond);
                }
                usleep(50000);
            }
        }
    }
    if (c.worker == 2) {
        while (1) {
            if (!list_of_chocolate_printing_typeC.empty()) {
                test4 = true;

                pthread_mutex_lock(&total_queue_printing);
                list_of_chocolate_packed_typeC.push(list_of_chocolate_printing_typeC.front());
                list_of_chocolate_printing_typeC.pop();
                pthread_mutex_unlock(&total_queue_printing);

                if ((list_of_chocolate_packed_typeC.size() % carton_capacity) == 0) {
                    carton_typeC++;
                    containers_typeC = containers_typeC - carton_capacity;
                    number_of_typeC_in_storage++;
                    pthread_cond_signal(&storage_area_cond);
                }
                usleep(50000);

            }
        }
    }
    free(arg);
    return NULL;
}

void *storage_boxes(void *arg) {
    employees c = *(employees *) arg;
    bool flag_storage = true;
    while (1) {
        pthread_mutex_lock(&total_queue_printing);
        while (flag_storage) {
            pthread_cond_wait(&storage_area_cond, &total_queue_printing);
            flag_storage = false;
        }
        test5 = true;
        storage_area_counter++;
        pthread_mutex_unlock(&total_queue_printing);
        sleep(generate_waiting_time(time_to_place_the_carton_in_the_storage_area_min,
                                    time_to_place_the_carton_in_the_storage_area_max));
        flag_storage = true;
        if (storage_area_counter < storage_area_min) {
            pthread_cond_broadcast(&employee_cond);
        }
    }

    free(arg);
    return NULL;
}

void *trucks(void *arg) {
    employees c = *(employees *) arg;
    while (1) {
        pthread_mutex_lock(&truck_mutex);
        if (storage_area_counter > 0) {
            truck2 = true;
            if (truck[current_truck] < truck_capacity) {
                truck[current_truck]++;
                storage_area_counter--;
                if (truck[current_truck] == truck_capacity) {
                    current_time = time(NULL);
                    trucks_time[current_truck] = current_time;
                    current_truck = (current_truck + 1) % number_of_trucks;
                }
            }
            if (truck[current_truck] == truck_capacity) {
                current_time = time(NULL);
                int delta_time = current_time - trucks_time[current_truck];
                if (delta_time >= (int) truck_travel_time) {
                    truck[current_truck] = 0;
                }
            }
        }
        pthread_mutex_unlock(&truck_mutex);
    }
    free(arg);
    return NULL;
}

// //////////////////////////////////////////////////////////////////////////////////////// opengl
void startOpenGl() {

    init();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 700);
    glutInitWindowPosition(150, 250);
    glutCreateWindow("Chocolate Factory simulator");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    border();
    TypesManuRooms();
    ExpirationDManuline();
    ContainersSection();
    Boxes();
    Storage();
    LoadingIntoTrucks();
    glutPostRedisplay();
    glutSwapBuffers();
}

void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1400, 0, 700);
    glMatrixMode(GL_MODELVIEW);
}

void renderBitMap(char *string, void *font, float x, float y) {
    char *c;
    glRasterPos2i(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

/////////////// rect expiry date 1
    if (x1 > 950 && l == 0 && testt == true) {
        x1 = x1 - 2;
        if (x1 == 950)
            l = 1;
    } else if (x1 < 1050 && l == 1 && testt == true) {
        x1 = x1 + 2;
        if (x1 == 1050)
            l = 0;
    }

///////////////// rect expiry date 2

    if (x2 > 950 && q == 0 && test1 == true) {
        x2 = x2 - 2;
        if (x2 == 950)
            q = 1;
    } else if (x2 < 1050 && q == 1 && test1 == true) {
        x2 = x2 + 2;
        if (x2 == 1050)
            q = 0;
    }

    //////////////// rect box1

    if (x11 < 380 && a == 0 && test2 == true) {
        x11 = x11 + 2;
        if (x11 == 380)
            a = 1;
    } else if (x11 >= 250 && a == 1 && test2 == true) {
        x11 = x11 - 2;
        if (x11 == 250)
            a = 0;
    }
    //////////////// rect box2

    if (x12 < 380 && b == 0 && test3 == true) {
        x12 = x12 + 2;
        if (x12 == 380)
            b = 1;
    } else if (x12 > 250 && b == 1 && test3 == true) {
        x12 = x12 - 2;
        if (x12 == 250)
            b = 0;
    }
    //////////////// rect box3

    if (x13 < 380 && c == 0 && test4 == true) {
        x13 = x13 + 2;
        if (x13 == 380)
            c = 1;
    } else if (x13 > 250 && c == 1 && test4 == true) {
        x13 = x13 - 2;
        if (x13 == 250)
            c = 0;
    }

    //////////////// rect storage1
    if (x21 < 780 && d == 0 && test5 == true) {
        x21 = x21 + 2;
        if (x21 == 780)
            d = 1;
    } else if (x21 > 680 && d == 1 && test5 == true) {
        x21 = x21 - 2;
        if (x21 == 680)
            d = 0;
    }

    //////////////// rect storage2
    if (x22 < 780 && e == 0 && test5 == true) {
        x22 = x22 + 2;
        if (x22 == 780)
            e = 1;
    } else if (x22 > 680 && e == 1 && test5 == true) {
        x22 = x22 - 2;
        if (x22 == 680)
            e = 0;
    }

    /////////// truck loading 1
    if (x30 > 1100 && f == 0 && truck2 == true) {
        x30 = x30 - 2;
        if (x30 == 1100)
            f = 1;
    } else if (x30 < 1150 && f == 1 && truck2 == true) {
        x30 = x30 + 2;
        if (x30 == 1150)
            f = 0;
    }

    /////////// truck loading 2
    if (x31 > 1100 && g == 0 && truck2 == true) {
        x31 = x31 - 2;
        if (x31 == 1100)
            g = 1;
    } else if (x31 < 1150 && g == 1 && truck2 == true) {
        x31 = x31 + 2;
        if (x31 == 1150)
            g = 0;
    }

}

void border() {

    int offset = 40;
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0 + offset, 0 + offset);
    glVertex2f(0 + offset, 700 - offset);

    glBegin(GL_LINES);
    glVertex2f(1400 - offset, 700 - offset);
    glVertex2f(1400 - offset, 0 + offset);

    glBegin(GL_LINES);
    glVertex2f(0 + offset, 0 + offset);
    glVertex2f(1400 - offset, 0 + offset);

    glBegin(GL_LINES);
    glVertex2f(0 + offset, 700 - offset);
    glVertex2f(1400 - offset, 700 - offset);

    glFlush();
    glEnd();
}

void Arrow(int x, int y) {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x - 130, y);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x - 120, y + 10);
    glVertex2f(x - 130, y);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x - 120, y - 10);
    glVertex2f(x - 130, y);
    glEnd();
    glFlush();
}

void Arrow2(int x, int y) {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x + 130, y);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x + 120, y + 10);
    glVertex2f(x + 130, y);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x + 120, y - 10);
    glVertex2f(x + 130, y);
    glEnd();
    glFlush();
}

void TypesManuRooms() {

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(40, 400);
    glVertex2f(1360, 400);
    glFlush();
    glEnd();

    for (int i = 40; i <= 1360; i += 440) {

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(i, 660);
        glVertex2f(i, 400);
        glEnd();
        glFlush();
    }
    ///typeA manu lines
    sprintf(TypeAcountsSting, "TypeA #: %d", typeA_total_number);
    renderBitMap(TypeAcountsSting, GLUT_BITMAP_HELVETICA_18, 200, 410);

    for (int i = 0; i <= 2; i++) {
        glColor3f(0, 0, 1);

        glBegin(GL_POLYGON);
        glVertex2f((140 + 100 * i), 640);
        glVertex2f((140 + 100 * i) + 20, 640);
        glVertex2f((140 + 100 * i) + 20, 440);
        glVertex2f((140 + 100 * i), 440);
        glEnd();
        glFlush();

        ///typeA employees
        for (int j = 7; j >= 0; j--) {

            glColor3f(0, 1, 0);
            glBegin(GL_POLYGON);
            glVertex2f((140 + 100 * i) - 10, (640 - 28 * j) + 10);
            glVertex2f((140 + 100 * i) - 10 - 10, (640 - 28 * j) + 10);
            glVertex2f((140 + 100 * i) - 10 - 10, (640 - 28 * j));
            glVertex2f((140 + 100 * i) - 10, (640 - 28 * j));
            glEnd();
            glFlush();

            if (typeA_employee_working[i][j] == true) {
                glColor3f(1, 0, 0);
                glBegin(GL_POLYGON);
                glVertex2f((140 + 100 * i) - 10, (640 - 28 * j) + 10);
                glVertex2f((140 + 100 * i) - 10 - 10, (640 - 28 * j) + 10);
                glVertex2f((140 + 100 * i) - 10 - 10, (640 - 28 * j));
                glVertex2f((140 + 100 * i) - 10, (640 - 28 * j));
                glEnd();
                glFlush();
            }
        }
    }


    ///typeB manu lines

    glColor3f(0, 0, 0);
    sprintf(TypeBcountsSting, "TypeB #: %d", typeB_total_number);
    renderBitMap(TypeBcountsSting, GLUT_BITMAP_HELVETICA_18, 650, 410);

    for (int i = 0; i <= 1; i++) {
        glColor3f(1, 1, 0);
        glBegin(GL_POLYGON);
        glVertex2f((600 + 200 * i), 640);
        glVertex2f((600 + 200 * i) + 20, 640);
        glVertex2f((600 + 200 * i) + 20, 440);
        glVertex2f((600 + 200 * i), 440);
        glEnd();
        glFlush();

        ///typeB employees
        for (int j = 5; j >= 0; j--) {

            glColor3f(0, 1, 0);

            if (typeB_employee_working[i][j]) {
                glColor3f(1, 0, 0);

            }

            glBegin(GL_POLYGON);
            glVertex2f((600 + 200 * i) - 10, (640 - 40 * j) + 10);
            glVertex2f((600 + 200 * i) - 10 - 10, (640 - 40 * j) + 10);
            glVertex2f((600 + 200 * i) - 10 - 10, (640 - 40 * j));
            glVertex2f((600 + 200 * i) - 10, (640 - 40 * j));
            glEnd();
            glFlush();
        }
    }

    ///typeC manu lines

    glColor3f(0, 0, 0);
    sprintf(TypeCcountsSting, "TypeC #: %d", typeC_total_number);
    renderBitMap(TypeCcountsSting, GLUT_BITMAP_HELVETICA_18, 1100, 410);

    for (int i = 0; i <= 1; i++) {
        glColor3f(1, 0, 1);

        glBegin(GL_POLYGON);
        glVertex2f((1050 + 200 * i), 640);
        glVertex2f((1050 + 200 * i) + 20, 640);
        glVertex2f((1050 + 200 * i) + 20, 440);
        glVertex2f((1050 + 200 * i), 440);
        glEnd();
        glFlush();

        ///typeC employees
        for (int j = 4; j >= 0; j--) {
            glColor3f(0, 1, 0.0);

            if (typeC_employee_working[i][j]) {

                glColor3f(1.0, 0.0, 0.0);
            }


            glBegin(GL_POLYGON);
            glVertex2f((1050 + 200 * i) - 10, (640 - 50 * j) + 10);
            glVertex2f((1050 + 200 * i) - 10 - 10, (640 - 50 * j) + 10);
            glVertex2f((1050 + 200 * i) - 10 - 10, (640 - 50 * j));
            glVertex2f((1050 + 200 * i) - 10, (640 - 50 * j));
            glEnd();
            glFlush();
        }

    }
}

void ExpirationDManuline() {

    Arrow(1360, 310);

    sprintf(title, "exp date process");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 1250, 315);

    glColor3f(0, 0, 0);
    sprintf(PatchNumSting, "Batch #: %d", Batch_size);
    renderBitMap(PatchNumSting, GLUT_BITMAP_HELVETICA_18, 1100, 310);

    ///expiring date employees

    if (testt == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x1, y11);
    glEnd();
    glFlush();

    if (test1 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }

    glBegin(GL_POINTS);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();

    ////////// expiry line

    if (testt == true || test1 == true) {
        glColor3f(0.5, 0.5, 0.5);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(800, 330);
    glVertex2f(1000, 330);
    glVertex2f(1000, 310);
    glVertex2f(800, 310);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    sprintf(ExpNumASting, "exp products A#: %d", printing_expiration_date_typeA);
    renderBitMap(ExpNumASting, GLUT_BITMAP_HELVETICA_18, 600, 350);

    sprintf(ExpNumBSting, "exp products B#: %d", printing_expiration_date_typeB);
    renderBitMap(ExpNumBSting, GLUT_BITMAP_HELVETICA_18, 600, 320);

    sprintf(ExpNumCSting, "exp products C#: %d", printing_expiration_date_typeC);
    renderBitMap(ExpNumCSting, GLUT_BITMAP_HELVETICA_18, 600, 290);

}

void ContainersSection() {

    sprintf(title, "containers process");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 450, 315);

    Arrow(550, 310);

    /// CONTAINER A
    if (test6 == true) {
        glColor3f(0, 0, 1);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(60, 350);
    glVertex2f(60 + 100, 350);
    glVertex2f(60 + 100, 290);
    glVertex2f(60, 290);
    glEnd();
    glFlush();

    /// CONTAINER B
    if (test7 == true) {
        glColor3f(1, 1, 0);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(180, 350);
    glVertex2f(180 + 100, 350);
    glVertex2f(180 + 100, 290);
    glVertex2f(180, 290);
    glEnd();
    glFlush();

    /// CONTAINER C
    if (test8 == true) {
        glColor3f(1, 0, 1);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(300, 350);
    glVertex2f(300 + 100, 350);
    glVertex2f(300 + 100, 290);
    glVertex2f(300, 290);
    glEnd();
    glFlush();

    ///CONTAINERS EMPLOYEE A
    if (test6 == true) {
        glColor3f(0, 0, 1);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(60 + 50, 380);
    glVertex2f(60 + 60, 380);
    glVertex2f(60 + 60, 390);
    glVertex2f(60 + 50, 390);
    glEnd();
    glFlush();

    ///CONTAINERS EMPLOYEE B
    if (test7 == true) {
        glColor3f(1, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(180 + 50, 380);
    glVertex2f(180 + 60, 380);
    glVertex2f(180 + 60, 390);
    glVertex2f(180 + 50, 390);
    glEnd();
    glFlush();

    ///CONTAINERS EMPLOYEE C
    if (test8 == true) {
        glColor3f(1, 0, 1);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(300 + 50, 380);
    glVertex2f(300 + 60, 380);
    glVertex2f(300 + 60, 390);
    glVertex2f(300 + 50, 390);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    sprintf(title, "Container A");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 61, 320);
    sprintf(title, "Container B");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 181, 320);
    sprintf(title, "Container C");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 301, 320);

    sprintf(ContACapString, "Cont A cap #: %d", containers_typeA);
    renderBitMap(ContACapString, GLUT_BITMAP_HELVETICA_12, 60, 270);

    sprintf(ContBCapString, "Cont B cap #: %d", containers_typeB);
    renderBitMap(ContBCapString, GLUT_BITMAP_HELVETICA_12, 180, 270);

    sprintf(ContCCapString, "Cont C cap #: %d", containers_typeC);
    renderBitMap(ContCCapString, GLUT_BITMAP_HELVETICA_12, 300, 270);
}

void Boxes() {

    glColor3f(0, 0, 0);
    sprintf(title, "Boxing process");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 50, 215);
    Arrow2(40, 200);

    ///BOXING EMPLOYEE 1
    if (test2 == true) {
        glColor3f(0, 0, 1);
    } else {
        glColor3f(0, 0, 0);
    }
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x11, y);
    glEnd();
    glFlush();

    ///BOXING EMPLOYEE 2

    if (test3 == true) {
        glColor3f(1, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POINTS);
    glVertex2f(x12, y12);
    glEnd();
    glFlush();

    ///BOXING EMPLOYEE 3
    if (test4 == true) {
        glColor3f(1, 0, 1);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POINTS);
    glVertex2f(x13, y13);
    glEnd();
    glFlush();


    glColor3f(0, 0, 0);
    sprintf(FullCartonANumSting, "cartons A #: %d", carton_typeA);
    renderBitMap(FullCartonANumSting, GLUT_BITMAP_HELVETICA_18, 400, 235);

    sprintf(FullCartonBNumSting, "cartons B #: %d", carton_typeB);
    renderBitMap(FullCartonBNumSting, GLUT_BITMAP_HELVETICA_18, 400, 205);

    sprintf(FullCartonCNumSting, "cartons C #: %d", carton_typeC);
    renderBitMap(FullCartonCNumSting, GLUT_BITMAP_HELVETICA_18, 400, 175);
}

void Storage() {

    glColor3f(0, 0, 0);
    sprintf(title, "storage process");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 540, 215);

    Arrow2(530, 200);
    if (test5 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(GL_POLYGON);
    glVertex2f(800, 230);
    glVertex2f(1000, 230);
    glVertex2f(1000, 180);
    glVertex2f(800, 180);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    sprintf(title, "storage Area");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 850, 200);

    ///STORING EMPLOYEE 1
    if (test5 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x21, y21);
    glEnd();
    glFlush();

    ///STORING EMPLOYEE 2
    if (test5 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glBegin(GL_POINTS);
    glVertex2f(x22, y22);
    glEnd();
    glFlush();

    glColor3f(0, 0, 0);
    sprintf(AllCartonNumSting, "stored cartons A #: %d", number_of_typeA_in_storage);
    renderBitMap(AllCartonNumSting, GLUT_BITMAP_HELVETICA_18, 1020, 230);

    sprintf(CartonNumASting, "stored cartons B #: %d", number_of_typeB_in_storage);
    renderBitMap(CartonNumASting, GLUT_BITMAP_HELVETICA_18, 1020, 210);

    sprintf(CartonNumBSting, "stored cartons C #: %d", number_of_typeC_in_storage);
    renderBitMap(CartonNumBSting, GLUT_BITMAP_HELVETICA_18, 1020, 190);

    sprintf(CartonNumCSting, "All stored cartons #: %d", storage_area_counter);
    renderBitMap(CartonNumCSting, GLUT_BITMAP_HELVETICA_18, 1015, 170);

}

void UpperCircle(int radius, int x, int y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(x, y); //center of the semi-circle
    for (int i = 0; i < 180; i++) {
        float rad = i * (M_PI / 180.0);
        glVertex2f(x + cos(rad) * radius, y + sin(rad) * radius);
    }
    glEnd();
}

void LowerCircle(int radius, int x, int y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(x, y); //center of the semi-circle
    for (int i = 180; i <= 360; i++) {
        float rad = i * (M_PI / 180.0);
        glVertex2f(x + cos(rad) * radius, y + sin(rad) * radius);
    }
    glEnd();
}

void LoadingIntoTrucks() {

    glColor3f(0, 0, 0);
    sprintf(title, "Loading in trucks process");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 1215, 215);
    renderBitMap(title, GLUT_BITMAP_HELVETICA_12, 1200, 115);

    Arrow2(1220, 200);
    Arrow(1340, 100);

    ///Loading EMPLOYEES
    if (truck2 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x30, y24);
    glEnd();
    glFlush();

    if (truck2 == true) {
        glColor3f(0, 1, 0);
    } else {
        glColor3f(0, 0, 0);
    }
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(x31, y25);
    glEnd();
    glFlush();

    for (int i = 700; i <= 1000; i += 140) {

        UpperCircle(10, i + 25, 130);
        UpperCircle(10, i + 140 - 65, 130);

        LowerCircle(10, i + 25, 70);
        LowerCircle(10, i + 140 - 65, 70);

        if (truck2 == true) {
            glColor3f(0, 1, 0);
        } else {
            glColor3f(1, 0, 0);
        }
        glBegin(GL_POLYGON);
        glVertex2f(i, 130);
        glVertex2f(i + 100, 130);
        glVertex2f(i + 100, 70);
        glVertex2f(i, 70);

        glEnd();
        glFlush();
    }

    glColor3f(0, 0, 0);
    sprintf(title, "Truck1");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 715, 100);
    sprintf(title, "Truck2");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 855, 100);
    sprintf(title, "Truck3");
    renderBitMap(title, GLUT_BITMAP_HELVETICA_18, 1000, 100);


    sprintf(T1CapacitySting, "T1 capacity: %d", truck[0]);
    renderBitMap(T1CapacitySting, GLUT_BITMAP_HELVETICA_18, 500, 126);

    sprintf(T2CapacitySting, "T2 capacity: %d", truck[1]);
    renderBitMap(T2CapacitySting, GLUT_BITMAP_HELVETICA_18, 500, 96);

    sprintf(T3CapacitySting, "T3 capacity: %d", truck[2]);
    renderBitMap(T3CapacitySting, GLUT_BITMAP_HELVETICA_18, 500, 66);
}