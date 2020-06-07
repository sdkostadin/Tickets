#ifndef DATE_H
#define DATE_H
#pragma once
class Date
{
public:
	Date();
	Date(int day, int month, int year);
	Date& operator=(const Date& other);

	int getDay() const { return _day; }
	int getMonth() const { return _month; }
	int getYear() const { return _year; }
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator==(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;
	void print() const;
	bool validation();

private:

	void copy(const Date& other);
	
	

	int _day;
	int _month;
	int _year;
};

std::ostream& operator<<(std::ostream& out, const Date& obj);

#endif