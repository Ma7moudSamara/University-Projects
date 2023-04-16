#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAX 100

typedef struct patient_info
{
    char Patient_name[50];
    char Gender[50];
    char Date_of_admission[50];
    char Date_of_birth[50];
    char Illness[50];
    char Address[50];
    char Blood_type[50];
} info;

typedef struct node *AVLnode;
struct node
{
    info data;
    AVLnode Left;
    AVLnode Right ;
    int Balance;
};

//initialize the new node

AVLnode AVL_tree=NULL;

/////////////////////////////////////////

struct hash_struct
{
    char *Patient_name;
    char *Gender;
    char *Date_of_admission;
    char *Date_of_birth;
    char *Illness;
    char *Address;
    char *Blood_type;
};
//////////////////////////////////////////////////

int Balance(AVLnode AVLtree);
int getBalance(AVLnode N);
int MAX (int x, int y);
AVLnode Rotateleft( AVLnode K2 );
AVLnode rightRotate(AVLnode k3);

//////////////////////////////////////////////////////////////////////////

AVLnode newNODE(info data)
{
    AVLnode T = (AVLnode) malloc(sizeof( struct node));

    strcpy(T->data.Patient_name,data.Patient_name);
    strcpy(T->data.Gender,data.Gender);
    strcpy(T->data.Date_of_admission,data.Date_of_admission);
    strcpy(T->data.Date_of_birth,data.Date_of_birth);
    strcpy(T->data.Illness,data.Illness);
    strcpy(T->data.Address,data.Address);
    strcpy(T->data.Blood_type,data.Blood_type);
    T->Left = NULL;  // left side of AVL tree
    T->Right = NULL; // Right side of AVL tree
    T->Balance = 1;

    return T;
}
//////////////////////////////////////////////////////////////////

AVLnode Insert( AVLnode avl_tree, info data )
{
    if (avl_tree==NULL)
        return newNODE(data);

    if (strcmp(data.Patient_name,avl_tree->data.Patient_name)< 0)  // when the patient name is less than the root so we insert it in the left side
        avl_tree->Left  = Insert(avl_tree->Left,data);

    else if (strcmp(data.Patient_name,avl_tree->data.Patient_name)> 0) // when the patient name is bigger than the root so we insert it in the right side
        avl_tree->Right = Insert(avl_tree->Right, data);

    else
        return avl_tree;

    // Updating the BALANCE of the whole tree

    avl_tree->Balance = 1 + MAX(Balance(avl_tree->Left),Balance(avl_tree->Right));

    int balance = getBalance(avl_tree);

    // left left case
    if (balance > 1 &&(strcmp(data.Patient_name,avl_tree->Left->data.Patient_name)< 0))
        return rightRotate(avl_tree);

    // Right Right Case
    if (balance < -1 && (strcmp(data.Patient_name,avl_tree->Right->data.Patient_name)> 0))
        return Rotateleft(avl_tree);

    // Left Right Case
    if (balance > 1 &&(strcmp(data.Patient_name,avl_tree->Left->data.Patient_name)> 0))
    {
        avl_tree->Left =  Rotateleft(avl_tree->Left);
        return rightRotate(avl_tree);
    }

    // Right Left Case
    if (balance < -1 && (strcmp(data.Patient_name,avl_tree->Right->data.Patient_name)< 0))
    {
        avl_tree->Right = rightRotate(avl_tree->Right);
        return Rotateleft(avl_tree);
    }

    // return the (unchanged) node pointer
    return avl_tree;
}

////////////////////////////////////////////////////////////////////////////////////////////////

//1
// void function to read the data that is entered in the input file (patients) and cut the information
// depend on the # sign to know the patient name , gender ,................

