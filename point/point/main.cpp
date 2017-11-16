#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	cout << "Введите размерность первой прямоугольной  матрицы:" <<endl;
	int l, m, n, k;
	cin >> l;
	cin >> m;
	cout << "Введите размерность второй прямоугольной матрицы:" << endl;
	cin >> n;
	cin >> k;
	cout << endl;


	int **pMatrix1 = new int*[l];//выделение памяти 1 матрицы
	for (int i = 0; i < l; i++)
	{
		*(pMatrix1+i) = new int[m];
	}

	int **pMatrix2 = new int*[n];//выделение памяти 2 матрицы 
	for (int i = 0; i < n; i++)
	{
		*(pMatrix2 + i) = new int[k];
	}


	for (int i = 0; i < l; i++)//заполнение первой матрицы 
	{
		for (int j = 0; j < m; j++)
		{
			pMatrix1[i][j] = rand() % 5 + 1;
			cout << pMatrix1[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)//заполнение второй матрицы 
	{
		for (int j = 0; j < k; j++)
		{
			pMatrix2[i][j] = rand() % 5 + 1;
			cout << pMatrix2[i][j] << "  ";
		}
		cout << endl;
	}
	int **pMatrix3 = new int*[l];//выделение памяти матрицы перемножения 
	for (int i = 0; i < l; i++)
	{
		*(pMatrix3 + i) = new int[k];
	}

	if (m == n) //алгоритм перемножения прямоугольных матриц
	{
		cout << "Матрицы являются прямоугольными" << endl;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < k; j++)
			{
				pMatrix3[i][j] = 0;
				for (int s = 0; s < m; s++)
				{
					pMatrix3[i][j] += pMatrix1[i][s] * pMatrix2[s][j];
					
				}
				cout << pMatrix3[i][j] << "  ";
			}
			cout << endl;
		}		
	
	}
	else cout << "Ошибка,введите прямоугольные матрицы "<<endl;

	for (int i = 0; i < l; i++) //освобождение памяти для 1 матрицы
	{
		delete [] pMatrix1[i];

	}
	delete[] pMatrix1;

	for (int i = 0; i < n; i++) //освобождение памяти для 2 матрицы
	{
		delete[] pMatrix2[i];

	}
	delete[] pMatrix2;

	for (int i = 0; i < l; i++) //освобождение памяти для  матрицы перемножения 
	{
		delete[] pMatrix3[i];

	}
	delete[] pMatrix3;

	system("pause");
	return 0;

}