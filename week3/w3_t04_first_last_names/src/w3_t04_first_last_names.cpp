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

	map<int, string> first_names;
	map<int, string> last_names;
};

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : { 1900, 1965, 1990 }) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : { 1969, 1970 }) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : { 1969, 1970 }) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	return 0;
//}
