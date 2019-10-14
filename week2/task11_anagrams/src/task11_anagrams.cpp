#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> BuildCharCounters(const string& s) {
	map<char, int> res;
	for (const char& c : s) {
		res[c]++;
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << (BuildCharCounters(s1) == BuildCharCounters(s2) ? "YES" : "NO") << endl;
	}
	return 0;
}
