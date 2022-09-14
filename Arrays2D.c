#include <stdio.h>

/*Timothy McGowan
4/11/20
CSC 345-81
Lab 3
2DArrays & Arrays of Pointers to Functions
*/

void displayOutputs(int y, int x, int arr[y][x]);
int max(int y, int x, int arr[y][x]);
int rowsum(int y, int x, int arr[y][x], int row);
int columnsum(int y, int x, int arr[y][x], int column);
void isSquare(int y, int x);

int main(void)
{

	int rowy, colx, entry,row,col;
	
	size_t i,j;

	printf("Let's create a 2Dim array!\n\n");
	printf("How many rows? ");
	scanf("%d", &rowy);
	printf("How many columns? ");
	scanf("%d", &colx);
	int arr2d[rowy][colx];
	printf("\n");
	
	//Iterate through array for data entry
	for(i = 0; i < rowy; ++i)
	{
		for(j=0; j < colx; ++j)
		{
			printf("enter [%zu][%zu] : ",i,j);
			scanf("%d", &entry);
			arr2d[i][j] = entry;
		}

	}
	
	//Iterate through all rows of 2D array applying rowsum() function to each
	for(i = 0; i < rowy; ++i)
	{
		printf("\nSum of row %zu = %d ",(i+1),rowsum(rowy, colx, arr2d, i));
	}
	printf("\n");
	
	//Iterate through all columns of 2D array applying columnsum() function to each 
	for(i = 0; i < colx; ++i)
	{
		printf("\nSum of column %zu = %d ",(i+1),columnsum(rowy, colx, arr2d, i));
	}
	printf("\n\n");
	isSquare(rowy,colx);
	printf("\nHere is your 2Dim array\n");
	displayOutputs(rowy, colx, arr2d);
	
}

//Iterates through and formats a display for 2D arrays
void displayOutputs(int y, int x, int arr[y][x])
{
	size_t i,j;
	//Rows Loop
	for(i = 0; i < y; ++i)
	{
		printf("[");
		//Column Loop
		for(j=0; j < x; ++j)
		{
			if( j == (x-1))
			{
				printf("%3d",arr[i][j]);
			}
			else printf("%3d, ",arr[i][j]);
		}
		printf(" ]");
		puts("");
		
	}
}

//Iterate through and return max value of 2D array
int max(int y, int x, int arr[y][x])
{
	size_t i,j;
	int max = arr[0][0];
	//Rows Loop
	for(i = 0; i < y; ++i)
	{
		for(j = 0; j < x; ++j)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
			else;
		}
	}	
	return(max);
}

//Return sum of specified row
int rowsum(int y, int x, int arr[y][x], int row)
{
	size_t i,j;
	int sum = 0;
	//Rows Loop
	for( i = 0; i < x; ++i){
			sum = sum + arr[row][i];
	}
	
	return(sum);
}

//Return sum of specified column
int columnsum(int y, int x, int arr[y][x], int column)
{
	size_t i,j;
	int sum = 0;
	//Rows Loop
	for( i = 0; i < y; ++i){
			sum = sum + arr[i][column];
	}
	
	return(sum);
}

//Verify if 2D array is square or not
void isSquare(int y, int x)
{
	if(y == x)
	{
		printf("This is a Square Function\n");
	}
	else printf("This is not a Square Function\n");
}