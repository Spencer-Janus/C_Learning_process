#include <iostream>
using namespace std;
//ȫ�ֱ�������
int Available[100]; //��������Դ����
int Max[50][100];   //����������
int Allocation[50][100];  //�������
int Need[50][100];        //�������
int Request[50][100];     //M�����̻���ҪN����Դ����Դ��
int Finish[50];
int p[50];
int m, n;   //M������,N����Դ
//��ȫ���㷨
int Safe()
{
	int i, j, l = 0;
	int Work[100]; //��������Դ����
	for (i = 0; i < n; i++)
		Work[i] = Available[i];
	for (i = 0; i < m; i++)
		Finish[i] = 0;
	for (i = 0; i < m; i++)
	{
		if (Finish[i] == 1)
			continue;
		else
		{
			for (j = 0; j < n; j++)
			{
				if (Need[i][j] > Work[j])
					break;
			}
			if (j == n)
			{
				Finish[i] = 1;
				for (int k = 0; k < n; k++)
					Work[k] += Allocation[i][k];
				p[l++] = i;
				i = -1;
			}
			else continue;
		}
		if (l == m)
		{
			cout << "ϵͳ�ǰ�ȫ��" << '\n';
			cout << "ϵͳ��ȫ������:\n";
			for (i = 0; i < l; i++)
			{
				cout << p[i];
				if (i != l - 1)
					cout << "-->";
			}
			cout << '\n';
			return 1;
		}
	}
}
//���м��㷨
int main()
{
	int i, j, mi;
	cout << "������̵���Ŀ:\n";
	cin >> m;
	cout << "������Դ������:\n";
	cin >> n;
	cout << "����ÿ�������������ĸ�����Դ��,����" << m << "x" << n << "��������\n";
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> Max[i][j];
	cout << "����ÿ�������Ѿ�����ĸ�����Դ��,����" << m << "x" << n << "��������\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ��������������:\n";
				j--;
				continue;
			}
		}
	}
	cout << "�����������Դ���е���Ŀ:\n";
	for (i = 0; i < n; i++)
		cin >> Available[i];
	Safe();
	while (1)
	{
		cout << "����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�\n";
		cin >> mi;
		cout << "�������������ĸ�����Դ������\n";
		for (i = 0; i < n; i++)
			cin >> Request[mi][i];
		for (i = 0; i < n; i++)
		{

			if (Request[mi][i] > Need[mi][i])
			{
				cout << "��������Դ���������̵���������\n";
				return 0;
			}
			if (Request[mi][i] > Available[i])
			{
				cout << "��������Դ������ϵͳ���е���Դ����\n";
				return 0;
			}
		}
		for (i = 0; i < n; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}
		if (Safe())
			cout << "ͬ���������\n";
		else
		{
			cout << "SORRY�r(�s���t)�q����������󱻾ܾ���\n";
			for (i = 0; i < n; i++)
			{
				Available[i] += Request[mi][i];
				Allocation[mi][i] -= Request[mi][i];
				Need[mi][i] += Request[mi][i];
			}
		}
		for (i = 0; i < m; i++)
			Finish[i] = 0;
		char Flag;       //��־λ
		cout << "�Ƿ��ٴ�������䣿���밴Y/y�����밴N/n";
		while (1)
		{
			cin >> Flag;
			if (Flag == 'Y' || Flag == 'y' || Flag == 'N' || Flag == 'n')
				break;
			else
			{
				cout << "�밴Ҫ����������:\n";
				continue;
			}
		}
		if (Flag == 'Y' || Flag == 'y')
			continue;
		else break;
	}
}
