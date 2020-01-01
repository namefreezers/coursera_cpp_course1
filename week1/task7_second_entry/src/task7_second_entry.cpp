#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int status = -2;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == 'f') {
			if (status == -2) {
				status = -1;
			} else if (status == -1) {
				status = i;
				break;
			}
		}
	}
	cout << status;

	return 0;
}
