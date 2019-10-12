#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(const string& s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(const vector<string>& words, int minLength) {
	vector<string> res;
	for (string s : words) {
		if (s.size() >= minLength && IsPalindrom(s)) {
			res.push_back(s);
		}
	}
	return res;
}

//int main() {
////	for (string s : PalindromFilter({"abacaba", "aba"}, 2)) {
//	for (string s : PalindromFilter({"weew", "bro", "code"}, 2)) {
//		cout << s << endl;
//	}
//	return 0;
//}
