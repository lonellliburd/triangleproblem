# include <stdio.h>

# include <stdlib.h>



# define MAX 100



//The Binary Counter function takes an Array and size n as its 

//parameters. It traverses the Array from right to left and

//increments the value by 1. 



void binCounter(int A[], int n){

    int i;

    for (i=n-1; i>=0; i--){

        if (A[i]==0){

            A[i]=1;

            break;

        }

        else if (A[i]==1) A[i]=0;

    }

}



void printPath (int A[], int n, int pos){

    void binCounter(int[], int);

    void printArray(int[], int);

    

    int i;

    for (i=0; i<pos; i++)

        binCounter(A, n);

    printArray(A, n);

}

    

void printArray(int A[], int n){

    int i;

    for (i=0; i<n; i++){

        if (A[i]==0) printf("L");

        else printf("R");

        

    }

}

//Function calculates the largest sum of a path by using a Binary Counter.

//After, determine the n-bit counter, it increments through this 

//using a brute force method of testing all values to determine the largest

//values.

int bruteForceBinCounter(int A[][MAX], int binArray[], int numRows){    



    void binCounter(int[], int);

    int poss = numRows*numRows, n=0, p;

    int largest = -9999, row, col, j;

    

    while (n<poss){

        int Sum=A[0][0];

        row=0;

        col=0;

        for (j=0; j<numRows; j++){

            if (binArray[j]==0){

                Sum+= A[row+1][col];

                row++;

            }

            else

            if (binArray[j]==1){

                Sum+= A[row+1][col+1];

                row++; col++;

            }

        }

        

        binCounter(binArray, numRows);

        if (Sum>=largest){

            largest=Sum;

            p=n;

        }

        n++;

    }

    return largest;   

}



int bestSumSimpleRecursion(int A[][MAX], int i, int j, int n){

    int left, right;

    if (i==n) return A[i][j];

    left = bestSumSimpleRecursion(A, i+1, j, n);

    right = bestSumSimpleRecursion(A, i+1, j+1, n);

    if (left>right) return left + A[i][j];

    else return right + A[i][j];

}



int bestSumMemoization(int A[][MAX], int B[][MAX], int i, int j, int n){

    int left, right;

    if (i==n) return B[i][j];

    left = bestSumMemoization(A, B, i+1, j, n);

    right = bestSumMemoization(A, B, i+1, j+1, n);

    if (left>right) return B[i][j] = left + A[i][j];

    else return B[i][j] = right + A[i][j];

    

}



int bottomUpDynamic(int A[][MAX], int n){

    int i, j, sum=0;

    for (i=n-1; i>=0; i--){

        for (j=0; j<=i; j++){

            if (A[i+1][j] > A[i+1][j+1]) A[i][j]+=A[i+1][j];

            else A[i][j]+=A[i+1][j+1];

        }

    }

    return A[0][0];

}

    

    

    

int main (){

    int Arr[MAX][MAX], Arr2[MAX][MAX], binArray[MAX], numRows, row, col, i, j, val;

    

    int bruteForceBinCounter(int[][], int[], int);

    int bestSumSimpleRecursion(int[][], int, int, int);

    int bestSumMemoiztion(int[][], int[][], int, int, int);

    int bottomUpDynamic(int[][], int);

    void binCounter(int[], int);

    void printArray(int[], int);

    void printPath (int[], int, int);

    

    FILE * in = fopen("input.txt", "r");

    FILE * out = fopen("output.txt", "w");

   

    

    fscanf(in, "%d", &numRows);

       

    if (numRows==0){

        printf ("No rows read, exiting... \n");

        exit(0);

    }

    

    if (numRows==1){

        fscanf(in, "%d", &val);

        printf ("One row read, the largest sum is %d\n", val);

    }

    

    

    for (i=0; i<numRows; i++){

        binArray[i]=0;

        for (j=0; j<=i; j++){

            fscanf(in, "%d", &val);

            Arr[i][j]=val;

            Arr2[i][j]=val;

        }

    }

    

    

    int bfSum = bruteForceBinCounter(Arr, binArray, numRows);//working but I know there is an error

    int simpleSum = bestSumSimpleRecursion(Arr, 0,0,numRows);

    int memoSum = bestSumMemoization(Arr, Arr2, 0, 0, numRows);

    int dynamicSum = bottomUpDynamic(Arr, numRows); //working

    

     

    printf("Brute Force Binary Counter: Sum = %d\n", bfSum);

    printf("Simple Recursion: Sum = %d\n", simpleSum);

    printf("Best Sum Memoization Recursion: Sum = %d\n", memoSum);

    printf("Dynamic Program, Button Up Approach: Sum = %d\n", dynamicSum);

    

    fprintf(out, "Brute Force Binary Counter: Sum = %d\n", bfSum);

    fprintf(out, "Simple Recursion: Sum = %d\n", simpleSum);

    fprintf(out, "Best Sum Memoization Recursion: Sum = %d\n", memoSum);

    fprintf(out, "Dynamic Program, Button Up Approach: Sum = %d\n", dynamicSum);

    

    return 0;

}
