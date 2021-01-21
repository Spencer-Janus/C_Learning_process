#include<iostream>
using namespace std;
#define pi 3.14
class Container
{
protected:
 double radius;
public:
 Container(double r)
 {
  radius=r;
 }
 virtual double area()=0;
 virtual double volume()=0;
 virtual void print()=0;
};
class Cube:public Container
{
public:
 Cube(double r):Container(r)
 {}
 double area()
 {
  return 6*radius*radius;
 }
 double volume()
 {
  return radius*radius*radius;
 }
 void print()
 {
  cout<<"������������"<<area()<<endl;
  cout<<"�����������"<<area()<<endl;
 }
};
class Sphere:public Container
{
public:
 Sphere(double r):Container(r)
 {}
 double area()
 {
  return 4*pi*radius*radius;
 }
 double volume()
 {
  return radius*radius*radius*pi*(4.0/3);
 }
 void print()
 {
  cout<<"��������"<<area()<<endl;
  cout<<"�������"<<area()<<endl;
 }
};
class Cylinder:public Container
{
protected:
 double height;
public:
 Cylinder(double r,double h):Container(r)
 {
  height=h;
 }
 double area()
 {
  return(pi*radius*radius*2+2*pi*radius*height);
 }
 double volume()
 {
  return(pi*radius*radius*height);
 }
  void print()
 {
  cout<<"Բ���������"<<area()<<endl;
  cout<<"Բ�������"<<area()<<endl;
 }
};
int main()
{
 Container *p;
 Cube C(5);
 Sphere S(3);
 Cylinder Y(2,3);
 p=&C;
 cout<<p->area()<<endl;
 cout<<p->volume()<<endl;
 p->print();
 p=&S;
 cout<<p->area()<<endl;
 cout<<p->volume()<<endl;
 p->print();
 p=&Y;
 cout<<p->area()<<endl;
 cout<<p->volume()<<endl;
 p->print();
 Container K(4);
 return 0;
}