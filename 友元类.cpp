#include<iostream>
using namespace std;
class Boy;
class Girl
{
    char name[15];
	int age;
public:
    Girl(char N[],int A);
	~Girl()
	{
		cout<<"Girl destructing..\n";
	}
	void print();
	void VisitBoy(Boy &);
	friend void VisitBoyGirl(Boy &, Girl &);
	friend Boy;
};
class Boy
{	
	
	char name[15];
	int age;
     
public:
	Boy(char N[],int A);
	~Boy()
	{
		cout<<"Boy destructing..\n";
	}
	void print();
	void VisitGirl(Girl &);
	friend void VisitBoyGirl(Boy &, Girl &);
	friend Girl;
};
Girl::Girl(char N[],int A)
{
	strcpy(name,N);
	age=A;
	cout<<"Girl constructing..\n";
}
void Girl::print()
{
	cout<<"Girl's name:"<<name<<endl;
	cout<<"Girl's age;"<<age<<endl;
}
void Girl::VisitBoy(Boy &boy)
{
	cout<<"Boy's name:"<<boy.name<<endl;
	cout<<"Boy's age:"<<boy.age <<endl;
}
Boy::Boy(char N[],int A)
{
	strcpy(name,N);
	age=A;
	cout<<"Boy constructing..\n";
}
void Boy::print()
{
	cout<<"Boy's name:"<<name<<endl;
	cout<<"Boy's age;"<<age<<endl;
}
void Boy::VisitGirl(Girl &girl)
{
	cout<<"Girl's name:"<<girl.name<<endl;
	cout<<"Girl's age:"<<girl.age <<endl;
}
void VisitBoyGirl(Boy &boy, Girl &girl)
{
	cout<<"Boy's name:"<<boy.name<<endl;
	cout<<"Boy's age:"<<boy.age <<endl;
	cout<<"Girl's name:"<<girl.name<<endl;
	cout<<"Girl's age:"<<girl.age <<endl;
}



int main()
{
	Girl a("Áõ¹·æÃ",19);
	Boy b("ËïÅ£ÍÜ",19);
	a.VisitBoy(b);
	b.VisitGirl(a);
return 0;
}









