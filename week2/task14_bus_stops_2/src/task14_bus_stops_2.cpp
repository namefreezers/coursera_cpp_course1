#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<vector<string>, int> buses;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		vector<string> stops(m);
		for (auto &s : stops) {
			cin >> s;
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
