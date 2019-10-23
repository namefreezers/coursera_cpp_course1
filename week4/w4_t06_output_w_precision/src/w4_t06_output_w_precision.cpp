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

	cout << fixed << setprecision(3);
	double d;
	while (input_f >> d) {
		cout << d << endl;
	}

	return 0;
}
