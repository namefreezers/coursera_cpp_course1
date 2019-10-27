#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left == right) {
		return;
	}
	throw runtime_error(left + " != " + right);
}

int main() {
	try {
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	} catch (runtime_error &e) {
		cout << e.what() << endl;
	}
	return 0;
}
