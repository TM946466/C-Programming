#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 40

//Timothy McGowan
//3/2/1010
//CSC345-81
//0946466
//PROCESSING 1D ARRAYS

void fillArray(int Low, int High, int *A,int Len);  //Populates array with random variables in entered range
void printArray(int *A, int Len);                   //Displays contents of Array
int findWithRange(int *A, int Lower, int Upper);    //Finds Max value withing entered range
void reverseArray(int *A,int Len);                  //Reverses array order
void reverseArrayWithRange(int *A,int Lower, int Upper);    //Reverses Array order in Range





int main(int argc, char *argv[]) {
    int array[SIZE];  //Initialize array to set global size
    int Low = 0;      //Initialize variable for lower bound
    int High = 0;     //Initialize variable for upper bound
    int Len = (sizeof(array)/sizeof(int));//Calculate size and assign to variable (Divides the memory size of the array by the size of the arrays type to get number of elements)


    printf("Please enter Low and High value to random1y populate the array:\n"); // ask for user input to populate array
    scanf("%d", &Low);
    scanf("%d", &High);
    fillArray(Low,High,array,Len); //populate array based on user entry values
    printf("\nCurrent Array:\n");
    printArray(array,Len);          //Display Array

    printf("\nPlease enter index values to find the Max Value in range (Low High):\n"); //Ask user for index range values
    scanf("%d", &Low);
    scanf("%d", &High);
    printf("Max value between index %d and %d : %d ",Low,High,findWithRange(array,Low,High)); // Display max value in user entered index range
    printf("\n\nReversed Array :\n");
    reverseArray(array,Len);                                                                //Reverses the Array
    printArray(array,Len);

    printf("\nPlease enter index values to reverse in range (Low High):\n"); // ask for user index range values to reverse in range
    scanf("%d", &Low);
    scanf("%d", &High);
    printf("\n\nReversed Array (%d-%d):\n",Low,High);
    reverseArrayWithRange(array,Low,High);                                   //Reverse array in range
    printArray(array,Len);                                                   //Display Array

    return(0);

}

void fillArray(int Low, int High, int *A,int Len){

    srand(time(0)); // Generates seed for random based on time

    for(size_t i=0; i < Len; i++){

        A[i] = ((rand() % (High - Low + 1)) + Low); //Fill with random integers between and including Range
    }

}


void printArray(int *A, int Len){

    for(size_t i=0; i < Len; i++){

        if((i % 10) == 0){                          //Skips a line every 10 entries
            printf("\n");
        }
        printf("%d ",A[i]);
    }
    printf("\n");

}

int findWithRange(int *A, int Lower, int Upper){
    int Max = 0;                                    //Variable for max value in range to return
    for(size_t i = Lower; i < Upper; i++){

        if(Max < A[i]){                             //Check for max value in loop
            Max = A[i];
        }
    }
    return(Max);                                    //Return Max Value
}

void reverseArray(int *A,int Len){

    int temp;
    int high = Len - 1;                             //Set manipulatable variable based on Arrays Length
    for(size_t i = 0; i < high; i++){

        temp = A[i];                                //Set Temp var to A[i]
        A[i] = A[high];                             //A[i] to A[high]
        A[high] = temp;                             //Set A[high] to temp value
        high--;                                     //Decrement high
    }
}

void reverseArrayWithRange(int *A,int Lower, int Upper){ //Same as reverseArray but with a focused range instead of the entire array
    int temp;
    for(Lower; Lower < Upper; Lower++){

        temp = A[Lower];
        A[Lower] = A[Upper];
        A[Upper] = temp;
        Upper--;
    }
}

