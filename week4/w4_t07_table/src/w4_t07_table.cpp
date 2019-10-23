#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input_f("input.txt");
	if (!input_f.is_open()) {
		cout << "error!" << endl;
	}

	const int w = 10;
	int n, m;
	string s;

	input_f >> n >> m;
	input_f.ignore(1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			getline(input_f, s, ',');
			cout << setw(w) << s;
		}
		getline(input_f, s);
		cout << setw(w) << s;
		if (i < n - 1) {
			cout << endl;
		}
	}

	return 0;
}
