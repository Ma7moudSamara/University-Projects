//   1191602         MAHMOUD SAMARA       PROJECT 5       SECTION 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 1000000  // DEFINE VARIABLE IT IS CALLED INFINITY AND GIVE IT AN INITIAL VALUE

struct input
{
    int vertex_id_1, vertex_id_2, weight;
    char *town;
};

typedef struct input Input;  //give a new struct input* which is Input

struct output
{
    char *path;
    int distance;
    char *towns;
};
typedef struct output Output; //give a new struct output* which is Output

//a function declaration for find_inputs_from_line, parameters is line, return type is Input
Input find_inputs_from_line(char line[]);
//a function declaration for get_towns_path, parameters is output informations, no return type since it is void
void get_towns_path(char *towns_path, char *result_path, Input *file_data, int num_lines);
//a function declaration for find_shortest_distance, parameters is distance informations, return type is Output
Output find_shortest_distance(int *matrix, int MATRIX_SIZE, int start, int end, Input *file_data, int num_lines);
//a function declaration for get_max_vertex_value, return type is int
int get_max_vertex_value();
//a function declaration for get_number_of_lines,return type is int
int get_number_of_lines();
//a function declaration for read_data, parameters is data, no return type since it is void
void read_data(int *matrix, int MATRIX_SIZE, Input *file_data);
//a function declaration for save_result_to_file, parameters is line,  no return type since it is void
void save_result_to_file(Output results[100],int num_results);
//a function declaration for initialize_adjacency_matrix, parameters is line,  no return type since it is void
void initialize_matrix(int *matrix, int MATRIX_SIZE);
//a function declaration for checkinputs, parameters is int,  no return type since it is void
void checkinputs(Input *s,int node1,int node2);

void instructions ()
{
    printf("Welcome to my program!\n\n");
    printf("My program is implement a a solution of a very common issue: how to get from one town to another using the shortest route.\n");
    printf("1.Be sure that you entered the data in the file if not please put your data in a file named segments.txt\n");
    printf("2.Be sure that the file is added in the code folder and it has been read succesfully\n");
    printf("4.Thank you for using my program and I hope you will enjoy it. \n");
    printf("----------------------------------------------------------------\n");
}

// the main function
int main()
{
    Output results[500]; // intialize result from struct output kind
    Output result;
    int num_results = 0;
    int result_calculated = 0;
    int file_read = 0; // use it to check if the user read the file or not
    int user_input, start, end; // variables used in the loop in scanf

    char buffer[1000];

    int MATRIX_SIZE = get_max_vertex_value()+1; // to calculate the max size in the input file
    int num_lines = get_number_of_lines();

    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    initialize_matrix((int*)matrix, MATRIX_SIZE); // calling the void function intialize_matrix

    Input file_data[num_lines];
    instructions ();
    printf("\nWelcome to shortest route Program\n");

    while (1) //infinite loop for the entering the enter the numbers from the user
    {
        printf("\nPLZ CHOOSE NUMBER FROM THE FOLLOWING MENU TO SELECT THE OPERATION U WANT:\n\n");
        printf("Enter 1 to Read the file segments.txt and load data\n");
        printf("Enter 2 to Enter 2 points to compute the shortest path between them\n");
        printf("Enter 3 to print the route of shortest distance in route.txt file\n");
        printf("Enter 4 to exit!\n");
        printf("Plz Enter your choice: ");

        fgets(buffer, 1000, stdin);
        sscanf(buffer, "%d", &user_input); // read the entered number from the user

        switch (user_input)
        {
        case 1: // the first case and it is the most importan because it let user to read the input file
            read_data((int*)matrix, MATRIX_SIZE, file_data);
            printf("\nFinished Reading Data and now u can choose numbers to know the shortest path!\n\n");
            result_calculated = 0;
            file_read = 1; // sign to confirm that the file has been read
            break;

        case 2:
            if (file_read == 0) // if statement to check if the user has read the file or not
            {
                printf("\nErr.. you need to read the file before calculating distance!\n\n");
            }
            else
            {
                while(1) //infinite loop for the entering the starting and ending point until the user will enter right number for both
                {

                    printf("\nPLZ Enter the starting point: ");
                    fgets(buffer, 1000, stdin);
                    sscanf(buffer, "%d", &start);

                    printf("PLZ Enter the ending point: ");
                    fgets(buffer, 1000, stdin);
                    sscanf(buffer, "%d", &end);

                    // if statements to check that both inputs the start and the end entered in the right way
                    if (start < 0 || end < 0 || start >= MATRIX_SIZE || end >= MATRIX_SIZE)
                    {
                        printf("\nErr....Invalid value for the starting point or the end point\n[U can't enter any negative number or any number that is larger than the max vertex]\n[[plz enter right numbers]]\n");
                    }
                    else if (start == end)
                    {
                        printf("\nThe distance is 0 and there is no path since start and end are the same and u didn't move from one place to other!\n\nPlz enter right numbers\n");

                    }
                    else break;

                }

                {
                    checkinputs(file_data, start, end); // calling check points function to be clear that all inputs are in the file
                    result = find_shortest_distance((int*)matrix, MATRIX_SIZE, start, end, file_data, num_lines); // print the total result
                    result_calculated = 1; // to confirm that there is operation has been done

                    printf("\nThe Distance FROM ( %d ) TO ARRIVE TO ( %d ) is = %d KM\nThe Path is = %s\n%s", start,end,result.distance, result.path,result.towns); // print the informations
                    printf("\n\n");
                    results[num_results] = result;
                    num_results++; // counter
                }
            }
            break;
        case 3: // this case is to save all operations and print them in the output file
            if (result_calculated == 0) // if statement to check if the user has entered inputs or not
            {
                printf("\nErr.. you need to calculate distance before saving!\n\n");
            }
            else
            {
                save_result_to_file(results, num_results); // saving all operations in the output file
                printf("\nDONE!!\nThe data has been Saved in the output file!\n\n All operations u did has been saved and the shortest path for each two numbers will be printed.");
            }
            break;

        case 4: // exit the run screen
            return 0;
        default:
            printf("\nErr..! Invalid option Please try again!\n\n");
            break;
        }
    }
    return 0;
}

