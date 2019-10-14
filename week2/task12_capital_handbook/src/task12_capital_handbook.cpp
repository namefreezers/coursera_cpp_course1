#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, string> capitals;

	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;

		string country, new_country, capital;
		if (op == "CHANGE_CAPITAL") {
			cin >> country >> capital;
			if (!capitals.count(country)) {
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			} else if (capitals[country] == capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << capital << endl;
			}
			capitals[country] = capital;
		} else if (op == "RENAME") {
			cin >> country >> new_country;
			if (country == new_country || !capitals.count(country) || capitals.count(new_country)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << country << " with capital " << capitals[country] << " has been renamed to " << new_country << endl;
				capitals[new_country] = capitals[country];
				capitals.erase(country);
			}
		} else if (op == "ABOUT") {
			cin >> country;
			if (capitals.count(country)) {
				cout << "Country " << country << " has capital " << capitals[country] << endl;
			} else {
				cout << "Country " << country << " doesn't exist" << endl;
			}
		} else if (op == "DUMP") {
			if (capitals.size()) {
				for (auto [key, value] : capitals) {
					cout << key << '/' << value << " ";
				}
				cout << endl;
			} else if (capitals.empty()) {
				cout << "There are no countries in the world" << endl;
			}
		}
	}

	return 0;
}
