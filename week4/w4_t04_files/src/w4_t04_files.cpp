#include <algorithm>
#include <fstream>
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

	string s;
	while (getline(input_f, s)) {
		cout << s << endl;
	}
	return 0;
}
