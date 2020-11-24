#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Simit(int** a, const int rowCount, const int colCount, const int i, const int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -42;
	int High = 51;
	int rowCount;
	int colCount;
	int f;
	cout << "n = "; cin >> rowCount;
	cout << "m = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	f = Simit(a, rowCount, colCount, 0, 0);
	if (f == 1)
		cout << "simitrichi";
	else cout << "ne simitrichni";
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Simit(int** a, const int rowCount, const int colCount, const int i, const int j)
{
	int f = 1;
	if (a[i][j] == a[rowCount - i - 1][colCount - j - 1])
	{

		f = f * 1;
	}
	else
	{
		f = f * 0;
	}
	if (j < colCount - 1)
		Simit(a, rowCount, colCount, i, j + 1);
	else if (i < rowCount - 1)
		Simit(a, rowCount, colCount, i + 1, 0);

	return f;
}

