#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	float d;
	cin >> d;
	printf("%4.2f", d);
	for (int i = 1; i < 200; ++i)
	{
		printf("%-4d\n", i);
	}

	//printf("Hello %d world! %f", n, d);
}