// Input function to save all inputs that are in the file for each line

Input find_inputs_from_line(char line[])
{
    int value;
    int counter = 0;
    Input data; // struct input data

    char *town = (char *)malloc(1000 * sizeof(char) + 1); // memory allocation
    int buf_size = 30;
    char *buf = (char *)malloc(buf_size * sizeof(char) + 1);

    snprintf(buf, buf_size, " ");  //Counting the character and storing in buf using snprintf
    strcpy(town, buf); // is equal to town = buf

    char *n = strtok(line, " "); // our reference to cut is the space
    do
    {
        value = atoi(n); // use atoi to change to int
        if (value != 0)  // if value not equal zero enter the if statements
        {
            // if statements to make the first vertex can be either start or end samething for vertex two
            if (counter == 0)
            {
                data.vertex_id_1 = value;
            }
            else if (counter == 1)
            {
                data.vertex_id_2 = value;
            }
            else
            {
                data.weight = value;
            }
            counter++; // plus the counter
        }
        else
        {
            strcat(town, n); // concatination
            snprintf(buf, buf_size, " "); //Counting the character and storing in buf using snprintf
            strcat(town, buf); //(joins) two strings.
        }
    }
    while ((n = strtok(NULL, " "))); // while loop

    data.town = (char *)malloc(strlen(town) + 1);
    strcpy(data.town, town);
    return data; // returning to the function
}

// function to know the path that we must print depend on the numbers that user entered

