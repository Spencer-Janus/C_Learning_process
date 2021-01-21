// RSA密码算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<cmath>
using namespace std;
int MOD;
int Euclidean(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = Euclidean(b, a % b, x, y);
	int t = x % MOD;
	x = y % MOD;
	y = ((t - a / b * x) % MOD + MOD) % MOD;
	return gcd;
}
int main()
{
	int p, q,n,x,d,e,y;
	cout << "输入素数p：" << endl;
	cin >> p;
	cout << "输入素数q：" << endl;
	cin >> q;
	cout << "乘积n=pq为:" << endl;
	n = p*q;
	cout << n<<endl;
	cout << "φ(n)为：" << endl;
	MOD = (p - 1)*(q - 1);
	cout << MOD<<endl;
	cout << "输入公钥e,要求e与φ(n)互质，且小于φ(n):";
	cin >> e;
	Euclidean(e, MOD, d, y);
	while (d < 0)
		d += MOD;
	cout << "密钥d为：" << d << endl;
	int M, C;
	cout << "输入需要加密的数字" << endl;
	cin >> M;
	C = 1;
	for (int i = 1; i <= e; i++)
		C = C * M % n;
	cout << "M=" << M << "加密后：" << C << endl;
	M = 1;
	for (int i = 1; i <= d; i++)
		M = M * C % n;
	cout << "密文：" << C << "解密后" << M << endl;
	return 0;

}

