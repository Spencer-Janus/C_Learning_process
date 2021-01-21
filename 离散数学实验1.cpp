#include "pch.h"
#include <iostream>
#include <string>
#include <stack>    
#include <map>      
#include <sstream>  
#include <cmath>
using namespace std;
string before;  /*中缀表达式*/
string after;   /*后缀表达式*/
string letter;   /*存放所有字母*/
int truenum[1000];//存放主析取范式真值
int falsenum[1000];//存放主合取范式真值
map<char, int>M;
int tnumber=0, fnumber = 0;//前者为主析取范式项数
void Delete()   /*删除中缀表达式中的多余符号*/
{
	before.append("#"); /*此处#用于stream函数将中缀转后缀扫描字符的判断依据*/
	string::iterator i = before.begin();
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (i = before.begin(); i != before.end(); ++i)
		{
			if (*i == '>')
			{
				before.erase(i);
				flag = 1;
				break;
			}
			if (*i == '=')
			{
				before.erase(i);
				flag = 1;
				break;
			}
		}
	}
}
int icp(char a)/*栈外优先级*/
{
	if (a == '(') return 12;
	if (a == '!') return 11;
	if (a == '&') return 8;
	if (a == '|') return 6;
	if (a == '-') return 4;
	if (a == '<') return 2;
	if (a == ')') return 1;
	if (a == '#') return 0;
}
int isp(char a)/*栈内优先级*/
{
	if (a == '(') return 1;
	if (a == '!') return 10;
	if (a == '&') return 9;
	if (a == '|') return 7;
	if (a == '-') return 5;
	if (a == '<') return 3;
	if (a == ')') return 12;
	if (a == '#') return 0;
}
int exchange()    //将字母存储在letter中，并将中缀转后缀
{
	int j = 0,letternum=0;
	stack<char> s;
	char ch, y;
	s.push('#');
	stringstream ss(before);
	while (ss >> ch, ch != '#')
	{
		if (isalpha(ch))      /*判断字符ch是否为字母*/
		{
			after.push_back(ch);
			if (letter.find(ch) == -1)/*若找不到则存入letter*/
			{       
				letternum++;
				letter.push_back(ch);
			}
		}
		else if (ch == ')') /*在遇到（之前持续出栈*/
		{
			for (y = s.top(), s.pop(); y != '('; y = s.top(), s.pop())
			{
				after.push_back(y);
			}
		}
		else
		{
			for (y = s.top(), s.pop(); icp(ch) <= isp(y); y = s.top(), s.pop())/*比较栈内外的优先级判断出栈与否*/
			{
				after.push_back(y);
			}
			s.push(y);
			s.push(ch);
		}
	}
	while (!s.empty())/*当没有元素情况下返回ture*/
	{
		y = s.top();
		s.pop();
		if (y != '#')
		{
			after.push_back(y);
		}
	}
	after.append("#");
	return letternum;
}
int calculate()   /*利用堆栈计算后缀表达式*/
{
	stack<int> s;
	char ch;
	int j = 0,i=0;
	int t1, t2;
	while (1)
	{
		ch = after[j];
		if (ch == '#'|| ch == '0') break;
		j++;
		if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))
		{
			
			s.push(M[ch]);
			i++;
		}
		else
		{
			if (ch == '!')
			{
				t1 = s.top();
				s.pop();
				s.push(!t1);
			}
			else if (ch == '&')
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				if (t1 == 1 && t2 == 1)
				{
					s.push(1);
				}
				else
				{
					s.push(0);
				}
			}
			else if (ch == '|')
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				if (t1 == 0 && t2 == 0)
				{
					s.push(0);
				}
				else
				{
					s.push(1);
				}
			}
			else if (ch == '-')
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				if (t1 == 0 && t2 == 1)
				{
					s.push(0);
				}
				else
				{
					s.push(1);
				}
			}
			else if (ch == '<')
			{
				t1 = s.top();
				s.pop();
				t2 = s.top();
				s.pop();
				if ((t1 == 1 && t2 == 1) || (t1 == 0 && t2 == 0))
				{
					s.push(1);
				}
				else
				{
					s.push(0);
				}
			}
		}
	}
	int cal = s.top();
	return cal;
}
void putletters(int n)//输出字母
{
	for (int i = 0; i < n; i++)
	{
		cout << letter[i] << "\t";
	}
	cout << "表达式真值";
	cout << endl;
}
void exprience(int n)/*所有情况的遍历*/
{
	int i, j, k, cal, m,t=0,f=0;
	for (i = 0; i < pow(2, n); i++)
	{
		int *data=new int[20];
		int temp = i;
		for (int i=n-1,j = n - 1; j >= 0; j--)
		{
			data[j] = temp & 1;  //两边操作数对应位上全为1时，结果的该位值为1
			M[letter[i]] = data[j];
			if (data[j] > 0)
			{
				cout << "T" << "\t";
			}
			else
				cout << "F" << "\t";
			temp >>= 1;/*二进制向右移动一位并赋值*/
			i--;
		}
		cal = calculate();
		if (cal > 0)
		{
			cout << "T" << endl;
			tnumber++;

		    for (k = 0; k <= n - 1; k++)
			{
				
				truenum[t] = data[k];
				t++;
			}
		}
		else
		{
			cout << "F" << endl;
			fnumber++;
			for (k = 0; k <= n - 1; k++)
			{
				
				falsenum[f] = data[k];
				f++;
			}
		}

		delete[]data;
	}
}
void putdisjunctive(int n,int m)/*输出主析取范式*/
{
	int j; int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			cout<<"∨";
		}
		cout << "(";
		for (j = 0; j < m; j++)
		{
			if (j != 0)
			{
				cout << "∧";
			}
			if (truenum[k]==1)
			{
				cout<<letter[j];
			}
			else
			{
				cout<<"￢"<<letter[j];
			}
			k++;
		}
		cout << ")" ;
	}
	cout << endl;
}
void putconjunctive(int n, int m)/*输出主合取范式*/
{
	int j; int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			cout<<"∨";
		}
		cout << "(";
		for (j = 0; j < m; j++)
		{
			if (j != 0)
			{
				cout << "∧";
			}
			if (falsenum[k] == 1)
			{
				cout<<letter[j];
			}
			else
			{
				cout<<"￢"<<letter[j];
			}
			k++;
		}
		cout << ")";
	}
	cout << endl;
}
int main()
{
	int a = 1;
	while (a)
	{
		printf("请输入表达式其中或运算为 | ,且为&，双条件<=>，非运算为!，单条件为-> \n");
		cin >> before;
		Delete();
		int num = exchange();
		putletters(letter.size());
		exprience(num);
		cout << "主析取范式为" << endl;
		putdisjunctive(tnumber, num);
		cout << "主合取范式为" << endl;
		putconjunctive(fnumber, num);
		before.clear();
		after.clear();
		letter.clear(); tnumber = 0; fnumber = 0;
		memset(truenum, 0, sizeof(truenum));
		memset(falsenum, 0, sizeof(falsenum));
		cout << "输入1继续，输入0退出";
		cin >> a;
	}
	return 0;
}
/*测试用例((!!!p|q)<=>(a&b))->(r|(!b&c))*/