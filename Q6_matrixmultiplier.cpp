#include <iostream>
#include <cstdlib>

using namespace std;

void printMatrix(int ** Matrix, int columns, int rows);
int** randomMatrix(int columns, int rows);
int** multMatrices(int ** matrix1, int ** matrix2, int rowsMatrix1, int colsMatrix2, int colsMatrix1);
void freeMem(int ** Matrix, int columns);

int main()
{

	int rowsMatrix1;
	int colsMatrix1;
	int rowsMatrix2;
	int colsMatrix2;

	cout << "Please input rows and columns for random matrices:" << endl;

	cout << "Matrix 1 rows: ";
	cin >> rowsMatrix1;

	cout << "Matrix 1 columns: ";
	cin >> colsMatrix1;

	cout << "Matrix 2 rows: ";
	cin >> rowsMatrix2;

	cout << "Matrix 2 columns: ";
	cin >> colsMatrix2;

	if(colsMatrix1 != rowsMatrix2)
	{
		cout << "Matrix 1 columns must match Matrix 2 rows" << endl;		
		return 0;
	}
		
	int ** matrix1 = randomMatrix(colsMatrix1, rowsMatrix1);
	int ** matrix2 = randomMatrix(colsMatrix2, rowsMatrix2);

	int ** result = multMatrices(matrix1, matrix2, rowsMatrix1, colsMatrix2, colsMatrix1);


	printMatrix(matrix1, colsMatrix1, rowsMatrix1);
	cout << endl << "Post multiplied by:" << endl;
	printMatrix(matrix2, colsMatrix2, rowsMatrix2);
	cout << endl << "Equals:" << endl;
	printMatrix(result, colsMatrix2, rowsMatrix1);
	cout << endl;

	freeMem(result, rowsMatrix1);
	freeMem(matrix1, rowsMatrix1);
	freeMem(matrix2, rowsMatrix2);

	return 0;
}

void printMatrix(int ** Matrix, int columns, int rows)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
			cout << Matrix[i][j] << "  ";

		cout << endl << endl;
	}
}

int ** randomMatrix(int columns, int rows)
{
	
	int ** matrix;
	int index1, index2;

	matrix = new int *[rows];

	for(int i = 0; i < rows; i++)
		matrix[i] = new int[columns];



	for(index1 = 0; index1 < rows; index1++)
	{
		for(index2 = 0; index2 < columns; index2++)
			matrix[index1][index2] = rand() % 10;
	}

	return (int**) matrix;
}

int** multMatrices(int ** matrix1, int ** matrix2, int rowsMatrix1, int colsMatrix2, int colsMatrix1)
{
	int** result;
	result = new int *[rowsMatrix1];
	for(int i = 0; i < rowsMatrix1; i++)
		result[i] = new int [colsMatrix2];

	for(int i = 0; i < rowsMatrix1; i++)
	{
		for(int j = 0; j < colsMatrix2; j++)
		{
			result[i][j] = 0;
			
			for(int x = 0; x < colsMatrix1; x++)
				result[i][j] += matrix1[i][x]*matrix2[x][j];
			 
		}
	}
	return (int**) result;
}


void freeMem(int ** Matrix, int rows)
{
	for(int i = 0; i < rows; i++)
		delete [] Matrix[i];

	delete [] Matrix;
}

