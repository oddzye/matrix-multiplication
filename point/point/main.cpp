#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	cout << "������� ����������� ������ �������������  �������:" <<endl;
	int l, m, n, k;
	cin >> l;
	cin >> m;
	cout << "������� ����������� ������ ������������� �������:" << endl;
	cin >> n;
	cin >> k;
	cout << endl;


	int **pMatrix1 = new int*[l];//��������� ������ 1 �������
	for (int i = 0; i < l; i++)
	{
		*(pMatrix1+i) = new int[m];
	}

	int **pMatrix2 = new int*[n];//��������� ������ 2 ������� 
	for (int i = 0; i < n; i++)
	{
		*(pMatrix2 + i) = new int[k];
	}


	for (int i = 0; i < l; i++)//���������� ������ ������� 
	{
		for (int j = 0; j < m; j++)
		{
			pMatrix1[i][j] = rand() % 5 + 1;
			cout << pMatrix1[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)//���������� ������ ������� 
	{
		for (int j = 0; j < k; j++)
		{
			pMatrix2[i][j] = rand() % 5 + 1;
			cout << pMatrix2[i][j] << "  ";
		}
		cout << endl;
	}
	int **pMatrix3 = new int*[l];//��������� ������ ������� ������������ 
	for (int i = 0; i < l; i++)
	{
		*(pMatrix3 + i) = new int[k];
	}

	if (m == n) //�������� ������������ ������������� ������
	{
		cout << "������� �������� ��������������" << endl;
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
	else cout << "������,������� ������������� ������� "<<endl;

	for (int i = 0; i < l; i++) //������������ ������ ��� 1 �������
	{
		delete [] pMatrix1[i];

	}
	delete[] pMatrix1;

	for (int i = 0; i < n; i++) //������������ ������ ��� 2 �������
	{
		delete[] pMatrix2[i];

	}
	delete[] pMatrix2;

	for (int i = 0; i < l; i++) //������������ ������ ���  ������� ������������ 
	{
		delete[] pMatrix3[i];

	}
	delete[] pMatrix3;

	system("pause");
	return 0;

}