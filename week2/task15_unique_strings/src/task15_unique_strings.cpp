#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> strs;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		strs.insert(s);
	}
	cout << strs.size();
	return 0;
}
