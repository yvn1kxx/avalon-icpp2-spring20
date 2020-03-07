#pragma once
#include <iostream>
namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum class DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum class Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	enum class SortBy
	{
		Date,
		Season
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	struct TimeDelta
	{
		int delta;
	};

	/*----------homework-04----------*/
		/*
			���������� ��������� ����
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			������ "���������� ������ ���������� ��� (JDN) �� ���� �������������� ���������"
			�������� ������					��������� ���������
			1.12.2018					2458454
			1.1.2018					2458120
			1.6.2000					2451697
			21.12.2012					2456283
		*/
	TimeDelta countJND(Date date);

	/*
		������������ ���������� ���� ����� ����� ������.
		��� ����������� ����������� CountJND
	*/
	TimeDelta countDistance(Date from, Date to);

	void printMonthAsString(Month month) {
		switch (month)
		{
		case Month::January:
			std::cout << "January";
			break;
		case Month::February:
			std::cout << "February";
			break;
		}
	}
	/*
		������� � �������
	*/
	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		if (format == DateFormat::MonthAsInt) {
			std::cout << static_cast<int>(month);
		}
		else if (format == DateFormat::MonthAsString) {
			printMonthAsString(month);
		}
		else {
			std::cout << "error";
		}
	}
	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		std::cout << data.day<<" ";
		print(data.month, format);
		std::cout <<" "<< data.year;
		/*if (format == DateFormat::MonthAsInt) {
			std::cout << "."
				<< static_cast<int>(data.month) << "."
				<< data.year;
		}
		else if (format == DateFormat::MonthAsString){
			std::cout << data.day << " ";
			printMonthAsString(data.month);
			std::cout << " "<< data.year;
		}
		else {
			std::cout << "error";
		}*/
	}
	
	void print(TimeDelta delta);

	/*
		���������� ����� (����, �����, ����, �����) ������������ ����
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

	/*
		�������� ���������� ��� ��������� ���������� ����������
	*/
	bool operator == (const Date lhs, const Date rhs);
	bool operator != (const Date lhs, const Date rhs);
	bool operator < (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	/*
		�������� ���������� ��� ��������� �������������� ����������
	*/
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);

	/*----------homework-05----------*/

	TimeDelta operator ++ (TimeDelta& delta);
	TimeDelta operator ++ (TimeDelta& delta, int);

	TimeDelta operator -- (TimeDelta& delta);
	TimeDelta operator -- (TimeDelta& delta, int);

	Date operator ++ (Date& delta);
	Date operator ++ (Date& delta, int);

	Date operator -- (Date& delta);
	Date operator -- (Date& delta, int);

	/*
		������ ���� �������
	*/
	void swap(Date& lhs, Date& rhs);

	/*
		������ ��������� ��������� �������
	*/
	void swap(TimeDelta& lhs, TimeDelta& rhs);

	/*
		���������� ������ �� ������� ����
	*/
	Date& max(Date& lhs, Date& rsh);

	/*
		���������� ��������� �� ������� ����
	*/
	Date& min(Date& lhs, Date& rsh);

	/*
		���������� ��������� �� ����������� ���� � ���������� ������� ���
	*/
	Date& getMinDate(Date dates[], int size);

	/*
		���������� ��������� �� ������������ ���� � ���������� ������� ���
	*/
	Date& getMaxDate(Date dates[], int size);

	/*
		��������� ������ ��� �� ���������� ��������
	*/
	void sort(Date dates[], SortBy sortBy = SortBy::Date);

	/*
		��������� ����� �� ������������ ���� � ������������� ����������.
		� ������ ������ ���������� true, � ��������� ���� �� ����������� ������.
		���� ���� � ����������� ����������� ������������ �� �����,
		���������� ������ ���������.
	*/
	Date* tryFillDate(int year, int month, int day);
}
