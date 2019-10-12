#include <iostream>
using namespace std;

void simple_algo(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i;
			break;
		}
	}
}

void euclid_algo(int a, int b) {
	while ( a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}
	cout << a + b;

}


int main() {
	int a, b;
	cin >> a >> b;
//	simple_algo(a, b);
	euclid_algo(a, b);
	return 0;
}
