#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string name;
	string last_name;
	int birth_day;
	int birth_month;
	int birth_year;
};

int main() {
	int n;
	cin >> n;

	vector<Student> db(n);

	for (Student &st : db) {
		cin >> st.name >> st.last_name >> st.birth_day >> st.birth_month
				>> st.birth_year;
	}

	int m;
	cin >> m;
	for (int t = 0; t < m; ++t) {
		string op;
		cin >> op;
		if (op == "name") {
			int i;
			cin >> i;
			i--;
			if (i < 0 || i >= n) {
				cout << "bad request" << endl;
			} else {
				cout << db[i].name << ' ' << db[i].last_name << endl;
			}

		} else if (op == "date") {
			int i;
			cin >> i;
			i--;
			if (i < 0 || i >= n) {
				cout << "bad request" << endl;
				continue;
			} else {
				cout << db[i].birth_day << '.' << db[i].birth_month << '.'
						<< db[i].birth_year << endl;
			}

		} else {
			cout << "bad request" << endl;
		}
		string dumb;
		getline(cin, dumb);

	}

	return 0;
}
