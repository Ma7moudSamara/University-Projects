// MAHMOUD SAMARA       1191602      COMP2421    SEC 4      PROJECT 2

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//struct node implementation
typedef struct node* PtoNode;
typedef PtoNode Stack;

struct node
{
    char informations[100];
    PtoNode n;

};

int IsEmpty( PtoNode S );
void add_stack(PtoNode Add_S, char a[]);
void pop( PtoNode Sp );
void push(PtoNode S,char x[]);
void undo(PtoNode s);
void print(Stack S);
void save(FILE* F, Stack S_print);

void redo(PtoNode P, char *X){

struct node* temp= (PtoNode)malloc(sizeof(struct node));

//temp->informations = X
strcpy(temp->informations , X);
temp->n = P->n;
P->n = temp;

}

void menu ()
{
    printf("****Welcome to my program this program is simulation of a simple text editor\n\n****Please choose the command that you want from the following menu after writing your statements****\n\n");
    printf("Menu : \n");
    printf("1.If you write (undo): this will remove that last entered statement \n");
    printf("2.If you write (redo): this will redo re-add that last removed statement \n");
    printf("3.If you write (print): this command will print the entire stored input text \n");
    printf("4.If you write (save): will save the text to a file called (output.txt); \n");
    printf("5.If you write quit: will exit the program and save all results to output.txt \n\n");
    printf("                                       **** NOTE****\nIf the Stack were empty the program will close and if any line has more than 100 character it will print");
    printf("\nerror message and quit.So plz understand these notes before u test my program \n\n");

}

int main()
{
    menu();
    char  str[100]; // intialize the string char and its maximum number of char is 100
    int m;
    m = strlen(str); // int m is equal to string length to check if the length is less than or equal 100
    Stack program_stack  =(PtoNode)malloc(sizeof(struct node)) ;
    program_stack->n=NULL;

    FILE* FilePrint ;

    // infinite loop
     while(1)
    {
        printf("MyCommand> ");
        gets(str);

// if statement to check if the number of characters in a line is less than or equal 100
//if yes it will continue if no it will return to the beginning and I wrote > 99 because we start count from 0
        if (m > 99)
        {
            printf("Something went wrong because one of the entered lines has more than 100 characters\n\n");
            main();
        }


       //if input is undo then do the following
        else if(strcmp("undo",str)==0)
        {
            undo(program_stack);
            printf("\nresult >\n");
            print(program_stack);
        }

      //if input is redo then do the following
        else if(strcmp("redo",str)==0)
        {
            redo(program_stack,str);
            printf("\nresult >\n");
            print(program_stack);

        }

        else if(strcmp("save", str)==0)        //if input is save then do the following
        {
            FilePrint=fopen("output.txt","w");
            save(FilePrint,program_stack);
            fclose(FilePrint);
            printf("\n<<the text has been saved into a file called (output.txt)>>\n\n");
        }

        //if entered string is print so it will print all inputs
        else if(strcmp("print",str)==0)
        {

            printf("\nresult >\n");
            print(program_stack);
        }

        //if entered string is quit so it will out from the program
        else if(strcmp("quit",str)==0)
        {

            FilePrint=fopen("output.txt","w");
            save(FilePrint,program_stack);
            fclose(FilePrint);
            printf("\nresult > Good Bye!\n");
            exit(0);

        }

        //if input is any other string  then add it to stack to store it using add function

        else
            add_stack(program_stack,str);
    }

    return 0;
}

// function for add values and written informations to stack
void add_stack(PtoNode Add_S, char a[])
{
    PtoNode tp;
    tp=(PtoNode)malloc(sizeof (struct node));
    strcpy(tp->informations,a);
    while(Add_S->n!=NULL)
    {
        Add_S=Add_S->n;
    }
    Add_S->n=tp;
    tp->n=NULL;
    int Z = 0;
    Z++;

}
//This function is to implement pop to pop string from stack
void pop( PtoNode Spop )
{

    PtoNode tempPOP;

    if( Spop == NULL)

        printf( "Empty stack");

    while(Spop->n->n!=NULL)
    {
        Spop =Spop->n;
    }
    tempPOP = Spop->n;
    Spop->n = tempPOP->n;
    free( tempPOP );
}

//This function is to implement push to push string into stack
void push(PtoNode S,char arrpush[])
{
    PtoNode temp;

    temp=(PtoNode)malloc(sizeof(struct node));//create new node

    if(temp==NULL)
        printf( "The Stack is empty!, plz write data in the stack to print it");

    strcpy(temp->informations,arrpush);
    temp->n = S->n;
    S->n = temp;

}

//undo function
void undo(PtoNode s)
{
    if (s==NULL)
    {
        return;
    }

    pop(s);
}

// void function to make the print for the data in the stack to use it in main
void print(PtoNode L)
{
    L=L->n;
    if(L == NULL)
        return ;

    printf("%s\n",L->informations);
    print(L);
}

//function for save in file
void save(FILE* F, Stack S_print)
{
    if(S_print->n == NULL)
        return;
     fprintf(F,"%s\n",S_print->n->informations);
     save(F, S_print->n);
}
