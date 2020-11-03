/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Different Operations on Matrix (Two Dimensions Array)
#include <stdio.h>
#include <stdlib.h>

void multiplication(void);

int A[30][30], B[30][30], C[30][30];

int i, j, k, m, n, sum = 0;
//Inside the main function
int main()
{
    //We are defining the size of arrays here
    printf("Enter Number of Rows : ");
    scanf("%d", &m);
    printf("Enter Number of Columns : ");
    scanf("%d", &n);
    printf("Enter Array Element for First Matrix : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter data in [%d][%d] : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    /*We are printing the first array here using two nested for loop.*/
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    /*Taking the values for first array.
    We use nested for loop and scan the values for array.*/
    printf("Enter Array Element for Second Matrix : \n");
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter data in [%d][%d] : ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    /*We are printing the second array here using two nested for loop.*/
    for(i = 0; i<m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    multiplication();
    return 0;
}

/*We perform multiplication of two arrays and store the result in matrix C.
Then we print the resultant matrix using two nested for loop.*/
void multiplication()
{
    for(i = 0; i < m; i++)
    {
        for(j=0; j < m; j++)
        {
            for(k = 0; k < m; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            sum  = 0;
        }
    }
    printf("The Multiplication of Two Arrays : \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}
