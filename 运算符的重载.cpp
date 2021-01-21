#include<iostream>
using namespace std;
class Complex
{
private:
	float real;
	float imag;
public:
	Complex(float r=0,float i=0);
	void print();
	friend Complex operator + (const Complex &a,const Complex &b);
	friend Complex operator ++ (Complex &a);
	friend Complex operator - (const Complex &a,const Complex &b);
	Complex operator ++ (int);
	Complex operator * (Complex &);
	Complex operator / (Complex &);
};
Complex::Complex(float r,float i)
{
	real=r;
	imag=i;
}
void Complex::print()
{
	cout<<real;
	if(imag!=0)
		if(imag>0)
			cout<<"+";
	        cout<<imag<<"i";
	cout<<endl;
}
Complex operator ++ (Complex&a)
{
	++a.real;
	++a.imag;
	return a;
}
Complex operator + (const Complex &a,const Complex &b)
{
	Complex temp;
	temp.real=a.real+b.real;
	temp.imag=a.imag+b.imag;
	return temp;
}
Complex operator - (const Complex &a,const Complex &b)
{
	Complex temp;
	temp.real=a.real-b.real;
	temp.imag=a.imag-b.imag;
	return temp;
}
Complex Complex::operator ++ (int)
{
	Complex temp(*this);
	real++;
	imag++;
	return temp;
}
Complex Complex::operator * (Complex &a)
{
	Complex temp;
	temp.real=real*a.real;
	temp.imag=imag*a.imag;
	return temp;
}
Complex Complex::operator / (Complex &a)
{
	Complex temp;
	temp.real=real/a.real;
	temp.imag=imag/a.imag;
	return temp;
}
int main()
{
	Complex A1(2.3,4.6),A2(3.6,2.8);
	Complex A3,A4,A5,A6;
	A3=A1+A2;
	A4=A1-A2;
	A5=A1*A2;
	A6=A1/A2;
	cout<<"A1=";A1.print();
	cout<<endl<<"A2=";A2.print();
	cout<<endl<<"A3=A1+A2";A3.print();
	cout<<endl<<"A4=A1-A2";A4.print();
	cout<<endl<<"A5=A1*A2";A5.print();
	cout<<endl<<"A6=A1/A2";A6.print();
	A3=++A1;
	cout<<endl<<"after A3=++A1";
	cout<<"A1=";
	A1.print();
	cout<<"A3=";
	A3.print();
	A4=A2++;
	cout<<endl<<"after A4=A2++";
	cout<<"A2=";
	A2.print();
	cout<<"A4=";
	A4.print();
	return 0;
}



	



