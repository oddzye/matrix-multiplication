#include <iostream>
using namespace std;

int main()
{
	
	cout << "Enter the dimension of the first rectangular matrix :"<<endl;
	int l, m, n, k;
	cin >> l;
	cin >> m;
	cout << "Enter the dimension of the second rectangular matrix :" << endl;
	cin >> n;
	cin >> k;
	cout << endl;


	int **pMatrix1 = new int*[l];//allocation memory for fitst matrix
	for (int i = 0; i < l; i++)
	{
		*(pMatrix1+i) = new int[m];
	}

	int **pMatrix2 = new int*[n];//allocation memory for second matrix
	for (int i = 0; i < n; i++)
	{
		*(pMatrix2 + i) = new int[k];
	}


	for (int i = 0; i < l; i++)//first matrix filling
	{
		for (int j = 0; j < m; j++)
		{
			pMatrix1[i][j] = rand() % 5 + 1;
			cout << pMatrix1[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)//second matrix filling
	{
		for (int j = 0; j < k; j++)
		{
			pMatrix2[i][j] = rand() % 5 + 1;
			cout << pMatrix2[i][j] << "  ";
		}
		cout << endl;
	}
	int **pMatrix3 = new int*[l];//allocation memory for multiplication matrix 
	for (int i = 0; i < l; i++)
	{
		*(pMatrix3 + i) = new int[k];
	}

	if (m == n) //multiplication algorithm
	{
		cout << "Matrices are rectangular" << endl;
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
	else cout << "Error,input rectangular matrices "<<endl;

	for (int i = 0; i < l; i++) //freeing memory for 1 matrix
	{
		delete [] pMatrix1[i];

	}
	delete[] pMatrix1;

	for (int i = 0; i < n; i++) //freeing memory for 2 matrix
	{
		delete[] pMatrix2[i];

	}
	delete[] pMatrix2;

	for (int i = 0; i < l; i++) //freeing memory for multiplication matrix
	{
		delete[] pMatrix3[i];

	}
	delete[] pMatrix3;

	system("pause");
	return 0;

}