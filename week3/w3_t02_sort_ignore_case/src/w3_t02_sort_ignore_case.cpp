#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void handle(string& s) {
	for (auto& c : s) {
		c = tolower(c);
	}
}

bool sorting(string a, string b) {
	handle(a);
	handle(b);
	return a < b;
}


int main() {
	int n;
	cin >> n;
	vector<string> strs(n);
	for (auto &s : strs) {
		cin >> s;
	}
	sort(begin(strs), end(strs), sorting);
	for (const auto &s : strs) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
