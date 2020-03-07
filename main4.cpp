#include <iostream>
//#include "calculator.hpp"

using namespace std;
//using namespace ext;
//void helloWorld(); /*{
//	cout << "Hello world!" << endl;
//}*/

void print(int* ptr, int size) {
	for (int i = 0 ; i < size; ++i)
	{
		cout << ptr[i] << " ";
	}
	cout << endl;
}
void printData(int(*data)[3], int rowCount, int size)
{
	for (int i = 0 ; i < rowCount; ++i)
	{
		print(data[i], size);
	}
}

int add(int a, int b=10)
{
	return a + b;
}
int add(int a, int b, int c)
{
	return a + b + c;
}

struct Point
{
	int x;
	int y;
};

//bool IsSame(Point a, Point b)
//{
//	return a.x == b.x && a.y == b.y;
//}
bool operator == (Point a, Point b) 
{
	return a.x == b.x && a.y == b.y;
}
bool operator != (Point a, Point b)
{
	return !(a == b);
}

Point operator + (Point a, Point b)
{
	
	return { a.x + b.x, a.y + b.y }; 
}
Point operator *(Point a, int m)
{
	return { a.x * m, a.y *m };
}
Point operator * (int m, Point a)
{
	return a*m;

}


int main()
{//helloWorld();
	//cout << helloWorld<< endl;
	//int data[2][3] = {};
	//print(data[0], 3);    //data + 1
	//cout << add(5, 6)<< endl;
	////cout << ext::minus(6, 5) << endl;
	//cout << add(5)<<endl;
	//cout << add(5,5,6)<<endl;
	/*Point a{ 5,6 };
	Point b{ 8,9 };
	if (a != b)
	{
		cout<<"Not same"<< endl;

	}
	Point c = 2 * a;*/
	
}

//
//void helloWorld() {
//	cout << "Hello world!" << endl;
//}