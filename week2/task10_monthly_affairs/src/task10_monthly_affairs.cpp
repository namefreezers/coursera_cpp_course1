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

	vector<int> lengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int cur_month = 0;

	vector<vector<string>> affairs(31);

	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;

		int day;
		string work;
		if (op == "ADD") {
			cin >> day >> work;
			affairs[day - 1].push_back(work);
		} else if (op == "NEXT") {
			int next = (cur_month + 1) % 12;
			if (lengths[next] >= lengths[cur_month]) {
				affairs.resize(lengths[next]);
				cur_month = next;
			} else {
				for (int i = lengths[next]; i < lengths[cur_month]; i++) {
					affairs[lengths[next] - 1].insert(
							end(affairs[lengths[next] - 1]),
							begin(affairs[i]), end(affairs[i]));
				}
				affairs.resize(lengths[next]);
				cur_month = next;
			}
		} else if (op == "DUMP") {
			cin >> day;
			cout << affairs[day - 1].size() << " ";
			for (string s : affairs[day - 1]) {
				cout << s << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
