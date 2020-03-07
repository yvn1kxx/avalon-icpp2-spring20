#include "Date.hpp"
#include <iostream>
using namespace ext;
using namespace std;
struct Point
{
	int x;
	int y;
};

void printPoint(Point point)
{
	cout <<"x = " << point.x << endl;
	cout <<"y = " << point.y << endl;
}

void swap(int& a, int& b) {
	int  temp = a;
	a = b;
	b = temp;
}

int maxValue(int data[], int size) 
{
	int tempMax = data[0];
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (data[i] > tempMax) {
			tempMax = data[i];
			index = i;
		}
	}
	return index;

}
int* maxValuePtr(int data[], int size)
{
	int* ptr = &data[0];
	for (int i = 1; i < size; ++i)
	{
		if (*ptr < data[i])
		{
			ptr = &data[i];
		}
	}
	return ptr;
}
int& maxValueRef(int data[], int size)
{
	int tempMax = data[0];
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (data[i] > tempMax) {
			tempMax = data[i];
			index = i;
		}
	}
	return data[index];
}


//Point& operator ++(Point& p)
//{
//	++p.x;
//	++p.y;
//	return p;
//}


Point& operator ++(Point& p,int)
{
	Point temp = p;
	
	++p.x;
	++p.y;
	return temp;
}
Point operator ++(Point* p)
{
	

	++(p->x);
	++(p->y);
	return *p;
}






int main()
{
	//Date date{ 1998,Month::February, 12 };
	//print(date); //12.2.1998
	//cout << endl;
	//print(date, DateFormat::MonthAsString); //12 February 1998
	//cout << endl;
	//print(date.month, DateFormat::MonthAsString);//2
	//cout << endl;


	/*int a = 10, b=15;
	swap(a, b);


	int data[] = { 5,4,3,2,1,6 };
	int maxIndex = maxValue(data, 6);
	data[maxIndex] *= 2;
	int* maxptr = maxValuePtr(data, 6);
	*maxptr *= 2;
	int& maxRef = maxValueRef(data, 6);
	maxRef = maxRef * 2;*/


	Point p{ 10,15 };
	printPoint(p);
	//++p; //{11,16}
	
	Point p1 = ++p;
	Point p2 = p++;
}