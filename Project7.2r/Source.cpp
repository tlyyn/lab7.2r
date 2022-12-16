#include <iostream>
#include <iomanip>
using namespace std;

void CreateRow(int** arr, const int rowNo, const int N, int colNo, const int Low, const int High);
void CreateRows(int** arr, const int N1, int rowNo, const int N2, const int Low = -10, const int High = 10);
void PrintRow(int** arr, const int rowNo, const int N, int colNo);
void PrintRows(int** arr, const int N1, int rowNo, const int N2);

void FindMinElemCol(int** arr, const int rowNo, const int N, int colNo, int& min_index);
void FindMinElemCols(int** arr, const int rowNo, const int rowCount, int colNo, int colCount, int& max);
void FindFirstMinElemCol(int** arr, const int rowNo, const int rowCount, int colNo, int colCount, int& max_index);


int main()
{
	srand((unsigned)time(NULL));

	int n, k;
	cout << "k(width) = "; cin >> k;
	cout << "n(height) = "; cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[k];
	CreateRows(arr, k, n, 0);
	PrintRows(arr, k, n, 0);

	int max;
	FindFirstMinElemCol(arr, 0, n, 0, k, max);
	FindMinElemCols(arr, 0, n, 0, k, max);

	cout << "max = " << max << endl;


	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

void CreateRow(int** arr, const int rowNo, const int N, int colNo, const int Low, const int High)
{
	arr[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(arr, rowNo, N, colNo + 1, Low, High);
}

void CreateRows(int** arr, const int colCount, const int rowCount, int rowNo, const int Low, const int High)
{
	CreateRow(arr, rowNo, colCount, 0, Low, High);
	if (rowNo < rowCount - 1)
		CreateRows(arr, colCount, rowCount, rowNo + 1, Low, High);
}

void PrintRow(int** arr, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << arr[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(arr, rowNo, N, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** arr, const int colCount, const int rowCount, int rowNo)
{
	PrintRow(arr, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(arr, colCount, rowCount, rowNo + 1);
	else
		cout << endl;
}


void FindFirstMinElemCol(int** arr, const int rowNo, const int rowCount, int colNo, int colCount, int& max)
{
	if (colNo % 2 == 0)
	{
		int min_index = 0;
		FindMinElemCol(arr, rowNo, rowCount, colNo, min_index);
		max = arr[min_index][colNo];
		return;
	}
	if (colNo < colCount - 1)
		FindFirstMinElemCol(arr, rowNo, rowCount, colNo + 1, colCount, max);
}

void FindMinElemCol(int** arr, const int rowNo, const int N, int colNo, int& min_index)
{
	if (arr[rowNo][colNo] < arr[min_index][colNo])
		min_index = rowNo;
	if (rowNo < N - 1)
		FindMinElemCol(arr, rowNo + 1, N, colNo, min_index);
}

void FindMinElemCols(int** arr, const int rowNo, const int rowCount, int colNo, int colCount, int& max)
{
	if (colNo % 2 == 0)
	{
		int min_index = 0;
		FindMinElemCol(arr, rowNo, rowCount, colNo, min_index);

		if (arr[min_index][colNo] > max)
		{
			max = arr[min_index][colNo];
		}
	}
	if (colNo < colCount - 1)
		FindMinElemCols(arr, rowNo, rowCount, colNo + 1, colCount, max);
}