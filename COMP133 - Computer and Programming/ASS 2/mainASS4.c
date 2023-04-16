#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 8
#define tax  0.15

typedef struct
{
int enumb;
char name[10];
float hours;
float rate;
float total_salary;
float tax_amount;
}employee_record;

void calculate( employee_record AR[]);
void sort ( employee_record AR []);


int main()
{
printf("                                            <<<<WELCOME TO MY PROGRAM>>>>                               \n\n");
printf("     **If you want to see the details of the report for the employees, Please go to file it's called (report)**\n");
FILE *input ,*result;
input=fopen("employees.txt","r");
result=fopen("report.txt","w");
employee_record AR[length],total_salary,tax_amount;
for (int i= 0; i < 8; i++)
{
fscanf(input, "%d", &AR[i].enumb);
}

fscanf(input, "\n");
char range[100];
fgets(range,100,input);
char *take=strtok(range," ,;\n");
for(int i=0;i<8;i++)
{
strcpy(AR[i].name, take);
take = strtok(NULL, " ,;\n");
}
 for (int i= 0; i< 8; i++)
{
 fscanf(input, "%f", &AR[i].hours);
}

 for (int i= 0; i< 8; i++)
{
    fscanf(input, "%f", &AR[i].rate);
}
calculate(AR);
 sort ( AR);

fprintf(result,"<<The informations for the eight employees are shown down in the diagram>>\n\n");
fprintf(result,"****The informations for  the employees after ascending order is:\n\n");
fprintf(result,"Employee Name     The total Salary       The tax Amount       The net Salary\n");
fprintf(result,"-------------     ----------------       --------------       --------------\n");

for (int i= 0; i< 8; i++)
fprintf(result,"    %-10s       %f            %f           %f\n", AR[i].name, AR[i].total_salary, AR[i].tax_amount, AR[i].total_salary-((AR[i].total_salary)*tax));


fclose(input);
fclose(result);
    return 0;
}
void calculate( employee_record AR[])
{
int i ;
for ( i=0;i<8;i++)
{
if (AR[i].hours<=40)
 {
    AR[i].total_salary=AR[i].hours * AR[i].rate;
 }
else
 {
   AR[i].total_salary = 40*AR[i].rate + (AR[i].hours-40)*AR[i].rate*1.5;
 }

AR[i].tax_amount = tax * AR[i].total_salary;
}
}
void sort ( employee_record AR [])
{
char change[10] ;
int i , j ;
float change1 ;
for(i = 0 ; i<length ; i++)
{
for( j = i+1 ; j<length; j++)
{
if(strcmp(AR[i].name,AR[j].name) > 0)
{
strcpy(change,AR[i].name);
strcpy(AR[i].name,AR[j].name);
strcpy(AR[j].name,change);

change1 = AR[i].total_salary;
AR[i].total_salary = AR[j].total_salary;
AR[j].total_salary = change1 ;

change1 = AR[i].tax_amount;
AR[i].tax_amount = AR[j].tax_amount;
AR[j].tax_amount = change1;
}
}
}
}
