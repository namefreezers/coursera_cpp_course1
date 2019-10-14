#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	int temps[N];
	for (int &i : temps) {
		cin >> i;
	}

	int avg = 0;
	for (int i : temps) {
		avg += i;
	}
	avg /= N;

	vector<int> res;
	for (int idx = 0; idx < N; idx++) {
		if (temps[idx] > avg) {
			res.push_back(idx);
		}
	}

	cout << res.size() << endl;
	for (const int &ind : res) {
		cout << ind << " ";
	}

	return 0;
}
