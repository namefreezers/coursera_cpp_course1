#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	void SetDate(int new_year, int new_month, int new_day) {
		if (new_month < 1 || new_month > 12) {
			throw invalid_argument(
					"Month value is invalid: " + to_string(new_month));
		}
		if (new_day < 1 || new_day > 31) {
			throw invalid_argument(
					"Day value is invalid: " + to_string(new_day));
		}
		year = new_year;
		month = new_month;
		day = new_day;
	}

private:
	int year;
	int month;
	int day;
};

istream& operator>>(istream &stream, Date &d) {
	string date_str;
	stream >> date_str;

	stringstream ss(date_str);
	int year, month, day;
	if (!(ss >> year)) {
		throw runtime_error("Wrong date format: " + date_str);
	}
	if (ss.peek() != '-') {
		throw runtime_error("Wrong date format: " + date_str);
	}
	ss.ignore(1);
	if (!(ss >> month)) {
		throw runtime_error("Wrong date format: " + date_str);
	}
	if (ss.peek() != '-') {
		throw runtime_error("Wrong date format: " + date_str);
	}
	ss.ignore(1);
	if (!(ss >> day)) {
		throw runtime_error("Wrong date format: " + date_str);
	}
	string temp;
	if (ss >> temp) { // anything left
		throw runtime_error("Wrong date format: " + date_str);
	}

	d.SetDate(year, month, day);
	return stream;
}

bool operator<(const Date &lhs, const Date &rhs);

class Database {
public:
	void AddEvent(const Date &date, const string &event);
	bool DeleteEvent(const Date &date, const string &event);
	int DeleteDate(const Date &date);

	set<string> Find(const Date &date) const;

	void Print() const {
		for (const auto& [date, events] : db) {
			for (const auto &event : events) {
				cout << date << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>> db;
};

int main() {
	Database db;

	string command;
	while (getline(cin, command)) {
		stringstream ss_line(command);

		string op;
		if (!(ss_line >> op)) {
			continue;
		}

		if (op == "Print") {
			db.Print();
		}

		Date d;
		if (op == "Add" or op == "Del" or op == "Find") {
			try {
				ss_line >> d;
			} catch (const invalid_argument &e) {
				cout << e.what() << endl;
				continue;
			} catch (const runtime_error &e) {
				cout << e.what() << endl;
				continue;
			}
		}

		string event;
		bool event_present;
		event_present = (ss_line >> event);
		if (op == "Add") {
			db.AddEvent(d, event);
		} else if (op == "Del" && event_present) {
			db.DeleteEvent(d, event);
		} else if (op == "Del") {
			db.DeleteDate(d);
		} else if (op == "Find") {
			for (const auto &e : db.Find(d)) {
				cout << e << endl;
			}
		}

		return 0;
	}
