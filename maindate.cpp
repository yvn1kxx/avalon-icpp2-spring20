#include <windows.h>
#include <iostream>
#include "Date.hpp"
using namespace std;
using namespace ext;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TimeDelta delta = { 10 };
	Month month = static_cast<Month>(7);
	Date data = { 2020,Month::January, 1 };
	Date data2 = { 2020,Month::February, 1 };
	print(data); //12.2.1998
	cout << endl;
	print(data, DateFormat::MonthAsString); //12 February 1998
	cout << endl;
	print(data.month, DateFormat::MonthAsString);//2
	cout << endl;
	cout << countJND(data).delta<< endl;
	cout << countDistance(data,data2).delta<< endl;
	cout << static_cast<int>(getSeason(data))<< endl;
	cout << static_cast<int>(getSeason(month)) << endl;
	print(data + delta);


	/*char tip[] = "��� ����������";
	char a[] = " ";

	printf("��� ����������%-10s|%-4s������,%-4s|%-15s��������%-15s|%-2s����������\n", a,a, a, a,a,a);
	printf("%-24s|%-5s����%-6s|", a,a,a);*/

}