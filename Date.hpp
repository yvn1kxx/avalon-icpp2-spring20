#pragma once

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
			Возвращает Юлианскую дату
			https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
			раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
			Тестовые данные					Ожидаемый результат
			1.12.2018					2458454
			1.1.2018					2458120
			1.6.2000					2451697
			21.12.2012					2456283
		*/
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

	TimeDelta countJND(Date date) {
		int a,y,m,jdn;
		a = (14 - static_cast<int>(date.month)) / 12;
		y = static_cast<int>(date.year) + 4800 - a;
		m = static_cast<int>(date.month) + 12 * a - 3;
		jdn = static_cast<int>(date.day) + ((153 * m + 2) / 5) + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
		TimeDelta JDN = { jdn };
		return JDN;
	}

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to)
	{
		/*
		int jdn1, jdn2;
		TimeDelta jdn1 = countJND(from);
		TimeDelta jdn2 = countJND(to);

		return 

		int a, y, m;
		a = (14 - static_cast<int>(from.month)) / 12;
		y = from.year + 4800 - a;
		m = static_cast<int>(from.month) + (12 * a) - 3;
		jdn1 = from.day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
		a = (14 - static_cast<int>(to.month)) / 12;
		y = to.year + 4800 - a;
		m = static_cast<int>(to.month) + (12 * a) - 3;
		jdn2 = to.day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
		TimeDelta distance = { jdn2-jdn1 };*/
		TimeDelta distance = { countJND(to).delta - countJND(from).delta };
		return distance;
	 }

	/*
		Выводит в консоль
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
		std::cout << data.day << " ";
		print(data.month, format);
		std::cout << " " << data.year;
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
	void print(TimeDelta delta) 
	{
		std::cout << delta.delta;
	}

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Month month) {
		Season ans;
		switch (static_cast<int>(month))
		{
		case 1:
		case 2:
		case 12:
			return Season::Winter;
		case 3:
		case 4:
		case 5:
			ans = static_cast<Season>(1);
			break;
		case 6:
		case 7:
		case 8:
			ans = static_cast<Season>(3);
			break;
		case 9:
		case 10:
		case 11:
			ans = static_cast<Season>(4);
			break;

		}
		return ans;
	}

	Season getSeason(Date date) {
		return getSeason(date.month);
	}
	
//
//	/*
//		Написать перегрузку для следующих логических операторов
//	*/
	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day && lhs.month==rhs.month && rhs.year==lhs.year;
}
	bool operator != (const Date lhs, const Date rhs) {
		return !(lhs == rhs);
	}

	bool operator < (const Date lhs, const Date rhs) {
		return lhs.day < rhs.day && lhs.month <rhs.month && rhs.year> lhs.year;
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return lhs.day <= rhs.day && lhs.month <=rhs.month && lhs.year<=rhs.year;
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		return!(lhs < rhs);
	}
	bool operator >= (const Date lhs, const Date rhs) {
		return !(lhs <= rhs);
	}

//	/*
//		Написать перегрузку для следующих арифметических операторов
//	*/

	Date JNDToDate(const TimeDelta delta)
	{
		return ans
	}

	Date operator + (const Date date, const TimeDelta delta) 
	{
		TimeDelta JDN{ countJND(date).delta + delta.delta };
		int a = JDN + 32044, b = (4 * a + 3) / 146097, c = a - (146097 * b) / 4, d = (4 * c + 3) / 1461, e = c - (1461 * d) / 4, m = (5 * c + 2) / 153;
		Date ans;
		ans.day = e - (153 * m + 2) / 5 + 1;
		ans.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		ans.year = 100 * d - 4800 + (m / 10);

		return JNDToDate(JDN);
	}
	Date operator + (const TimeDelta delta, const Date date)
	{
		return { date + delta };
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) 
	{
		return { lhs.delta + rhs.delta };
	}

	TimeDelta operator * (const TimeDelta delta, int multiplier) 
	{
		return { delta.delta * multiplier };
	}
	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		return { delta * multiplier };
	}

	
}