void read_data()
{
    FILE *file_read = fopen("patients.txt","r");  // input file name
    if(file_read==NULL)
    {
        printf("FILE DOES NOT EXIST, PLZ CHECK IT AND TRY AGAIN");
    }
    char st[100];
    while (fgets(st,100,file_read))
    {
        // pointer to cut the line depend on the # sign
        char *f="#";
        char *a = strtok(st,f);
        int count =0; // counter to know when to cut
        info data; // to call the patient information
        while (a!=NULL)
        {
            if (count == 0) // reading the patient name
            {
                strcpy(data.Patient_name,a);
            }
            else if (count == 1) // reading the gender of the patient
            {
                strcpy(data.Gender,a);

            }
            else if (count == 2) // reading the Date_of_admission of the patient
            {
                strcpy(data.Date_of_admission,a);
            }

            if (count == 3) // reading the Date_of_birth of the patient
            {
                strcpy(data.Date_of_birth,a);
            }
            else if (count == 4) // reading the Illness of the patient
            {
                strcpy(data.Illness,a);
            }
            else if (count == 5) // reading the Address of the patient
            {
                strcpy(data.Address,a);
            }
            else if (count == 6) // reading the Blood_type of the patient
            {
                strcpy(data.Blood_type,a);
            }
            count++; // will plus every time we read # sign to save all things depend on the # sign
            if (count == 7)
            {
                AVL_tree = Insert(AVL_tree,data); // insert the whole informations
                count = 0; // start counting from the beginning to read another patient informations
            }
            a = strtok(NULL,f);
        }
    }
    fclose(file_read);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//3
// looking for the entered patient name to update it or delete it depend on the user choice
AVLnode find (AVLnode find_name, info data)
{
    // IF STATEMENTS TO SEARCH FOR THE ENTERED PATIENT NAME IN THE AVL TREE
    if (strcmp(find_name->data.Patient_name,data.Patient_name)==0) // if equal so the patient he is the root
        return find_name;
    if(strcmp(find_name->data.Patient_name,data.Patient_name)>0&&find_name->Left)
        return find(find_name->Left,data);
    if(strcmp(find_name->data.Patient_name,data.Patient_name)<0&&find_name->Right)
        return find(find_name->Right,data);
    else
        printf("The Patient name that you entered does not exist \n");
    return NULL;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//3
// updating the inforamtions of the selected patient

void update (AVLnode update_patient)
{
    info data;
    char temp;
    printf("Enter the patient name to find and then to update the data if you want\n\n");
    scanf("%c",&temp);
    scanf("%[^\n]",data.Patient_name);
    update_patient = find(update_patient,data);
    if(update_patient)
    {
        printf("\nPatient name is : : %s",update_patient->data.Patient_name);
        printf("\nPatient Gender is : %s",update_patient->data.Gender);
        printf("\nDate_of_admission: %s",update_patient->data.Date_of_admission);
        printf("\nDate of birth : %s",update_patient->data.Date_of_birth);
        printf("\nPatient Illness : %s",update_patient->data.Illness);
        printf("\nPatient Address : %s",update_patient->data.Address);
        printf("\nPatient Blood_type : %s",update_patient->data.Blood_type);

        printf("\nPlz choose a number from the following menu to choose what u want to update from the previous informations for the selected patient...\n\n");
        printf("Press 1 to update the Gender\n");
        printf("Press 2 to update date of admission\n");
        printf("Press 3 to update date of birth\n");
        printf("Press 4 to update illness\n");
        printf("Press 5 to update address\n");
        printf("Press 6 to update blood type\n");
        printf("Press 7 to back to the main menu\n\n");
        int x;
        scanf("%d",&x);
        while(x!=7)
        {
            switch(x)
            {
            case 1 : // UPDATE THE GENDER OF THE SELECTED PATIENT
                printf("Enter the new gender of the selected Patient [%s]\n",data.Patient_name);
                char st1 [50];
                scanf("%s",st1);
                strcpy(update_patient->data.Gender,st1);
                break;
            case 2: // UPDATE THE Date_of_admission OF THE SELECTED PATIENT
                printf("Enter the new Date_of_admission of the selected Patient [%s]\n",data.Patient_name);
                char st2 [50];
                scanf("%s",st2);
                strcpy(update_patient->data.Date_of_admission,st2);
                break;
            case 3: // UPDATE THE Date_of_birth OF THE SELECTED PATIENT
                printf("Enter the new date of birth of the selected Patient [%s]\n",data.Patient_name);
                char st3 [50];
                scanf("%s",st3);
                strcpy(update_patient->data.Date_of_birth,st3);
                break;
            case 4: // UPDATE THE Illness OF THE SELECTED PATIENT
                printf("Enter the new illness of the selected Patient [%s]\n",data.Patient_name);
                char st4 [50];
                scanf("%c",&temp);
                scanf("%[^\n]",st4);
                strcpy(update_patient->data.Illness,st4);
                break;
            case 5: // UPDATE THE address OF THE SELECTED PATIENT
                printf("Enter the new address of the selected Patient [%s]\n",data.Patient_name);
                char st5 [50];
                scanf("%c",&temp);
                scanf("%[^\n]",st5);
                strcpy(update_patient->data.Address,st5);
                break;
            case 6: // UPDATE THE Blood_type OF THE SELECTED PATIENT
                printf("Enter the new blood type of the selected Patient [%s]\n",data.Patient_name);
                char st6 [50];
                scanf("%c",&temp);
                scanf("%[^\n]",st6);
                strcpy(update_patient->data.Blood_type,st6);
                break;
            default :
                printf("Wrong choice!!\nplz choose number from 1 to 6 depend on the menu or number 7 to back to main menu\n");
            }
            printf("choose from the following menu to choose what u want to update...\n");
            printf("Press 1 to update Gender\n");
            printf("Press 2 to update admission date\n");
            printf("Press 3 to update date of birth\n");
            printf("Press 4 to update illness\n");
            printf("Press 5 to update address\n");
            printf("Press 6 to update blood type\n");
            printf("Press 7 to back to the main menu\n\n");
            scanf("%d",&x);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//4
void PrintInOrder( AVLnode root)  // left --> root --> right
{
    if( root != NULL)
    {
        PrintInOrder( root->Left );
        printf("\nPatient name is : : %s",root->data.Patient_name);
        printf("\nPatient Gender is : %s",root->data.Gender);
        printf("\nDate_of_admission: %s",root->data.Date_of_admission);
        printf("\nDate of birth : %s",root->data.Date_of_birth);
        printf("\nPatient Illness : %s",root->data.Illness);
        printf("\nPatient Address : %s",root->data.Address);
        printf("\nPatient Blood_type : %s",root->data.Blood_type);
        printf("\n");
        PrintInOrder( root->Right );
    }
}
////////////////////////////////////////////////////////////

//5
void print_illness(AVLnode same_ill, info data)
{
    if (same_ill != NULL)
    {
        print_illness(same_ill->Left, data);

        if ((strcmp(same_ill->data.Illness,data.Illness)==0))
        {
            printf("\nPatient name is : : %s",same_ill->data.Patient_name);
            printf("\nPatient Gender is : %s",same_ill->data.Gender);
            printf("\nDate_of_admission: %s",same_ill->data.Date_of_admission);
            printf("\nDate of birth : %s",same_ill->data.Date_of_birth);
            printf("\nPatient Illness : %s ",same_ill->data.Illness);
            printf("\nPatient Address : %s ",same_ill->data.Address);
            printf("\nPatient Blood_type : %s ",same_ill->data.Blood_type);
            printf("\n");
        }

        print_illness(same_ill->Right, data);
    }
}


////////////////////////////////////////////////////////////////

AVLnode find_min(AVLnode root)
{
    if(root==NULL)
        return root;
    else if(root->Left!=NULL)
        return find_min(root->Left);
    else
        return root;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//6
AVLnode Deletion_patientIN_TREE(AVLnode n, info data)
{
    if (n == NULL)
        return n;

    if (strcmp(n->data.Patient_name,data.Patient_name) > 0)
        n->Left = Deletion_patientIN_TREE(n->Left, data);

    else if (strcmp(n->data.Patient_name,data.Patient_name) < 0)
        n->Right = Deletion_patientIN_TREE(n->Right, data);

    else
    {
        if ((n->Left == NULL) || (n->Right == NULL))
        {
            struct node *temp = n->Left ? n->Left : n->Right;

            if (temp == NULL)
            {
                temp = n;
                n = NULL;
            }
            else
                *n = *temp;

            free(temp);
        }
        else
        {
            struct node *temp = find_min(n->Right);
            strcpy(n->data.Patient_name, temp->data.Patient_name);
            strcpy(n->data.Gender, temp->data.Gender);
            strcpy(n->data.Date_of_admission, temp->data.Date_of_admission);
            strcpy(n->data.Date_of_birth, temp->data.Date_of_birth);
            strcpy(n->data.Illness, temp->data.Illness);
            strcpy(n->data.Address, temp->data.Address);
            strcpy(n->data.Blood_type, temp->data.Blood_type);

            n->Right = Deletion_patientIN_TREE(n->Right, temp->data);
        }
    }

    if (n == NULL)
        return n;

    n->Balance = 1 + MAX(Balance(n->Left),Balance(n->Right));

    int balance = getBalance(n);


    if (balance > 1 && getBalance(n->Left) >= 0)
        return rightRotate(n);

    if (balance > 1 && getBalance(n->Left) < 0)
    {
        n->Left = Rotateleft(n->Left);
        return Rotateleft(n);
    }

    if (balance < -1 && getBalance(n->Right) <= 0)
        return Rotateleft(n);

    if (balance < -1 && getBalance(n->Right) > 0)
    {
        n->Right = rightRotate(n->Right);
        return Rotateleft(n);
    }

    return n;
};

//////////////////////////////////////////////////////////////////////

//7

void save_data (AVLnode node, FILE*f)
{
    if (node != NULL)
    {
        // saving the data and print it int output file in the inorder way

        save_data(node->Left, f);
        fputs(node->data.Patient_name, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Gender, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Date_of_admission, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Date_of_birth, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Illness, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Address, f);
        fputs("#", f); // this sign because it will help me to read the information from the patients_hash table when it is input file for hash table

        fputs(node->data.Blood_type, f);
        save_data(node->Right, f);
    }
}

//////////////////////////////////////////////////////////////////

char *read_hash(char *p, int n)
{
    char *cut;
    for (cut = strtok(p, "#"); cut && *cut; cut = strtok(NULL, "#\n"))
    {
        if (!--n)
            return cut;
    }
    return NULL;
}

//////////////////////////////////////////////////////////////////////

int hash_function(char *n)
{
    int k = 0;
    int temp=0;
    int length = strlen(n);
    for(int i=0; i<length ; i++)
    {
        temp = n[i];
        k += temp;
    }
    return k % 100;
}
////////////////////////////////////////////////////////////////////////

int Insert_h(struct hash_struct *insartion, char *Patient_name, char *Gender, char *Date_of_admission,char *Date_of_birth,char *Illness,char *Address,char *Blood_type, int hash_size)
{
    int m = hash_function(Patient_name);
    int i;
    for( i=m; i<100; i++)
    {
        if(insartion[i].Patient_name == NULL)
        {
            insartion[i].Patient_name = malloc(sizeof(char *) * strlen(Patient_name));
            insartion[i].Patient_name = Patient_name;

            insartion[i].Gender = malloc(sizeof(char *) * strlen(Gender));
            insartion[i].Gender = Gender;

            insartion[i].Date_of_admission = malloc(sizeof(char *) * strlen(Date_of_admission));
            insartion[i].Date_of_admission = Date_of_admission;

            insartion[i].Date_of_birth = malloc(sizeof(char *) * strlen(Date_of_birth));
            insartion[i].Date_of_birth = Date_of_birth;

            insartion[i].Illness = malloc(sizeof(char *) * strlen(Illness));
            insartion[i].Illness = Illness;

            insartion[i].Address = malloc(sizeof(char *) * strlen(Address));
            insartion[i].Address = Address;

            insartion[i].Blood_type = malloc(sizeof(char *) * strlen(Blood_type));
            insartion[i].Blood_type = Blood_type;

            hash_size++;
            return hash_size;
        }
    }
    return hash_size;

};

////////////////////////////////////////////////////////////////////////////////

struct hash_struct *int_hash(struct hash_struct* n)
{
    n = (struct hash_struct*) malloc( 100 * sizeof(struct hash_struct));
    int i;
    for(i=0; i<100; i++)
    {
        n[i].Patient_name = NULL;
    }
    return n;
};

////////////////////////////////////////////////////////////////

void print_hash(struct hash_struct* n)
{

    for(int i=0; i<100; i++)
    {
        if(n[i].Patient_name == NULL)

            printf("\n");

        else
        {

            printf("\nPatient name is : : %s",n[i].Patient_name);
            printf("\nPatient Gender is : %s",n[i].Gender);
            printf("\nDate_of_admission: %s",n[i].Date_of_admission);
            printf("\nDate of birth : %s",n[i].Date_of_birth);
            printf("\nPatient Illness : %s ",n[i].Illness);
            printf("\nPatient Address : %s ",n[i].Address);
            printf("\nPatient Blood_type : %s ",n[i].Blood_type);
            printf("\n");
        }
    }
}

//////////////////////////////////////////////////////////////////////////

void search_hash(struct hash_struct* s_hash)
{

    char x[100];
    char *Patient_name;

    printf("Enter the name of the patient that u want to search for him or her: ");
    fgets(x, 100, stdin);
    Patient_name = strdup(x);
    Patient_name[strcspn(Patient_name, "\n")] = 0;

    int a = hash_function(Patient_name);
    int i;

    for(i=a; i<100; i++)
    {
        if(s_hash[i].Patient_name==NULL)
        {
            printf("\nSorry The patient that u entered is not found\n");
            return;
        }

        if(strcmp(Patient_name,s_hash[i].Patient_name)==0)
        {
            printf("\nPatient name is : : %s",s_hash[i].Patient_name);
            printf("\nPatient Gender is : %s",s_hash[i].Gender);
            printf("\nDate_of_admission: %s",s_hash[i].Date_of_admission);
            printf("\nDate of birth : %s",s_hash[i].Date_of_birth);
            printf("\nPatient Illness : %s ",s_hash[i].Illness);
            printf("\nPatient Address : %s ",s_hash[i].Address);
            printf("\nPatient Blood_type : %s ",s_hash[i].Blood_type);
            printf("\n");
            return;
        }
    }
    printf("\nSorry The patient that u entered is not found\n");
    return;
}


int delete_hash(struct hash_struct *array,int size)
{
    char *Patient_name;
    char buffer[100];
    printf("Enter the name of the patient the you want to delete: ");
    fgets(buffer, 100, stdin);
    Patient_name = strdup(buffer);
    Patient_name[strcspn(Patient_name, "\n")] = 0;

    int key = hash_function(Patient_name);
    int i;

    for(i=key; i<100; i++)
    {
        if(array[i].Patient_name==NULL)
        {
            printf("\nThere is no any name of the patient that you entered\n");
            return size;
        }

        if(strcmp(Patient_name,array[i].Patient_name)==0)
        {

            free(array[i].Patient_name);
            free(array[i].Gender);
            free(array[i].Date_of_admission);
            free(array[i].Date_of_birth);
            free(array[i].Illness);
            free(array[i].Address);
            free(array[i].Blood_type);

            array[i].Patient_name = NULL;

            printf("\nThe patient that u entered has successfully deleted !\n");
            size--;
            return size;
        }
    }
    printf("\nNo any patient in this name so there is no any information for him or her\n");
    return size;
}

///////////////////////////////////////////////////////////////////////

void save_hash(struct hash_struct *array)
{
    FILE *out = fopen("patients_hash.data", "w");

    for(int i=0; i<100; i++)
    {
        if(array[i].Patient_name==NULL)
            continue;
        else
        {

            fputs("The Patient name is :",out);
            fputs(array[i].Patient_name, out);

            fputs("\nThe Gender of the Patient is :",out);
            fputs(array[i].Gender, out);

            fputs("\nThe Date_of_admission of the Patient is :",out);
            fputs(array[i].Date_of_admission, out);

            fputs("\nThe Date_of_birth of the Patient is :",out);
            fputs(array[i].Date_of_birth, out);

            fputs("\nThe Illness of the Patient is :",out);
            fputs(array[i].Illness, out);

            fputs("\nThe Address of the Patient is :",out);
            fputs(array[i].Address, out);

            fputs("\nThe Blood type of the Patient is :",out);
            fputs(array[i].Blood_type, out);
            fputs("\n\n", out);
        }
    }
    fclose(out);
}
void menu2()
{
    printf("\nWelcome to the HASH TABLE main menu:");
    printf("\nPlease Choose a number From the following Menu :\n");
    printf("1.Print hashed table (i.e., print the entire table to the screen including empty spots).\n");
    printf("2.Print out table size\n");
    printf("3.Print out the used hash function.\n");
    printf("4.Insert a new record into the hash table\n");
    printf("5.Search for a specific patient\n");
    printf("6.Delete a specific record.\n");
    printf("7.Save hash table back to file called (patients_hash.data)\n");
    printf("8.Exit\n");
}

int hash_main()
{
    struct hash_struct *array = NULL;
    int size=0;
    char temp;
    array = int_hash(array);

    FILE *read = fopen("patients_hash.data", "r");

    char line[1024];
    int num_lines = 0;
    char *Patient_name, *Gender, *Date_of_admission, *Date_of_birth, *Illness, *Address, *Blood_type;
    while (fgets(line, 1024, read))
    {
        if (num_lines == 0)
        {
            num_lines++;
            continue;
        }

        char *t = strdup(line);
        Patient_name = strdup(read_hash(t, 1));
        free(t);

        t = strdup(line);
        Gender = strdup(read_hash(t, 2));
        free(t);

        t = strdup(line);
        Date_of_admission = strdup(read_hash(t, 3));
        free(t);

        t = strdup(line);
        Date_of_birth = strdup(read_hash(t, 4));
        free(t);

        t = strdup(line);
        Illness = strdup(read_hash(t, 5));
        free(t);

        t = strdup(line);
        Address = strdup(read_hash(t, 6));
        free(t);

        t = strdup(line);
        Blood_type = strdup(read_hash(t, 7));
        free(t);
        size = Insert_h(array, Patient_name, Gender, Date_of_admission, Date_of_birth, Illness, Address, Blood_type,size);
    }
    fclose(read);


    int user_input;
    menu2();
    printf("\nPlZ ENTER YOUR CHOICE FROM THE PREVIOUS MENU: ");
    scanf("%d",&user_input);
    char count_hash [100];
    while (user_input!=8)
    {


        fgets(count_hash, 100, stdin);
        sscanf(count_hash, "%d", &user_input);

        if (user_input==1)
        {
            print_hash(array);
        }
        else if (user_input==2)
        {
            printf("\nThe number of records in the hash table is : [ %d ] ",size);
            printf("\nThe total size of hash table is : [ %d ]  that is the maximum size that I defined for my hash table",HASH_MAX);
            printf("\n");
        }
        else if (user_input==3)
        {
            printf("\nThe function that I used in my code is open addressing function in specific Linear Hashing (Linear probing)\nAfter adding all values they will be module by 100 its the max size of hash that I entered");
            printf("\nIn this kind of hash we will Try all cells sequentially with wraparounds in search of an empty cell\n [[h(x) = (function + i) module size]]\n");
        }
        else if (user_input==4)
        {
            printf("\nPlz enter the following informations for the patient to Insert him or her\n");
            printf("Enter the name of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Patient_name);//Scan the Patient_name to insert
            printf("\nEnter the gender of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Gender);//Scan the Gender to insert
            printf("\nEnter the admission date of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Date_of_admission);//Scan the Date_of_admission to insert
            printf("\nEnter the date of birth of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Date_of_birth);//Scan the Date_of_birth to insert
            printf("\nEnter the illness of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Illness);//Scan the Illness to insert
            printf("\nEnter the address of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Address);//Scan the Address to insert
            printf("\nEnter the blood type of new patient: ");
            scanf("%c",&temp);
            scanf("%[^\n]",Blood_type);//Scan the Blood_type to insert;

            Insert_h(array, Patient_name, Gender, Date_of_admission, Date_of_birth, Illness, Address, Blood_type,size);

            printf("\n[[The new patient has been Inserted]]\n\n");

        }

        else  if (user_input==5)
        {
            search_hash(array);
        }
        else if (user_input==6)
        {
            size = delete_hash(array,size);
        }
        else if (user_input==7)
        {
            save_hash(array);
            printf("THE DATA HAS BEEN SAVED SUCCESFULLY IN patients_hash.data FILE\n");

        }
        menu2();
        printf("\nPlZ ENTER YOUR CHOICE FROM THE PREVIOUS MENU: ");

        scanf("%d",&user_input);
    }

    return 0;
}


//////////////////////////////////////////////////////////

void instructions ()
{
    printf("My program is implement a system to manage patients data in a hospital.");
    printf("The hospital patient management system stores specific information in the form of health record to keep track of the patients data : \n");
    printf("1.Be sure that you have a file named patients.txt\n");
    printf("2.Be sure that you entered the patients informations and data in the file if not please put your patients informations in a file named patients.txt\n");
    printf("3.Be sure that the file is added in the code folder and it has been read successfully\n");
    printf("4.Thank you for using my program and I hope you enjoy it. \n");
    printf("----------------------------\n");
}
void menu1()
{
    printf("\nPlease Choose a number From the following Menu :\n");
    printf("1.Read the patients file and load the data\n");
    printf("2.Insert a new patient from your choice with all its associated data\n");
    printf("3.Find a patient and you can have the chance for updating information of the patient if found.\n");
    printf("4.List all patients in lexicographic order with their associated information\n");
    printf("5.List all patients that have the same illness\n");
    printf("6.Delete a patient from the system\n");
    printf("7.Save all patients in a file called (patients_hash.data) and move to the hash table main menu\n");
}



int main()
{
    printf("Welcome to my program!\n\n");
    printf("if you want to know what my program do and want to read the instructions press any key to continue but not (0) \n*********************************************************\n");
    int f=0;
    info data;
    char temp;
    FILE *out_file;
    char first_number = '0';
    scanf("%c",&first_number);
    if(first_number!=0)
        instructions();

    int choice;
    menu1();
    printf("\nPlZ ENTER YOUR CHOICE FROM THE PREVIOUS MENU: ");
    scanf("%d",&choice);
    while(choice!=8)
    {

        if (choice==1)
        {
            read_data();
            printf("\nFILE HAS BEEN READ AND HAS BEEN DONE \n");
            f = 1 ; // sign to confirm that the input file has been read
        }
        else if (choice==2)
        {
            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");

            else
            {
                printf("\nPlz enter the following informations for the patient to Insert him or her\n");
                printf("Enter the name of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Patient_name);//Scan the Patient_name to insert
                printf("\nEnter the gender of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Gender);//Scan the Gender to insert

                printf("\nEnter the admission date of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Date_of_admission);//Scan the Date_of_admission to insert

                printf("\nEnter the date of birth of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Date_of_birth);//Scan the Date_of_birth to insert

                printf("\nEnter the illness of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Illness);//Scan the Illness to insert
                printf("\nEnter the address of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Address);//Scan the Address to insert
                printf("\nEnter the blood type of new patient: ");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Blood_type);//Scan the Blood_type to insert;
                AVL_tree = Insert(AVL_tree,data);

                printf("\n[[The new patient has been Inserted]]\n\n");

            }
        }
        else if (choice==3)
        {
            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");


            else
            {
                update(AVL_tree);

            }

        }

        else if (choice==4)
        {
            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");

            else
            {

                printf("\nThe Patients informations in the inorder way ( left --> root --> right ) are as the following:\n");
                PrintInOrder(AVL_tree);

            }
        }
        else if (choice==5)
        {

            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");

            else
            {
                printf("Enter the name of the Illness to print all patients who has this Illness\n\n");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Illness);
                print_illness(AVL_tree,data);
            }
        }
        else if (choice==6)
        {

            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");

            else
            {
                printf("Enter the name of the patient that u want to delete\n\n");
                scanf("%c",&temp);
                scanf("%[^\n]",data.Patient_name);
                Deletion_patientIN_TREE(AVL_tree,data);
            }
        }

        else if (choice==7)
        {

            if(f == 0)
                printf("SOMETHING WRONG PLZ YOU should read the FILE AT THE FIRST\n");

            else
            {
                out_file = fopen("patients_hash.data", "w");
                fputs("Patient Name#Gender#Date of admission#Date of birth#Illness#Address (city)#Blood type\n",out_file);
                //save data, close file and open it again to be an input file for the hash table
                save_data(AVL_tree, out_file);
                printf("\nTHE DATA HAS BEEN SAVED SUCCESFULLY IN patients_hash.data FILE\n");
                fclose(out_file);
                return hash_main();
            }
        }


        menu1();
        printf("\nPlZ ENTER YOUR CHOICE FROM THE PREVIOUS MENU: ");
        scanf("%d",&choice);
    }

}

// function to get the balannce of the AVL tree
int Balance(AVLnode AVLtree)
{
    if(AVLtree==NULL)
        return 0;
    else
        return AVLtree->Balance;
}

///////////////////////////////////////////////////////////////////////////////////////////
int getBalance(AVLnode N)
{
    if (!N)
        return 0;
    return Balance(N->Left) - Balance(N->Right);
}
////////////////////////////////////////////////////////////////////////////////////////
int MAX (int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

////////////////////////////////////////////////////////////////////////////////////////////

AVLnode Rotateleft( AVLnode K2 )
{
    AVLnode y = K2->Right;
    AVLnode T2 = y->Left;

    // Perform rotation
    y->Left = K2;
    K2->Right = T2;

    //  Update heights
    K2->Balance = MAX(Balance(K2->Left), Balance(K2->Right))+1;
    y->Balance = MAX(Balance(y->Left), Balance(y->Right))+1;

    // Return new root
    return y;
}
///////////////////////////////////////////////////////////////////////////////////////////////
AVLnode rightRotate(AVLnode k3)
{
    AVLnode x = k3->Left;
    AVLnode T2 = x->Right;

    // Perform rotation
    x->Right = k3;
    k3->Left = T2;

    // Update heights
    k3->Balance = MAX(Balance(k3->Left), Balance(k3->Right))+1;
    x->Balance = MAX(Balance(x->Left), Balance(x->Right))+1;

    // Return new root
    return x;
}
