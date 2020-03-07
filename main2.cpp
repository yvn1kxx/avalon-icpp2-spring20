#include <iostream>
#include "Extention.hpp"
using namespace ext;
using namespace std;

enum Grade
{
	F = 1,   // неявка
	D = 2,  // неудовлетворительно
	C = 3,  // удовлетворительно
	B = 4,  // хорошо
	A = 5,  // отлично      
};
struct Student
{
	int Id;
	Grade Mark;
	char Name[7];
};




int main()
{
	Grade mark = Grade::B;
	cout << static_cast<int>(mark) << endl;

	Grade userMark;
	int i;
	cin >> i;
	userMark = static_cast<Grade>(i);
	cout << userMark;

	Student student;
	student.Id = GetRandomValue(














}
	/*const int size = 8;
	int data[size] = { 2,3,4,3,2,1,3,4 };
	for (int i = 0; i < size;++i)
	{
		bool hasSwap = false;
		for (int j=0;j<size-1-i;++j)
		{
			if (data[j]> data[j+1])
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				hasSwap = true;
			}
		}
		if (!hasSwap)
		{
			break;
		}
	}


	for (int i = 0; i < size; ++i)
	{
		cout <<data[i]<<endl;
	}*/

	//char data[5] = {'h','e','l','l','\0'};
	//char name[] = "hello";
	//int size = sizeof(data) / sizeof(int);
	//cout << data  << endl;
	//cout << data+1 << endl;
	////print(data);

	/*
	int* ptrData = nullptr;
	int data[DATA_SIZE];

	while (true)
	{
		ptrData = new int[1000];
	}


	for (int i = 0; i < DATA_SIZE; i++)
	{
		cout << "111";
	}*/




