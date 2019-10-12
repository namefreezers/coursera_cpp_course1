#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string res;
	for (int i = 2; n > 0; i *= 2) {
		if (n % i != 0) {
			n -= i / 2;
			res = '1' + res;
		} else {
			res = '0' + res;
		}
	}
	cout << res;

	return 0;
}
