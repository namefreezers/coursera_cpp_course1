#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto &i : A) {
		cin >> i;
	}
	sort(begin(A), end(A), [](int i, int j) {return abs(i) < abs(j);});
	for (const auto &i : A) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
