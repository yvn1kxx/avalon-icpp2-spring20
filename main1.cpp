#include <iostream>

using namespace std;
const int DATA_SIZE = 1000;
int main()
{
	int* ptrData= nullptr;
	int data[DATA_SIZE];

	while (true)
	{
		ptrData = new int [1000];
	}


	for (int i = 0; i < DATA_SIZE; i++)
	{
		cout << ptrData[i] << endl;
	}
}