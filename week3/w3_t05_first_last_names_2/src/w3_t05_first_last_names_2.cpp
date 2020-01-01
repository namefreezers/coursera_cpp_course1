#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string &first_name) {
		first_names[year] = first_name;
	}

	void ChangeLastName(int year, const string &last_name) {
		last_names[year] = last_name;
	}

	string GetFullName(int year) {
		string first = get_last(first_names, year);
		string last = get_last(last_names, year);
		if (first == "" && last == "") {
			return "Incognito";
		} else if (first != "" && last != "") {
			return first + " " + last;
		} else if (first != "") {
			return first + " with unknown last name";
		} else { // if (last != "")
			return last + " with unknown first name";
		}
	}

	string GetFullNameWithHistory(int year) {
		string first_hist = get_history(first_names, year);
		string last_hist = get_history(last_names, year);
		if (first_hist == "" && last_hist == "") {
			return "Incognito";
		} else if (first_hist != "" && last_hist != "") {
			return first_hist + " " + last_hist;
		} else if (first_hist != "") {
			return first_hist + " with unknown last name";
		} else { // if (last_hist != "")
			return last_hist + " with unknown first name";
		}
	}

private:
	string get_last(const map<int, string> &names, const int &searched_year) {
		string name = "";
		for (const auto& [y, n] : names) {
			if (y <= searched_year) {
				name = n;
			} else {
				break;
			}
		}
		return name;
	}

	string get_history(const map<int, string> &names,
			const int &searched_year) {
		vector<string> names_hist;
		for (const auto& [y, n] : names) {
			if (y <= searched_year) {
				if (names_hist.size() == 0
						|| names_hist[names_hist.size() - 1] != n) {
					names_hist.push_back(n);
				}
			} else {
				break;
			}
		}

		if (names_hist.size() == 0) {
			return "";
		}

		string res;
		res += names_hist[names_hist.size() - 1];
		if (names_hist.size() > 1) {
			res += " (";
			for (int i = names_hist.size() - 2; i >= 1; --i) {
				res += names_hist[i] + ", ";
			}
			res += names_hist[0] + ")";
		}
		return res;
	}

	map<int, string> first_names;
	map<int, string> last_names;
};




//int main() {
//  Person person;
//
//  person.ChangeFirstName(1900, "Eugene");
//  person.ChangeLastName(1900, "Sokolov");
//  person.ChangeLastName(1910, "Sokolov");
//  person.ChangeFirstName(1920, "Evgeny");
//  person.ChangeLastName(1930, "Sokolov");
//  cout << person.GetFullNameWithHistory(1940) << endl;
//
//  return 0;
//}





//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : { 1900, 1965, 1990 }) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : { 1969, 1970 }) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : { 1969, 1970 }) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeFirstName(1990, "Polina");
//	person.ChangeLastName(1990, "Volkova-Sergeeva");
//	cout << person.GetFullNameWithHistory(1990) << endl;
//
//	person.ChangeFirstName(1966, "Pauline");
//	cout << person.GetFullNameWithHistory(1966) << endl;
//
//	person.ChangeLastName(1960, "Sergeeva");
//	for (int year : { 1960, 1967 }) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	person.ChangeLastName(1961, "Ivanova");
//	cout << person.GetFullNameWithHistory(1967) << endl;
//
//	return 0;
//}
