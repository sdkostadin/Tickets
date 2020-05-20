#pragma once
class Date
{
public:
	Date();
	Date(int day, int month, int year);
	Date& operator=(const Date& other);
	~Date();
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

private:

	void copy(const Date& other);
	void clear();
	bool validation(int day, int month, int year);

	int _day;
	int _month;
	int _year;
};

std::ostream& operator<<(std::ostream& out, const Date& obj);
