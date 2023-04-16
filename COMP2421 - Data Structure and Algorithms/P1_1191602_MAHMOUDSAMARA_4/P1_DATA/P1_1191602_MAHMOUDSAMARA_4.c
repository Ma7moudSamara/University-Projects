// MAHMOUD SAMARA       1191602      COMP2421    SEC 4      PROJECT 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


struct Node {
	int coefficient;
	int power;
	struct Node* next;
	struct Node* prev;
};
struct DLL {
    struct Node* head;
    struct Node* tail;
};
void DLL_parts(struct DLL* List)
{
    List->head =NULL;
    List->tail =NULL;
}

struct DLL* dLL[1000];
int PynomialCOEFF[1000][1000];
int pynomialPOW[1000][1000];
int counter  = 0;
int Cequation  = -1;
int numberOfEquations = 0;

////////////////////////////////////////////////
void extraction(char extract[], char sign[1000], int X) {
    int M = 0;
    int count = 0;
    while (M < strlen(extract)) {
        if (extract[M] == 'x') {
            count++;
        }
        if (extract[M] == '^') {
            count++;
        }
        M++;
    }
    int i = 0;
    char coefficient[10];
    char power[10];
    while (extract[i] != 'x' && i < strlen(extract)) {
        coefficient[i] = extract[i];
        i++;
    }
    //atoi converts the string argument str to an integer (type int) since we have char
   //coefficient so we will convert it to int to make the if statemnt .

    int convTOint1  = atoi(coefficient);
    if (convTOint1  == 0) {
        convTOint1  = 1;
    }
    if (sign[X] == '-') {
        convTOint1  = convTOint1  * (-1);
    }

    i = strlen(extract) - 1;
    int j = 0;
    while (extract[i] != '^' && i > 0) {
        power[j] = extract[i];
        j++;
        i--;
    }
   //atoi converts the string argument str to an integer (type int) since we have char
   //power so we will convert it to int to make the if statemnt .

    int convTOint2  = atoi(power);
    if (count == 1) {
        convTOint2  = 1;
    }
    else if (count == 0) {
        convTOint2  = 0;
    }

    if (X == 0) {
        counter = 0;
        Cequation ++;
    }
    PynomialCOEFF[Cequation ][counter] = convTOint1;
    pynomialPOW[Cequation ][counter] = convTOint2 ;
    counter++;

}
//////////////////////////////////////////////////////////////////

void changing_the_equation(char t[100]) {

    int i = 0;
int num = 0;
int j = 1;
    char sign[10];
    if (t[0] != '-') {
        sign[0] = '+';
    }
    else if (t[0] == '-') {
        sign[0] = '-';
        j--;
    }
    while (i < strlen(t)) {
        if (t[i] == '+' || t[i] == '-') {
            sign[j] = t[i];
            j++;
        }
        i++;
    }
    const char* d = "+-";
    char *token;



    token = strtok(t, d);


    while(token != NULL) {
        extraction(token, sign, num);
        num++;

        token = strtok(NULL, d);
    }
}
//////////////////////////////////////////////////////////////////////

void readEquations() {
 FILE *FILE_INPUT;
 //int p = 1;
    char str[100];
    char* filename = "equations.txt";

    FILE_INPUT = fopen(filename, "r");
    if (FILE_INPUT == NULL){
        printf("Could not open file %s",filename);
        return;
    }
    while (fgets(str, 100, FILE_INPUT) != NULL) {
            numberOfEquations++;
        changing_the_equation(str);
    }
    fclose(FILE_INPUT);
}
////////////////////////////////////////////////////////////////////////////

void Insert(struct DLL* Insert_L,int cons, int p) {

  struct Node* temp;
  temp = (struct Node*)malloc(sizeof(struct Node));
  temp->coefficient = cons;
  temp->power = p;
  if (!Insert_L->tail) {

    Insert_L->tail = temp;
    Insert_L->tail->next = NULL;
    Insert_L->tail->prev = NULL;
    Insert_L->head = Insert_L->tail;
    return;
  }
  Insert_L->tail->next = temp;
  temp->next = NULL;
  temp->prev =Insert_L->tail;
  Insert_L->tail = temp;
}
//////////////////////////////////////////////////

void implementDLL() {
    int a = 0;
    int b = 0;
    while (a < numberOfEquations) {
        if (PynomialCOEFF[a][b] != 0) {
        Insert(dLL[a], PynomialCOEFF[a][b], pynomialPOW[a][b]);}
        if (PynomialCOEFF[a][b] == 0) {
            a++;
            b = -1;
        }
        b++;
    }
}

/////////////////////////////////////////////////////////

