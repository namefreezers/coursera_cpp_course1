#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
	Person(const string &first, const string &last, int year) {
		birth = year;
		first_names[year] = first;
		last_names[year] = last;
	}

	void ChangeFirstName(int year, const string &first_name) {
		if (year < birth) {
			return;
		}

		first_names[year] = first_name;
	}

	void ChangeLastName(int year, const string &last_name) {
		if (year < birth) {
			return;
		}

		last_names[year] = last_name;
	}

	string GetFullName(int year) const {
		if (year < birth) {
			return "No person";
		}

		string first = get_last(first_names, year);
		string last = get_last(last_names, year);
		if (first == "" && last == "") {
			return "Incognito";
		} else if (first != "" && last != "") {
			return first + " " + last;
		} else if (first != "") {
			return first + " with unknown last name";
		} else if (last != "") {
			return last + " with unknown first name";
		}
	}

	string GetFullNameWithHistory(int year) const {
		if (year < birth) {
			return "No person";
		}

		string first_hist = get_history(first_names, year);
		string last_hist = get_history(last_names, year);
		if (first_hist == "" && last_hist == "") {
			return "Incognito";
		} else if (first_hist != "" && last_hist != "") {
			return first_hist + " " + last_hist;
		} else if (first_hist != "") {
			return first_hist + " with unknown last name";
		} else if (last_hist != "") {
			return last_hist + " with unknown first name";
		}
	}

private:
	string get_last(const map<int, string> &names, const int &searched_year) const {
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
			const int &searched_year) const {
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

	int birth;
	map<int, string> first_names;
	map<int, string> last_names;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : { 1959, 1960 }) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : { 1965, 1967 }) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
