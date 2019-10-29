#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		num = 0;
		denom = 1;
	}

	Rational(int numerator, int denominator) {
		change(numerator, denominator);
	}

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return denom;
	}

	void change(int numerator, int denominator) {
		int gcd = GCD_euclid(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		if (denominator == 0) {
			throw invalid_argument("invalid denominator");
		}

		num = numerator;
		denom = denominator;
	}

private:
	int GCD_euclid(int a, int b) {
		a = abs(a);
		b = abs(b);
		while (a > 0 && b > 0) {
			if (a > b) {
				a = a % b;
			} else {
				b = b % a;
			}
		}
		return a + b;
	}

	int num;
	int denom;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
	return lhs.Numerator() == rhs.Numerator()
			&& lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Denominator()
			+ rhs.Numerator() * lhs.Denominator();
	int denom = lhs.Denominator() * rhs.Denominator();
	return Rational(num, denom);
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Denominator()
			- rhs.Numerator() * lhs.Denominator();
	int denom = lhs.Denominator() * rhs.Denominator();
	return Rational(num, denom);
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	int num = lhs.Numerator() * rhs.Numerator();
	int denom = lhs.Denominator() * rhs.Denominator();
	return Rational(num, denom);
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("zero division");
	}
	return Rational(lhs.Numerator() * rhs.Denominator(),
			lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream &stream, const Rational &r) {
	stream << r.Numerator() << '/' << r.Denominator();
	return stream;
}

istream& operator>>(istream &stream, Rational &r) {
	int num, denom;
	if (!(stream >> num)) {
		return stream;
	}
	if (stream.peek() != '/') {
		cout << "error\n";
	}
	stream.ignore(1);
	if (!(stream >> denom)) {
		return stream;
	}
	r.change(num, denom);
	return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	return lhs.Numerator() * rhs.Denominator()
			< rhs.Numerator() * lhs.Denominator();
}

int main() {
	Rational r1, r2;
	string op;
	try {
		cin >> r1 >> op >> r2;
	} catch (const invalid_argument&) {
		cout << "Invalid argument" << endl;
		return 0;
	}
	if (op == "+") {
		cout << r1 + r2 << endl;
	} else if (op == "-") {
		cout << r1 - r2 << endl;
	} else if (op == "*") {
		cout << r1 * r2 << endl;
	} else if (op == "/") {
		try {
			cout << r1 / r2 << endl;
		} catch (const domain_error&) {
			cout << "Division by zero" << endl;
			return 0;
		}
	}

	return 0;
}