void Display(struct DLL *Dis_L) {
  struct Node* temp ;
  temp = Dis_L->head;
  printf("\n**** [ ");
   while (temp) {
    if (temp->coefficient >= 0) {
      printf("+");
    }
    printf("%dx^%d ",temp->coefficient,temp->power);
    temp = temp->next;
  }
printf(" ] ****\n");
}
///////////////////////////////////////////////////

void X_value(struct DLL *List,int x) {
  int answer = 0;
  struct Node* tp ;
  tp = List->head;
  while (tp) {
  	int p = pow(x, tp->power);
    answer = answer + (tp->coefficient *  p);
    tp = tp->next;
  }
  printf("\nThe value of X  is = [ %d  ]   then the result for this equation is : [ %d  ]\n",x,answer);
}

/////////////////////////////////////////////////////////////

void Simplify(struct DLL* temp) {
    // This function iterates through the polynomial and add/subtracts similar terms
	struct Node* ptr1 = temp->head;
	struct Node* ptr2;
	struct Node* duplicate;

	while (ptr1 && ptr1->next) {
		ptr2 = ptr1;
		while (ptr2->next) {
			if (ptr1->power == ptr2->next->power) {
				ptr1->coefficient = ptr1->coefficient + ptr2->next->coefficient;
				duplicate = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(duplicate);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}
/////////////////////////////////////////////////////////////////////////

struct DLL* Addition(struct DLL* eq1,struct DLL* eq2) {
	struct DLL* result;
	result =(struct DLL*)malloc(sizeof(struct DLL));
    DLL_parts(result);
	struct Node* p1 = eq1->head;
	struct Node* p2 = eq2->head;
	while (p1) {
        Insert(result, p1->coefficient, p1->power);
        p1 = p1->next;
	}
    while (p2) {
        Insert(result,p2->coefficient, p2->power);
        p2 = p2->next;
    }
    Simplify(result);
	return result;
}
struct DLL* Subtraction(struct DLL* eq1,struct  DLL* eq2) {

	struct DLL* result=(struct DLL*)malloc(sizeof(struct DLL));
    DLL_parts(result);
	struct Node* p1 = eq1->head;
	struct Node* p2 = eq2->head;
	while (p1) {
        Insert(result, p1->coefficient, p1->power);
        p1 = p1->next;
	}
    while (p2) {
        Insert(result, (-1)*(p2->coefficient), p2->power);
        p2 = p2->next;
    }
    Simplify(result);
	return result;
}

///////////////////////////////////////////////////////////////

struct DLL* Multiplication(struct DLL* operand1,struct  DLL* operand2) {


		struct DLL* tempList=(struct DLL*)malloc(sizeof(struct DLL));
        DLL_parts(tempList);
		struct Node* polynomial1 = operand1->head;
		struct Node* polynomial2 = operand2->head;
		// Iterates through both polynomials by taking one term and finding its similar term in second polynomial then multiplies the coefficients and sums the power  of the term
		while (polynomial1) {
			while (polynomial2) {
				Insert(tempList,(polynomial2->coefficient * polynomial1->coefficient), (polynomial2->power + polynomial1->power));
				polynomial2 = polynomial2->next;
			}
			polynomial1 = polynomial1->next;
			polynomial2 = operand2->head;
		}
		Simplify(tempList);
		return tempList;
}

void resultOFequations(struct DLL *List, int op){

    FILE *fptr;
    fptr = fopen("results.txt", "a");

    if (fptr == NULL) {
        printf("Error! there is something wrong happened");
        exit(1);
    }
	if (op == 3)
    {
        fprintf(fptr, "\nSum equations is : ");
    }
    else if (op == 4)
    {
        fprintf(fptr, "\nSubtraction equations is: ");
    }
    else if (op == 5)
    {
        fprintf(fptr, "\nMultiplication equations is: ");
    }

	struct Node* temp;
	temp = List->head;
  	while (temp) {
    	if (temp->coefficient >= 0) {
      		fprintf(fptr, "+");
    	}
    	fprintf(fptr, "%dx^%d",temp->coefficient,temp->power);

    	temp = temp->next;
    }

    fclose(fptr);
}

//////////////////////////////////////////


void menu()
{
    printf("Menu : \n");
    printf("1.Read From File Named equations.txt \n");
    printf("2.Print The Equations that was read On The Screen \n");
    printf("3.Find The Sum Of The Equations \n");
    printf("4.Find The Subtraction Of The Equations \n");
    printf("5.Find The Multiplication Of The Equations \n");
    printf("6.Substitute A Value In the Sum Equation \n");
    printf("7.Substitute A Value In the Subtraction Equation \n");
    printf("8.Substitute A Value In the Multiplication Equation \n");
    printf("9.Substitute A Value In all Equation \n");
    printf("10.Exit\n");
    printf("\nEnter the number of operation that u want from the previous menu : ");
}
void instructions ()
{
    printf("My program is implement a Polynomial ADT using Linked Lists. You can choose the implementation that you want\nSuch as : the Multiplication, Addition, and Subtraction operations of polynomials.\n\nInstructions to use the program : \n");
    printf("1.Be sure that you entered the equations in the file if not please put your equations in a file named equations.txt\n");
    printf("2.Be sure that the file is added in the code folder and it has been read succesfully\n");
    printf("3.If you want to try to enter a value of x for any equation first you have to be sure that the wanted equation has been printed\n");
    printf("4.Thank you for using my program and I hope you enjoy it. \n");
    printf("----------------------------\n");
}

int main() {
    int count  = 0;
    for (count  = 0; count  < 1000; count ++) {
        dLL[count ]=(struct DLL*)malloc(sizeof(struct DLL));
        DLL_parts(dLL[count ]);
    }
  int Sum_operation_ready = 0;
  int Sub_operation_ready = 0;
  int mul_operation_ready = 0;
    struct DLL* add;
    struct DLL* sub;
    struct DLL* mul;
  // MENU OF POLYNOMIAL
  int enterd_choice;;
  int x;
  printf("Welcome to my program!\n\n");
    printf("if you want to know what my program do and want to read the instructions press any key to continue but not (0) \n*********************************************************\n");
    char first_number = '0';
    scanf("%c",&first_number);
    if(first_number!=0)
  instructions();
    menu();
  scanf("%d",&enterd_choice);
	while (enterd_choice != 0) {
        if (enterd_choice == 1) {
			readEquations();
			implementDLL();
			printf("\n\nFile Read \n");

		}
		else if (enterd_choice == 2) {
                printf("\n\nEquations has been Read from File: \n\n");
                int v = 0;
            for (v = 0; v < numberOfEquations; v++) {
                printf("%d. ", v+1);
                Display(dLL[v]);
            }
		}
		else if (enterd_choice == 3) {
            int b = 2;

            add = Addition(dLL[0], dLL[1]);

            while (b < numberOfEquations) {
                add = Addition(add, dLL[b]);
                b++;
            }
		    printf("\n\nAddition Result\n\t");
            Display(add);
            Sum_operation_ready = 1;

		}
		else if (enterd_choice == 4) {
            int d = 2;

            sub = Subtraction(dLL[0], dLL[1]);

            while (d < numberOfEquations) {
                sub = Subtraction(sub, dLL[d]);
                d++;
            }
            printf("\n\nSubtraction Result\n\t");
            Display(sub);
            Sub_operation_ready =1;

        }
		else if (enterd_choice == 5) {
		    int g = 2;

            mul = Multiplication(dLL[0], dLL[1]);

            while (g < numberOfEquations) {
                mul = Multiplication(mul, dLL[g]);
                g++;
            }
            printf("\n\nMultiplication Result\n");
            Display(mul);
            mul_operation_ready = 1;


		}
		else if (enterd_choice == 6)
        {
            printf("Enter the value of x: ");
            scanf("%d", &x);
            printf("\nSummation Result when x = %d",x);
            X_value(add, x);
            Sum_operation_ready = 1;
        }

        else if (enterd_choice == 7)
        {
            printf("Enter the value of x: ");
            scanf("%d", &x);
            printf("\nsubtraction Result when x = %d",x);
            X_value(sub, x);
            Sub_operation_ready = 1;

        }
        else if (enterd_choice == 8)
        {
            printf("Enter the value of x: ");
            scanf("%d", &x);
            printf("\nmultiplication Result when x = %d",x);
            X_value(mul, x);
            mul_operation_ready = 1;
        }

        else if (enterd_choice == 9)
        {
            printf("Enter value of x: ");
            scanf("%d", &x);
            printf("\nSum Result when x = %d",x);
            X_value(add, x);
            Sum_operation_ready = 1;
            printf("\nsub Result when x = %d",x);
            X_value(sub, x);
            Sub_operation_ready = 1;
            printf("\nmultiplication Result when x = %d",x);
            X_value(mul, x);
            mul_operation_ready = 1;

        }

        else if (enterd_choice == 10)
        {
            if (Sum_operation_ready == 1)
            {
                resultOFequations(add, 3);
            }
            if (Sub_operation_ready == 1)
            {
                resultOFequations(sub, 4);
            }
            if (mul_operation_ready == 1)
            {
                resultOFequations(mul, 5);
            }
            return 0;
		}
     menu();
    scanf("%d", &enterd_choice);
	}

	return 0;

}
