/* **************************** Theory ****************************

1. friend function - 
	In C++, a friend function is a function that is defined outside a class but 
	has the right to access the private 
	and protected members of the class in which it is declared as a friend.

	Friend functions are not member functions of the class. They are normal functions 
	that are given special access 
	privileges to the class and its members.

2. what are istream and ostream in the given code -
	istream and ostream are classes in the C++ standard library that define 
	input and output streams, respectively. 
	They are used to perform input and output operations on streams of bytes, 
	such as reading from a file or writing to a file.

3. 
	In the main function, the program creates three complex objects: c1, c2, and c3. 
	It then prompts the user to input values for c1 and c2, and outputs the values of 
	c1 and c2. Next, it performs addition and subtraction of c1 and c2 
	and stores the result in c3. Finally, it outputs the value of c3.
*/

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
