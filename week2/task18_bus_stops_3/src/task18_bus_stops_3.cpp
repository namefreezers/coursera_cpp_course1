#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<set<string>, int> buses;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;

		set<string> stops;
		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			stops.insert(s);
		}

		if (buses.count(stops)) {
			cout << "Already exists for " << buses[stops] << endl;
		} else {
			buses[stops] = buses.size() + 1;
			cout << "New bus " << buses[stops] << endl;
		}

	}
	return 0;
}
