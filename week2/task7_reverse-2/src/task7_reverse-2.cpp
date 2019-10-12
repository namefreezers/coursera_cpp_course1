#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> res;
	for (int i = v.size() - 1; i >=0; i--) {
		res.push_back(v[i]);
	}
	return res;
}

//int main() {
//	for (int i : Reversed({1, 5, 3, 4, 2})) {
//		cout << i << endl;
//	}
//	return 0;
//}
