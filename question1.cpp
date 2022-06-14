//Name: Ahmet Sabri MERT
//Course: Programming for Engineering. 64170031, Fall, 2020
//Purpose:The purpose of this program is to create a matrix and order the
//numbers in these matrices under the desired conditions and by
//creating the desired functions. Fýles should be used.
//Written in C language.

#include<stdio.h>
#include<string.h>

void sortMatrix(int A[95][95], int n,int m)
{
// temporary matrix
int l[100*100 ];
int k = 0;
   int i,j;
   int size;
// copying the elements of matrix one by one into temp[]
for ( i = 0; i < n; i++)
for (j = 0; j < m; j++)
l[k++] = A[i][j];
size=k;
   //bubble sort
   for(i=0;i<size;++i)
   {
       for(j=0;j<size-i-1;++j)
       {
           if(l[j]>l[j+1])
           {
           int temp = l[j];
           l[j]=l[j+1];
           l[j+1]=temp;
           }
       }  
   }
  
//copying values back to matrix untill n/2
k = 0;
for (i = 0; i <n/2; i++)
for (j = 0; j < m; j++)
A[i][j] = l[k++];

   //bubble sort
   for(i=0;i<size;++i)
   {
       for(j=0;j<size-i-1;++j)
       {
           if(l[j]<l[j+1])
           {
           int temp = l[j];
           l[j]=l[j+1];
           l[j+1]=temp;
           }
       }  
   }
  
//copying back into the array A, but in descending order and starting from n/2 row
//copying values back to matrix untill n/2
k = 0;
for (i = n/2; i <n; i++)
for (j = 0; j < m; j++)
A[i][j] = l[k++];
}

void print(int A[95][95], int n,int m)
{
   int i,j;
   for(i=0;i<n;++i)
   {
       for(j=0;j<m;++j)
       {
           printf("%d   ",A[i][j]);
          
       }
       printf("\n");
   }
}

void write(int A[95][95],int n,int m)
{
   FILE * fin = fopen("matrix.txt","w");
   int i,j;
   for(i=0;i<n;++i)
   {
       for(j=0;j<m;++j)
       {
           fprintf(fin,"%d ",A[i][j]);
       }
       fprintf(fin,"\n");
   }
   fclose(fin);
}

void read(int A[95][95],int n,int m)
{
   FILE * fin = fopen("matrix.txt","r");
   int i,j;
   for(i=0;i<n;++i)
   {
       for(j=0;j<m;++j)
       {
           fscanf(fin,"%d",&A[i][j]);
       }
   }
   fclose(fin);
}

int main()
{
   int A[95][95];
   int n,m; // n= rows, m=columns
   printf("Enter value of n: ");
   scanf("%d",&n);
   printf("Enter value of m: ");
   scanf("%d",&m);
   //taking values from the user
   int i,j;
   for(i=0;i<n;++i)
   {
       for(j=0;j<m;++j)
       {
           printf("Enter value %d %d: ",i,j);
           scanf("%d",&A[i][j]);
       }
   }
   //writing the data into file
   write(A,n,m);
   //reading the data from file into A
   read(A,n,m);
   sortMatrix(A,n,m);
   print(A,n,m);
  
  
   return 0;
}
