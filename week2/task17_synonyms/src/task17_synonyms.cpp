#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, set<string>> synonyms;

	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;

		if (op == "ADD") {
			string s1, s2;
			cin >> s1 >> s2;
			synonyms[s1].insert(s2);
			synonyms[s2].insert(s1);

		} else if (op == "CHECK") {
			string s1, s2;
			cin >> s1 >> s2;
			cout << (synonyms[s1].count(s2) ? "YES" : "NO") << endl;

		} else if (op == "COUNT") {
			string s1;
			cin >> s1;
			cout << synonyms[s1].size() << endl;

		}
	}
	return 0;
}
