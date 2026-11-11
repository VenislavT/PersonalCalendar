#include "Date.h"

bool Date::is_leap_year() const {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

Date::Date() {}

Date::Date(int day, string& month, int year) {
	set_month(month);
	set_year(year);
	set_day(day);
}

int Date::get_day() const {
	return day;
}

int Date::get_month() const {
	return int_month;
}

int Date::get_year() const {
	return year;
}

bool Date::set_day(int day) {
	if (this->int_month == 2 && is_leap_year() && day <= 29 && day > 0) {
		this->day = day;
		return true;
	}
	else if (this->int_month == 2 && !is_leap_year() && day <= 28 && day > 0) {
		this->day = day;
		return true;
	}
	else if (((this->int_month <= 7 && this->int_month % 2 == 1) || (this->int_month >= 8 && this->int_month % 2 == 0)) && this->int_month != 2) {
		if (day <= 31 && day > 0) {
			this->day = day;
			return true;
		}
		else {
			return false;
		}
	}
	else if (((this->int_month <= 7 && this->int_month % 2 == 0) || (this->int_month >= 8 && this->int_month % 2 == 1)) && this->int_month != 2) {
		if (day <= 30 && day > 0) {
			this->day = day;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Date::set_month(string& month) {
	for (char& c : month) {
		c = tolower(c);
	}

	this->str_month = month;

	if (month == "jan" || month == "january" || (month == "1" && stoi(month) == 1)) {
		this->int_month = 1;
	}
	else if (month == "feb" || month == "february" || (month == "2" && stoi(month) == 2)) {
		this->int_month = 2;
	}
	else if (month == "mar" || month == "march" || (month == "3" && stoi(month) == 3)) {
		this->int_month = 3;
	}
	else if (month == "apr" || month == "april" || (month == "4" && stoi(month) == 4)) {
		this->int_month = 4;
	}
	else if (month == "may" || (month == "5" && stoi(month) == 5)) {
		this->int_month = 5;
	}
	else if (month == "jun" || month == "june" || (month == "6" && stoi(month) == 6)) {
		this->int_month = 6;
	}
	else if (month == "jul" || month == "july" || (month == "7" && stoi(month) == 7)) {
		this->int_month = 7;
	}
	else if (month == "aug" || month == "august" || (month == "8" && stoi(month) == 8)) {
		this->int_month = 8;
	}
	else if (month == "sep" || month == "september" || (month == "9" && stoi(month) == 9)) {
		this->int_month = 9;
	}
	else if (month == "oct" || month == "october" || (month == "10" && stoi(month) == 10)) {
		this->int_month = 10;
	}
	else if (month == "nov" || month == "november" || (month == "11" && stoi(month) == 11)) {
		this->int_month = 11;
	}
	else if (month == "dec" || month == "december" || (month == "12" && stoi(month) == 12)) {
		this->int_month = 12;
	}
	else {
		return false;
	}
	
	return true;
}

bool Date::set_year(int year) {
	if (year <= 0) {
		return false;
	}
	this->year = year;
	return true;
}

ostream& operator<<(ostream& os, const Date& date) {
	os << date.day << "." << date.int_month << "." << date.year;
	return os;
}

istream& operator>>(istream& is, Date& date) {
	is >> date.day;
	is.ignore(1);

	is >> date.int_month;
	is.ignore(1);

	is >> date.year;
	// is.ignore(1);

	return is;
}

bool Date::input() {
	return input_year() && input_month() && input_day();
}

bool Date::input_year() {
	int new_year;
	while (true) {
		cout << "Enter Year: ";
		cin >> new_year;

		if (cin.fail()) {
			cin.clear();
			string word;
			cin >> word;
			if (word == "/back") {
				cin.ignore(1000, '\n');
				return false;
			}
			cin.ignore(1000, '\n');
			cout << "Year must be a number. Try again." << endl;
		}
		else if (!set_year(new_year)) {
			cout << "Year must be a positive number. Try again." << endl;
		}
		else {
			return true;
		}
	}
}

bool Date::input_month() {
	string new_month;
	while (true) {
		cout << "Enter Month: ";
		cin >> new_month;

		if (new_month == "/back") {
			return false;
		}
		if (set_month(new_month)) {
			return true;
		}
		cout << "Invalid month. Enter a number from 1 to 12 or a name like jan. Try again." << endl;
	}
}

bool Date::input_day() {
	int new_day;
	while (true) {
		cout << "Enter Day: ";
		cin >> new_day;

		if (cin.fail()) {
			cin.clear();
			string word;
			cin >> word;
			if (word == "/back") {
				cin.ignore(1000, '\n');
				return false;
			}
			cin.ignore(1000, '\n');
			cout << "Day must be a number. Try again." << endl;
		}
		else if (!set_day(new_day)) {
			cout << "This month has no such day. Try again." << endl;
		}
		else {
			return true;
		}
	}
}

bool Date::isEqual(const Date& other) const {
	return (year == other.year) && (int_month == other.int_month) && (day == other.day);
}

bool Date::isLater(const Date& other) const {
	if (year > other.year) {
		return true;
	}

	if (year == other.year && int_month > other.int_month) {
		return true;
	}

	if (year == other.year && int_month == other.int_month && day > other.day) {
		return true;
	}
	return false;
}

bool Date::isEarlier(const Date& other) const {
	if (year < other.year) {
		return true;
	}

	if (year == other.year && int_month < other.int_month) {
		return true;
	}

	if (year == other.year && int_month == other.int_month && day < other.day) {
		return true;
	}

	return false;
}

void Date::forward_date(int days) {
	for (int i = 0; i < days; i++) {
		if (!set_day(day + 1)) {
			day = 1;
			int_month++;

			if (int_month > 12) {
				int_month = 1;
				year++;
			}

			str_month = to_string(int_month);
		}
	}
}
