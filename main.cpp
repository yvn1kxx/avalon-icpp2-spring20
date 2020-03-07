#include <iostream>
using namespace std;
const int x = 3;
const int y = 4;
struct row
{
	const static int SIZE = y;
	int data[SIZE];

};
void print(row data[], int x)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < row::SIZE; ++j)
		{
			cout << data[i].data[j] << " ";
		}
		cout << endl;
	}

}

row inputrow(
	row row;
for (int i = 0; i < 5; ++i)
{
	cin >> row.data[i];
}
return *row;
);




int* input()
{
	int *data[5];
	for (int i = 0; i < 5; ++i)
	{
		cin >> data[i];
	}
	return *data;
}




int main()
{
	int* ptr = input();

	for (int i = 0; i < 5; ++i)
	{
		cout << ptr[i] << endl;
	}












//	int data2[x][y] = { {2,4,5}, {8,7,4},{} };
//	int* ptr = &data2[0][0];
//
//	row data[3] = { {2,4,5}, {8,7,4},{} };
//	print(data, x);
//
//	cout << row::SIZE << endl;
//
//	/*cout << data2 << endl;
//	cout << **data2 << endl;
//
//	cout << data2 + 1 << endl;
//	cout << **data2 + 1 << endl;*/
}