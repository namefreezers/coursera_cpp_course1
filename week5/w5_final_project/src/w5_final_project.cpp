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
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}

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

	auto GetComparable() const {
		return tie(year, month, day);
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

ostream& operator<<(ostream &stream, const Date &d) {
	stream << setfill('0');
	return stream << setw(4) << d.GetYear() << '-' << setw(2) << d.GetMonth()
			<< '-' << setw(2) << d.GetDay();
}

bool operator<(const Date &lhs, const Date &rhs) {
	return lhs.GetComparable() < rhs.GetComparable();
}

class Database {
public:
	void AddEvent(const Date &date, const string &event) {
		db[date].insert(event);
	}

	bool DeleteEvent(const Date &date, const string &event) {
		if (db[date].count(event) == 0) {
			return false;
		}
		db[date].erase(event);
		return true;
	}

	int DeleteDate(const Date &date) {
		int res = db[date].size();
		db.erase(date);
		return res;
	}

	set<string> Find(const Date &date) const {
		if (db.count(date) == 0) {
			return {};
		}
		return db.at(date);
	}

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
		event_present = bool(ss_line >> event);
		if (op == "Add") {
			db.AddEvent(d, event);
		} else if (op == "Del" && event_present) {
			if (db.DeleteEvent(d, event) == true) {
				cout << "Deleted successfully" << endl;
			} else {
				cout << "Event not found" << endl;
			}
		} else if (op == "Del") {
			int amount_deleted = db.DeleteDate(d);
			cout << "Deleted " << amount_deleted << " events" << endl;
		} else if (op == "Find") {
			for (const auto &e : db.Find(d)) {
				cout << e << endl;
			}
		}
	}

	return 0;
}