void get_towns_path(char *towns_path, char *result_path, Input *file_data, int num_lines)
{
    char *n = strtok(result_path, " <-- ");
    int value;
    int prev_vertex = 0; // the previous vertex

    int buf_size = 100;
    char *buf = (char *)malloc(buf_size * sizeof(char) + 1);

    int first_town = 0; // to check the town or city if it has been printed or not to not repeat any thing and use it in the loop
    do
    {
        value = atoi(n); // use atoi to change to int
        if (value != 0)
        {
            if (prev_vertex==0)
            {
                prev_vertex = value;
            }
            else
            {
                //Here we use prev_vertex and value to find the town
                int min_weight = INFINITY;

                char *min_weight_town = (char *)malloc(200 * sizeof(char) + 1);

                // for loop
                for(int i=0; i<num_lines; i++)
                {
                    // if statement to check all situations because in the project all roads are two ways so any number can be starting or ending point

                    if((file_data[i].vertex_id_1 == value && file_data[i].vertex_id_2 == prev_vertex) || (file_data[i].vertex_id_1 == prev_vertex && file_data[i].vertex_id_2 == value))
                    {
                        // in this situation we will print the name of the town that has shortest path if we have
                        // two numbers with two different paths like  1 2 A 90 || 1 2 B 25  so it will only print road B

                        if (min_weight > file_data[i].weight)
                        {
                            min_weight = file_data[i].weight;
                            snprintf(buf, buf_size, "%s",file_data[i].town); //Counting the character and storing in buf using snprintf
                            strcpy(min_weight_town,buf);

                        }
                    }
                }

                if(first_town == 0)
                {
                    snprintf(buf, buf_size, "%s",min_weight_town); //Counting the character and storing in buf using snprintf
                    strcpy(towns_path,buf);
                    first_town ++;
                }
                else
                {
                    snprintf(buf, buf_size, " <--- %s",min_weight_town); //Counting the character and storing in buf using snprintf
                    strcat(towns_path,buf);
                }
                prev_vertex = value;
            }
        }
    }
    while ((n = strtok(NULL, " <-- "))); // infinite loop until we arrive to the destination
}

// output function to know what is the shortest path we must print and the output will depend on the user inputs

