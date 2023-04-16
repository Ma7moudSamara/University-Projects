#include <stdio.h>
#include <stdlib.h>
void Fill_Matrix (FILE *input,int years[10],int quantity[10][4]);
void Print_Matrix (int years[10],int quantity[10][4]);
void Compute_Sum (int years[10],int quantity[10][4],float years_sum[10]);
void Sort (int years[10],int quantity[10][4],float years_sum[10]);
void Print_Average (int years[10],int quantity[10][4],float years_sum[10]);


int main()
{
    printf("                                         <<<<Welcome to my program>>>>              \n\n");
    printf("  (This program contains the rain accumulation for the months of Jan - Apr for the last 10 years (2011 - 2020) in ml)\n");
int years[10];
int quantity[10][4];
float years_sum[10];
FILE *input;
 input= fopen("rains.txt","r");

 Fill_Matrix (input,years,quantity);
 Print_Matrix (years,quantity);
 Compute_Sum (years,quantity,years_sum);
 Sort (years, quantity,years_sum);
 Print_Average (years,quantity,years_sum);

return 0;
}
void Fill_Matrix (FILE *input,int years[10],int quantity[10][4])
{

    int i;
    for(i=0;i<10;i++)
    {
        fscanf(input,"%d%d%d%d%d",&years[i],&quantity[i][0],&quantity[i][1],&quantity[i][2],&quantity[i][3]);
    }

}
   void Print_Matrix (int years[10],int quantity[10][4])
{
   int M,S;
   printf("\n<<The years>>       <<The 4 readings for the rain fall in the months from January to April>>\n(2011 - 2020)        1st reading        2nd reading         3rd reading        4th reading\n");
   printf(" --------------      ------------------------------------------------------------------------\n");

    for(M=0;M<10;M++)
    {
        printf("     %d    ",years[M]);
        for(S=0;S<4;S++)
        {
        printf("            %d    ",quantity[M][S]);
        }
        printf("\n");
    }
}
Compute_Sum (int years[10],int quantity[10][4],float years_sum[10])
{
int M;

for (M=0;M<10;M++)// Because I know the number of coloumns and rows in array quantity I can do the sum like what shown down.
{
    years_sum[M] = quantity[M][0] + quantity[M][1] +quantity[M][2] + quantity[M][3] ;
}

}
void Sort (int years[10],int quantity[10][4],float years_sum[10])
{
    int x,y,z,change2,change3;
    float change1;
    for (x=0;x<10;x++)
    {
        for (y=x+1;y<10;y++)
        {
            if (years_sum[x]<years_sum[y])
            {
               change1 = years_sum[x];
               years_sum[x]=years_sum[y];
               years_sum[y]=change1;

               change2= years[x];
               years[x] = years[y];
               years[y] = change2;

               for (z=0;z<4;z++) // Here I added a new loop because quantity array is a 2D array so we need a loop for rows and one for coloumns.
               {
                   change3=quantity[x][z];
                   quantity[x][z]=quantity[y][z];
                   quantity[y][z]=change3;
               }

            }
        }
    }
}
void Print_Average (int years[10],int quantity[10][4],float years_sum[10])
{
    printf("\n***************************         ******************************          **************************\n ##The diagram below show the descending order of the years depends on the sum of the rain in each year:##\n\n");
    printf("<<The Years>>                <<The 4 months readings>>                        <<The Sum of 4 months>>\n");
     printf("------------                ---------------------------                      --------------------------\n");
     int L;
     for(L=0;L<10;L++)
    {
        printf("    %d                      %d    %d    %d    %d                               %.2f\n",years[L],quantity[L][0],quantity[L][1],quantity[L][2],quantity[L][3],years_sum[L]);
    }
}

