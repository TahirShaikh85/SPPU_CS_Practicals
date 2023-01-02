#include<iostream>
using namespace std;
class complex
{
	public:
		int real ,img;
		friend complex operator+(complex,complex);
		friend complex operator-(complex,complex);
		friend istream&operator>>(istream &in,complex &c1 );
		friend ostream&operator<<(istream &out,complex &c1 );		
};
complex operator +(complex c1,complex c2)
{
	complex c3;
	c3.real=c1.real+c2.real;
	c3.img=c1.img+c2.img;
	return c3;
}
complex operator -(complex c1,complex c2)
{
	complex c3;
	c3.real=c1.real-c2.real;
	c3.img=c1.img-c2.img;
	return c3;
}
istream & operator>>(istream&in,complex&c1)
{
	cout<<"enter the complex no. real & imag: ";
	in>>c1.real>>c1.img;
	return in;
}
ostream & operator<<(ostream&out,complex&c1)
{
	out<<"the complex no.is \n";
	out<<c1.real<<"+"<<c1.img<<"i";
	out<<endl;
	return out;
}
int main()
{
	complex c1,c2,c3;
	cin>>c1;
	cin>>c2;
	cout<<c1;
	cout<<c2;
	c3=c1+c2;
	cout<<"addition is \n";
	cout<<c3;
	cout<<"sub is \n";
	c3=c1-c2;
	cout<<c3;
}
