#include <iostream>
#include <vector>
#include <string>
using namespace std;

//void print(vector<bool> queue) {
//	for (bool b: queue) {
//		cout << b << " ";
//	}
//	cout << endl;
//}

int main() {
	int N;
	cin >> N;

	vector<bool> queue;

	for (int i = 0; i < N; i++) {
		string s;
		int number;
		cin >> s;
		if (s == "COME") {
			cin >> number;
			queue.resize(queue.size() + number, false);
		} else if (s == "WORRY") {
			cin >> number;
			queue[number] = true;
		} else if (s == "QUIET") {
			cin >> number;
			queue[number] = false;
		} else if (s == "WORRY_COUNT") {
			int res = 0;
			for (const bool &i : queue) {
				res += i;
			}
			cout << res << endl;
		}
	}

	return 0;
}