Output find_shortest_distance(int *matrix, int MATRIX_SIZE, int start, int end, Input *file_data, int num_lines)
{
    int cost_matrix[MATRIX_SIZE][MATRIX_SIZE], distance[MATRIX_SIZE], pred[MATRIX_SIZE];
    int visited[MATRIX_SIZE], count, minimum_distance, next_node, i, j;

    //Create the cost_matrix matrix using data
    // for loop
    for (i = 0; i < MATRIX_SIZE; i++)                                   // dijkstra algorithm
        for (j = 0; j < MATRIX_SIZE; j++)
            if (matrix[i + j * MATRIX_SIZE] == 0)
                cost_matrix[i][j] = INFINITY;
            else
                cost_matrix[i][j] = matrix[i + j * MATRIX_SIZE];

    //Initialize distance, pred and visited
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        distance[i] = cost_matrix[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

                                                            //Find minimum distance for each node
    while (count < MATRIX_SIZE - 1)
    {
        minimum_distance = INFINITY;

                                                              //nextnode is the Node at minimum distance
        for (i = 0; i < MATRIX_SIZE; i++)
            if (distance[i] < minimum_distance && !visited[i])
            {
                minimum_distance = distance[i];
                next_node = i;
            }

        visited[next_node] = 1;
        for (i = 0; i < MATRIX_SIZE; i++)                      // for loop to calc full distance
            if (!visited[i])
                if (minimum_distance + cost_matrix[next_node][i] < distance[i])
                {
                    distance[i] = minimum_distance + cost_matrix[next_node][i];
                    pred[i] = next_node;
                }
        count++;
    }

                                                          //Finished, now need to create result

    Output result;
    char *output = (char *)malloc(1000 * sizeof(char) + 1);
    result.path = (char *)malloc(1000 * sizeof(char) + 1);
    int buf_size = 100;
    char *buf = (char *)malloc(buf_size * sizeof(char) + 1);

    //If we found a path
    if (distance[end] < INFINITY)
    {
        snprintf(buf, buf_size, "%d", end); //Counting the character and storing in buf using snprintf
        strcpy(output, buf);

        j = end;
        do
        {
            j = pred[j];
            snprintf(buf, buf_size, " <-- %d", j); //Counting the character and storing in buf using snprintf
            strcat(output, buf);

        }
        while (j != start);

        result.path = (char *)malloc(1000 * sizeof(char) + 1);
        strcpy(result.path, output);
        result.distance = distance[end];
    }
    else
    {
        // since the entered start and end has no path between them so we must print the following
        result.path = "No Path";
        result.distance = 0000;
        printf("\nNo Path available for the entered start and end so their won't be any city or town\n");
    }

    char *towns = (char *)malloc(2 * 1000 * sizeof(char) + 200);
    snprintf(buf, buf_size, "The cities/towns you passed FROM ( %d ) TO ARRIVE TO ( %d ) are : ", start, end); // print sentence
    strcpy(towns, buf);

    char *towns_path = (char *)malloc(2 * 1000 * sizeof(char));
    strcpy(towns_path, buf);

    get_towns_path(towns_path, output, file_data, num_lines); // calling the towns path function to print all town we passed to arrive to our destination
    strcat(towns,towns_path);
    result.towns = strdup(towns); // to return a pointer
    return result;
}

// function to calculate the max size in the input file I know the max is 295  but I thought maybe the file in the testing will be different

int get_max_vertex_value()
{

    char line[1000];

    Input data;
    int max_vertex_value = 0;

    //File reading section
    FILE *stream = fopen("segments.txt", "r");
    while (fgets(line, 1000, stream))
    {
        data = find_inputs_from_line(line);

                                                          //Update the max value depending on which ever is bigger
        if (data.vertex_id_1 > max_vertex_value)
        {
            max_vertex_value = data.vertex_id_1;
        }
        if (data.vertex_id_2 > max_vertex_value)
        {
            max_vertex_value = data.vertex_id_2;
        }
    }
    fclose(stream);

    return max_vertex_value; // return the value of max vertex
}

// function to calculate the number of lines depend on the input file data

int get_number_of_lines()
{

    char line[1000];

    int num_lines = 0;

    //File reading section
    FILE *stream = fopen("segments.txt", "r");
    while (fgets(line, 1000, stream))
    {
        num_lines++;
    }
    fclose(stream);

    return num_lines;
}

// function to read the data in the input file
void read_data(int *matrix, int MATRIX_SIZE, Input *file_data)
{
    char line[1000];
    int file_data_index = 0;
    Input data; // struct input data

    //File reading section
    FILE *input_file = fopen("segments.txt", "r"); // intialize the input file
    while (fgets(line, 1000, input_file))
    {
        data = find_inputs_from_line(line);

        //Populate the matrix

        matrix[data.vertex_id_1 + data.vertex_id_2 * MATRIX_SIZE] = data.weight;
        matrix[data.vertex_id_2 + data.vertex_id_1 * MATRIX_SIZE] = data.weight;

        //Populate file data

        file_data[file_data_index].vertex_id_1 = data.vertex_id_1;
        file_data[file_data_index].vertex_id_2 = data.vertex_id_2;
        file_data[file_data_index].weight = data.weight; // the distance
        file_data[file_data_index].town = strdup(data.town);

        file_data_index++;
    }
    fclose(input_file);
}

void save_result_to_file(Output results[100],int num_results)
{
    FILE *output_file = fopen("route.txt", "w"); // intialize the output file
    //Generate an output line from result & save it
    for(int i=0; i<num_results; i++)
    {
        char *output = (char *)malloc(1000 * sizeof(char) + 1);
        snprintf(output, 1000, "The total Distance is : %d\nThe full Path is : %s\n%s\n\n", results[i].distance, results[i].path,results[i].towns); // print stetment
        fputs(output, output_file);
    }
    fclose(output_file); // close output file
}

// void function to intialize and know the value of the adjacency function
void initialize_matrix(int *matrix, int MATRIX_SIZE)
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i + j * MATRIX_SIZE] = 0;
        }
    }
}
// void function to check if any number entered is in the input file or not
void checkinputs(Input *s,int R1,int R2)
{
    int MATRIX_SIZE = get_max_vertex_value();
    int checkFound=0;
    int i=0;
    int from,next;
    int X=0;
    int Y=0;
    while(s[i].vertex_id_1 < MATRIX_SIZE)
    {
        from=s[i].vertex_id_1;
        next=(s[i].vertex_id_2);
        if(R1==from||R1==next)
        {
            X++;                                         // if the x has increased so the input is in the file
        }
        if(R2==from||R2==next)
        {
            Y++;                                          // if the y has increased so the input is in the file
        }
        i++;
    }
    if(X==0)
    {
        printf("\nThe input number %d does not Found in the input file\n",R1); // print statement when the vertex 1 not found
        checkFound++;
    }
    if(Y==0)
    {
        printf("\nThe input number %d does not Found in the input file\n",R2); // print statement when the vertex 2 not found
        checkFound++;
    }
}
